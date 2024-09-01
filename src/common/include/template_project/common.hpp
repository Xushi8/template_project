#pragma once

#ifndef BASIC_UNROLL_LOOP
#if defined(__GNUC__) || defined(__clang__)
// GCC or Clang
#define BASIC_STRINGIFY(X) #X
#define BASIC_TOSTRING(X) BASIC_STRINGIFY(X)
#define BASIC_UNROLL_LOOP(N) _Pragma(BASIC_TOSTRING(GCC unroll N))
// #undef TOSTRING
// #undef STRINGIFY
#elif defined(_MSC_VER)
// MSVC
#define BASIC_UNROLL_LOOP(N) __pragma(loop(unroll, N))
#else
// Other compilers
#define BASIC_UNROLL_LOOP(N)
#endif
#endif

#ifndef BASIC_BEGIN_NAMESPACE
#define BASIC_BEGIN_NAMESPACE \
	namespace basic_namespace \
	{                         \
	inline namespace v0       \
	{
#define BASIC_END_NAMESPACE   \
	}                         \
	}
#endif

BASIC_BEGIN_NAMESPACE



BASIC_END_NAMESPACE
