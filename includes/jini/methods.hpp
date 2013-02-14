/*
 methods.hpp
 This file autogenerated. Do not modify, as all modifications will be overwritten.
*/

#ifndef __JINI_METHODS_HPP__
#define __JINI_METHODS_HPP__

namespace jni {

	template <typename ret, typename T1 = NullT, typename T2 = NullT, typename T3 = NullT, typename T4 = NullT, typename T5 = NullT, typename T6 = NullT, typename T7 = NullT, typename T8 = NullT, typename T9 = NullT, typename T10 = NullT, typename OneMore = NullT> class Method;

	template <typename ret>
	class Method<ret>: public MethodBase< Method<ret> >
	{
	public:
		typedef MethodBase< Method<ret> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz)
		{
			return call(Env(), clazz, thiz, true);
		}
		ret no_throw(jclass clazz, jobject thiz)
		{
			return call(Env(), clazz, thiz, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method);
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1>
	class Method<ret, T1>: public MethodBase< Method<ret, T1> >
	{
	public:
		typedef MethodBase< Method<ret, T1> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1)
		{
			return call(Env(), clazz, thiz, arg1, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1)
		{
			return call(Env(), clazz, thiz, arg1, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2>
	class Method<ret, T1, T2>: public MethodBase< Method<ret, T1, T2> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2)
		{
			return call(Env(), clazz, thiz, arg1, arg2, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2)
		{
			return call(Env(), clazz, thiz, arg1, arg2, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3>
	class Method<ret, T1, T2, T3>: public MethodBase< Method<ret, T1, T2, T3> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4>
	class Method<ret, T1, T2, T3, T4>: public MethodBase< Method<ret, T1, T2, T3, T4> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5>
	class Method<ret, T1, T2, T3, T4, T5>: public MethodBase< Method<ret, T1, T2, T3, T4, T5> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4, T5> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4, T5>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4), JNIconv(arg5));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	class Method<ret, T1, T2, T3, T4, T5, T6>: public MethodBase< Method<ret, T1, T2, T3, T4, T5, T6> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4, T5, T6> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4, T5, T6>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4), JNIconv(arg5), JNIconv(arg6));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	class Method<ret, T1, T2, T3, T4, T5, T6, T7>: public MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4, T5, T6, T7>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4), JNIconv(arg5), JNIconv(arg6), JNIconv(arg7));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	class Method<ret, T1, T2, T3, T4, T5, T6, T7, T8>: public MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7, T8> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7, T8> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4, T5, T6, T7, T8>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4), JNIconv(arg5), JNIconv(arg6), JNIconv(arg7), JNIconv(arg8));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	class Method<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9>: public MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4), JNIconv(arg5), JNIconv(arg6), JNIconv(arg7), JNIconv(arg8), JNIconv(arg9));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};

	template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	class Method<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>: public MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> >
	{
	public:
		typedef MethodBase< Method<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> > base_t;
		Method(const char* name): base_t(name) {}
		bool onInit(JNIEnv* env, jclass clazz, bool _throw)
		{
			SigHelper sig(Signatures::buildSig<ret, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>());
			if (!sig) return false;
			return base_t::init(env, clazz, sig, _throw);
		}
		ret operator()(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, true);
		}
		ret no_throw(jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10)
		{
			return call(Env(), clazz, thiz, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, false);
		}
		bool init_(jclass clazz)
		{
			return base_t::ensure(Env(), clazz, false);
		}
		bool init_(JNIEnv* env, jclass clazz)
		{
			return base_t::ensure(env, clazz, false);
		}
	private:
		ret call(JNIEnv* env, jclass clazz, jobject thiz, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, bool _throw)
		{
			if (!base_t::ensure(env, clazz, _throw))
				return ret();
			ret _ret = TypeInfo<ret>::get_function(env)(env, thiz, base_t::m_method, JNIconv(arg1), JNIconv(arg2), JNIconv(arg3), JNIconv(arg4), JNIconv(arg5), JNIconv(arg6), JNIconv(arg7), JNIconv(arg8), JNIconv(arg9), JNIconv(arg10));
			if (_throw)
				Exception::check(env);
			return _ret;
		}
	};


} //jni

#endif //__JINI_METHODS_HPP__