#ifndef __JNI_HPP__
#define __JNI_HPP__

#include "jini/jini_base.hpp"
#include "jini/method_base.hpp"
#include "jini/methods.hpp"
#include "jini/static_methods.hpp"
#include "jini/constructors.hpp"

template <typename T> struct JavaArrayInfo;

#define JAVAARRAYINFO(type, Type) \
		template <> struct JavaArrayInfo<type>\
		{\
			typedef _##type##Array* array_t;\
			static type* acquire(JNIEnv* env, array_t array)\
			{\
				return env->Get##Type##ArrayElements(array, NULL);\
			}\
			static void release(JNIEnv* env, array_t array, type* ptr)\
			{\
				if (ptr != NULL)\
					env->Release##Type##ArrayElements(array, ptr, 0);\
			}\
		};

//JAVAARRAYINFO(jobject,Object); - different API
JAVAARRAYINFO(jboolean,Boolean);
JAVAARRAYINFO(jbyte,Byte);
JAVAARRAYINFO(jchar,Char);
JAVAARRAYINFO(jshort,Short);
JAVAARRAYINFO(jint,Int);
JAVAARRAYINFO(jlong,Long);
JAVAARRAYINFO(jfloat,Float);
JAVAARRAYINFO(jdouble,Double);
	
template <typename T>
class JavaArray
{
public:
	typedef typename JavaArrayInfo<T>::array_t array_t;
	
    JavaArray(JNIEnv* env, array_t array)
	: m_env(env)
	, m_array(array)
	, m_ptr(NULL)
	, m_len(0)
	{
    	if (!array) return;
    	m_len = env->GetArrayLength(array);
    	m_ptr = JavaArrayInfo<T>::acquire(env, array);
	}
    ~JavaArray()
    {
    	JavaArrayInfo<T>::release(m_env, m_array, m_ptr);
    	m_ptr = NULL;
    }

    T*  ptr() const { return m_ptr; }
    int length() const { return m_len; }
    
    operator array_t() { return m_array; }

private:
    JNIEnv* m_env;
    array_t m_array;
    T*      m_ptr;
    int     m_len;
};

#define NPE_CHECK(object)    \
    do { if (NULL == (object)) { throw java::lang::NullPointerException(); } } while (0)

#endif //__JNI_HPP__
