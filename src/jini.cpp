/*
 * jini.cpp
 *
 *  Created on: 12-02-2013
 *      Author: Marcin
 */

#include "jini.hpp"
#include <string.h>
#include <stdio.h>

namespace java { namespace lang {

	class _Throwable: public jni::Object<_Throwable>
	{
	public:
		JAVA_CLASS()
		{
		public:
			void init() {}
			DECLARE_JAVA_CLASS("java/lang/Throwable")
		};
		_Throwable(jobject _this): jni::Object<_Throwable>(_this) {}
	};
}} //java::lang

namespace jni
{
	template <> class TypeInfo<java::lang::_Throwable>
	{
	public:
		static const char* sig() { return "Ljava/lang/_Throwable;"; }
	};

	void Throwable::onThrow(const char* clazz, const char* msg)
	{
		JNIEnv* env = Env();

		scoped_local_ref<jthrowable> cause(env);
		if (env->ExceptionCheck())
		{
			cause.reset(env->ExceptionOccurred());
		}

		scoped_local_ref<jclass> klazz(env, env->FindClass(clazz));
		if (!klazz.get()) return;

		if (cause.get())
		{
			scoped_local_ref<jthrowable> _exception(env);
			if (msg && *msg)
			{
				scoped_local_ref<jstring> _msg(env, env->NewStringUTF(msg));
				Constructor<jstring, java::lang::_Throwable> ctor;
				if (!ctor.init_(env, klazz.get())) return;
				_exception.reset((jthrowable)ctor(klazz.get(), _msg.get(), cause.get()));
			}
			else
			{
				Constructor<java::lang::_Throwable> ctor;
				if (!ctor.init_(env, klazz.get())) return;
				_exception.reset((jthrowable)ctor(klazz.get(), cause.get()));
			}
			env->Throw(_exception.get());
			return;
		}

	    env->ThrowNew(klazz.get(), msg);
	}
} //jni

#ifdef WIN32
#define strerror_r(...) ((char*)1)
#define snprintf sprintf_s
#endif

static const char* jniStrError(int errnum, char* buf, size_t buflen) {
    // Note: glibc has a nonstandard strerror_r that returns char* rather than POSIX's int.
    // char *strerror_r(int errnum, char *buf, size_t n);
    char* ret = (char*) strerror_r(errnum, buf, buflen);
    if (((int)ret) == 0) {
        // POSIX strerror_r, success
        return buf;
    } else if (((int)ret) == -1) {
        // POSIX strerror_r, failure
        // (Strictly, POSIX only guarantees a value other than 0. The safest
        // way to implement this function is to use C++ and overload on the
        // type of strerror_r to accurately distinguish GNU from POSIX. But
        // realistic implementations will always return -1.)
        snprintf(buf, buflen, "errno %d", errnum);
        return buf;
    } else {
        // glibc strerror_r returning a string
        return ret;
    }
}

namespace java { namespace io {
	IOException::IOException(int errnum)
	{
	    char buffer[80];
	    const char* message = jniStrError(errnum, buffer, sizeof(buffer));
	    onThrow("java/io/IOException", message);
	}
}} //java::io


