/*
 signatures.hpp
 This file autogenerated. Do not modify, as all modifications will be overwritten.
*/

#ifndef __JINI_SIGNATURES_HPP__
#define __JINI_SIGNATURES_HPP__

namespace jni {


	class SigHelper
	{
		char* sig;
	public:
		SigHelper(char* s): sig(s) {}
		~SigHelper() { free(sig); }
		operator const char*() const { return sig; }
	};

	struct Signatures
	{
		static char* buildSig(const char* ret, const char** args, int len) {
			if (!ret || !*ret) return NULL;
			int buffsize = strlen(ret) + 3;
			for (int i = 0; i < len; ++i) {
				if (!args[i] || !*args[i]) return NULL;
				buffsize += strlen(args[i]);
			}
			char* buffer = (char*)malloc(buffsize);
			if (!buffer) return NULL;
			int ptr = 0;
			buffer[ptr++] = '(';
			for (int i = 0; i < len; ++i)
			{
				strcpy(buffer + ptr, args[i]);
				ptr += strlen(args[i]);
			}
			buffer[ptr++] = ')';
			strcpy(buffer + ptr, ret);
			return buffer;
		}
		template <int len>
		static char* buildSig(const char* ret, const char* (&args)[len]) { return buildSig(ret, args, len); }

		template <typename ret>
		static char* buildSig() {
			return buildSig(TypeInfo<ret>::sig(), NULL, 0);
		}

		template <typename ret, typename T1>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig(),
                TypeInfo<T5>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig(),
                TypeInfo<T5>::sig(),
                TypeInfo<T6>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig(),
                TypeInfo<T5>::sig(),
                TypeInfo<T6>::sig(),
                TypeInfo<T7>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig(),
                TypeInfo<T5>::sig(),
                TypeInfo<T6>::sig(),
                TypeInfo<T7>::sig(),
                TypeInfo<T8>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig(),
                TypeInfo<T5>::sig(),
                TypeInfo<T6>::sig(),
                TypeInfo<T7>::sig(),
                TypeInfo<T8>::sig(),
                TypeInfo<T9>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

		template <typename ret, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
		static char* buildSig() {
			const char* args[] = {
                TypeInfo<T1>::sig(),
                TypeInfo<T2>::sig(),
                TypeInfo<T3>::sig(),
                TypeInfo<T4>::sig(),
                TypeInfo<T5>::sig(),
                TypeInfo<T6>::sig(),
                TypeInfo<T7>::sig(),
                TypeInfo<T8>::sig(),
                TypeInfo<T9>::sig(),
                TypeInfo<T10>::sig()
			};
			return buildSig(TypeInfo<ret>::sig(), args);
		}

	};

} //jni

#endif //__JINI_SIGNATURES_HPP__
