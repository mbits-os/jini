#ifndef __JINI_BASE_HPP__
#define __JINI_BASE_HPP__

#include <jni.h>
#include <stdio.h>
#include <string.h>

#define NULL 0
#define nullptr NULL

namespace jni {

	class _Env
	{
		JavaVM* m_vm;
		_Env(): m_vm(NULL) {}
		_Env(const _Env& oth): m_vm(oth.m_vm) {}
		_Env& operator=(const _Env&) { return *this; }
		static _Env& get()
		{
			static _Env env;
			return env;
		}
	public:
		static void setVM(JavaVM* vm) { get().m_vm = vm; }
		static JNIEnv* getCurrent()
		{
		    JNIEnv* env = NULL;

		    if (get().m_vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		        return NULL;
		    }
		    return env;
		}
	};
	
	inline JNIEnv* Env() { return _Env::getCurrent(); }

	// This class is for two purposes only:
	// 1. To be thrown at any point, when ExceptionCheck returns non-null
	// 2. To be the base for the Throwable, and therfore catch all throwables
	//    at the JNI border.
	struct Exception
	{
		static void clear(JNIEnv* env) { env->ExceptionClear(); }
		static void clear() { clear(Env()); }
		static bool check(JNIEnv* env, bool _throw = true)
		{
			if (env->ExceptionCheck())
			{
				if (_throw) throw Exception();
				return false;
			}
			return true;
		}
		static bool check(bool _throw = true) { return check(Env(), _throw); }
	};

	// Apart from being actually thrown towards JNI border,
	// this class'es child types also setup actual excpetions
	// in the environment.
	struct Throwable: Exception
	{
	protected:
		Throwable() {};
		Throwable(const char* clazz, const char* msg)
		{
			onThrow(clazz, msg);
		}
		void onThrow(const char* clazz, const char* msg);
	};

#define DECL_EXC(Name, Class) \
	struct Name: jni::Throwable\
	{\
		Name(const char* msg = NULL): jni::Throwable(Class, msg){}\
	}

	template<typename T>
	class scoped_local_ref {
	public:
	    scoped_local_ref(JNIEnv* env, T localRef = NULL)
	    : mEnv(env), mLocalRef(localRef)
	    {
	    }

	    ~scoped_local_ref() {
	        reset();
	    }

	    void reset(T localRef = NULL) {
	        if (mLocalRef != NULL) {
	            mEnv->DeleteLocalRef(mLocalRef);
	        }
            mLocalRef = localRef;
	    }

	    T get() const {
	        return mLocalRef;
	    }

	private:
	    JNIEnv* mEnv;
	    T mLocalRef;

	    // Disallow copy and assignment.
	    scoped_local_ref(const scoped_local_ref&);
	    void operator=(const scoped_local_ref&);
	};

