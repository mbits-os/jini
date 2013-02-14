#ifndef __JINI_METHOD_BASE_HPP__
#define __JINI_METHOD_BASE_HPP__

#include <stdlib.h>
#include "signatures.hpp"

namespace jni {

	template <typename Final>
	class MethodBase: public Signatures
	{
	protected:
		jmethodID m_method;
		const char* m_name;

		bool init(JNIEnv* env, jclass klass, const char* sig, bool _throw, bool isStatic = false)
		{
			if (isStatic)
				m_method = env->GetStaticMethodID(klass, m_name, sig);
			else
				m_method = env->GetMethodID(klass, m_name, sig);
			return Exception::check(env, _throw);
		}
		bool ensure(JNIEnv* env, jclass clazz, bool _throw)
		{
			Final* _this = static_cast<Final*>(this);
			if (!m_method)
				return _this->onInit(env, clazz, _throw);
			return true;
		}
	public:
		MethodBase(const char* name): m_method(0), m_name(name) {}
	};

	class NullT {};
	
} //jni

#endif //__JINI_METHOD_BASE_HPP__