	template <typename T> class TypeInfo;
#define TYPEINFO(TYPE, SIG, NAME) \
	template <> class TypeInfo<TYPE> \
	{ \
	public: \
		static const char* sig() { return SIG; } \
		static TYPE get(JNIEnv* env, jobject _this, jfieldID field) { return env->Get##NAME##Field(_this, field); } \
		static TYPE getStatic(JNIEnv* env, jclass klass, jfieldID field) { return env->GetStatic##NAME##Field(klass, field); } \
		typedef TYPE (*call_t)(JNIEnv*, jobject, jmethodID, ...); \
		typedef TYPE (*static_call_t)(JNIEnv*, jclass, jmethodID, ...); \
		static call_t get_function(JNIEnv* env) { return env->functions->Call##NAME##Method; } \
		static static_call_t get_static_function(JNIEnv* env) { return env->functions->CallStatic##NAME##Method; } \
	}
	
	TYPEINFO(jboolean, "Z", Boolean);
	TYPEINFO(jbyte, "B", Byte);
	TYPEINFO(jchar, "C", Char);
	TYPEINFO(jshort, "S", Short);
	TYPEINFO(jint, "I", Int);
	TYPEINFO(jlong, "J", Long);
	TYPEINFO(jfloat, "F", Float);
	TYPEINFO(jdouble, "D", Double);

	template <> class TypeInfo<void>
	{
	public:
		static const char* sig() { return "V"; }
		static void get(JNIEnv*, jobject, jfieldID) {}
		static void getStatic(JNIEnv* env, jclass klass, jfieldID field) { }
		typedef void (*call_t)(JNIEnv*, jobject, jmethodID, ...);
		typedef void (*static_call_t)(JNIEnv*, jclass, jmethodID, ...);
		static call_t get_function(JNIEnv* env) { return env->functions->CallVoidMethod; } 
		static static_call_t get_static_function(JNIEnv* env) { return env->functions->CallStaticVoidMethod; } 
	};

	template <> class TypeInfo<jbyteArray>
	{
	public:
		static const char* sig() { return "[B"; }
	};

	template <> class TypeInfo<jstring>
	{
	public:
		static const char* sig() { return "Ljava/lang/String;"; }
	};

	template <> class TypeInfo<jintArray>
	{
	public:
		static const char* sig() { return "[I"; }
	};

	template <typename Final>
	class Class
	{
	public:
		Class(): m_class(0) {}

	protected:
		jclass m_class;

		void init()
		{
			JNIEnv* env = Env();
			m_class = env->FindClass(Final::classPathName());
			Exception::check(env);
			m_class = (jclass)env->NewGlobalRef(m_class);
			Exception::check(env);
		};

		template <int len>
		int registerNatives(const JNINativeMethod (&gMethods)[len])
		{
			return _Env::getCurrent()->RegisterNatives(m_class, gMethods, len);
		}

	public:
		bool instanceOf(jobject obj) { return _Env::getCurrent()->IsInstanceOf(obj, m_class); }
	};
#define DECLARE_JAVA_CLASS(Class) \
		static const char* classPathName() { return Class; } \
		static const char* argClassPathName() { return "L" Class ";"; }

	template <typename Final>
	class Object
	{
	protected:
		jobject m_this;

		Object(jobject _this): m_this(_this) {}
	public:
		static int init() { return Final::getClass().inited(); }
		bool inited() { return Final::getClass().inited() == 0; }
		bool instanceOf() { return Final::getClass().instanceOf(m_this); }
		operator jobject () { return m_this; }
		jobject _this() const { return m_this; }
	};

#define JAVA_CLASS() \
	public: class Class; \
	protected: static Class& getClass() \
	{ \
		static Class clazz; \
		static bool inited = false; \
		if (!inited) \
		{ \
			inited = true; \
			clazz.init(); \
		} \
		return clazz; \
	} \
	public: \
	class Class: public jni::Class<Class>

#define DECLARE_GETCLASS() \
	public: class Class; \
	protected: inline static Class& getClass(); \
	public: \

#define DEFINE_GETCLASS(type) \
	type::Class& type::getClass() \
	{ \
		static Class clazz; \
		static bool inited = false; \
		if (!inited) \
		{ \
			inited = true; \
			clazz.init(); \
		} \
		return clazz; \
	}

	template <typename Final> struct TypeInfo_Object
	{
		typedef typename Final object_t;
		typedef typename Final::Class class_t;

		static const char* sig() { return class_t::argClassPathName(); }

		static object_t get(JNIEnv* env, jobject _this, jfieldID field)
		{
			jobject _ret = env->GetObjectField(_this, field);
			Exception::check(env);
			return object_t(_ret);
		}

		static object_t getStatic(JNIEnv* env, jclass klass, jfieldID field)
		{
			jobject _ret = env->GetStaticObjectField(klass, field);
			Exception::check(env);
			return object_t(_ret);
		}

		typedef object_t (*call_t)(JNIEnv*, jobject, jmethodID, ...);
		static object_t call(JNIEnv* env, jobject _this, jmethodID meth, ...)
		{
			va_list vl;
			va_start(vl, meth);
			jobject o = env->CallObjectMethodV(_this, meth, vl);
			va_end(vl);
			Exception::check(env);
			return object_t(o);
		}
		static call_t get_function(JNIEnv* env) { return call; }

		typedef object_t (*static_t)(JNIEnv*, jclass, jmethodID, ...);
		static object_t static_call(JNIEnv* env, jclass klass, jmethodID meth, ...)
		{
			va_list vl;
			va_start(vl, meth);
			jobject o = env->CallStaticObjectMethodV(klass, meth, vl);
			va_end(vl);
			Exception::check(env);
			return object_t(o);
		}
		static static_t get_static_function(JNIEnv* env) { return static_call; }
	};

	template <typename T>
	class Field
	{
		jfieldID m_field;
		const char* m_name;
	public:
		Field(const char* name): m_field(0), m_name(name) {}

		T operator()(jclass clazz, jobject _this)
		{
			JNIEnv* env = Env();
			if (!m_field)
			{
				m_field = env->GetFieldID(clazz, m_name, TypeInfo<T>::sig());
				Exception::check(env);
			}
			T _ret = TypeInfo<T>::get(Env(), _this, m_field);
			Exception::check(env);
			return _ret;
		}
	};

	template <>
	class Field<jobject>
	{
		jfieldID m_field;
		const char* m_name;
		const char* m_sig;
	public:
		Field(const char* name, const char* sig): m_field(0), m_name(name), m_sig(sig) {}

		jobject operator()(jclass clazz, jobject _this)
		{
			JNIEnv* env = Env();
			if (!m_field)
			{
				m_field = env->GetFieldID(clazz, m_name, m_sig);
				Exception::check(env);
			}
			jobject _ret = env->GetObjectField(_this, m_field);
			Exception::check(env);
			return _ret;
		}
	};

	template <typename T>
	class StaticField
	{
		jfieldID m_field;
		const char* m_name;
	public:
		StaticField(const char* name): m_field(0), m_name(name) {}

		T operator()(jclass clazz)
		{
			JNIEnv* env = Env();
			if (!m_field)
			{
				m_field = env->GetStaticFieldID(clazz, m_name, TypeInfo<T>::sig());
				Exception::check(env);
			}
			T _ret = TypeInfo<T>::getStatic(env, clazz, m_field);
			Exception::check(env);
			return _ret;
		}
	};

	template <>
	class StaticField<jobject>
	{
		jfieldID m_field;
		const char* m_name;
		const char* m_sig;
	public:
		StaticField(const char* name, const char* sig): m_field(0), m_name(name), m_sig(sig) {}

		jobject operator()(jclass clazz)
		{
			JNIEnv* env = Env();
			if (!m_field)
			{
				m_field = env->GetStaticFieldID(clazz, m_name, m_sig);
				Exception::check(env);
			}
			jobject _ret = env->GetStaticObjectField(clazz, m_field);
			Exception::check(env);
			return _ret;
		}
	};

	template <typename T>
	T JNIconv(T arg) { return arg; }
	template <class T>
	jobject JNIconv(Object<T> obj) { return (jobject)obj; }
} //jni

#define DECL_BUILTIN_EXC(Name) DECL_EXC(Name, "java/lang/" #Name) 
namespace java {
	namespace lang {
		DECL_BUILTIN_EXC(NullPointerException);
		DECL_BUILTIN_EXC(ArrayIndexOutOfBoundsException);
		DECL_BUILTIN_EXC(RuntimeException);
		DECL_BUILTIN_EXC(IllegalArgumentException);
		DECL_BUILTIN_EXC(IllegalStateException);
		DECL_BUILTIN_EXC(OutOfMemoryError);
	} // java::lang

	namespace io {
		struct IOException: jni::Throwable
		{
			IOException(const char* msg = NULL)
					: jni::Throwable("java/io/IOException", msg)
			{}
			IOException(int errnum);
		};
	} // java::io
} // java

#endif //__JINI_BASE_HPP__
