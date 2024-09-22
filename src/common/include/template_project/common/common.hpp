#pragma once

// clang-format off
#ifndef BASIC_UNROLL_LOOP
#	if defined(_MSC_VER) && !defined(__clang__)
#		define BASIC_UNROLL_LOOP(N) __pragma(loop(unroll, N))
#	else
#		define BASIC_STRINGIFY(X)	 #X
#		define BASIC_TOSTRING(X)	 BASIC_STRINGIFY(X)
#		define BASIC_UNROLL_LOOP(N) _Pragma(BASIC_TOSTRING(GCC unroll N))
#	endif
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

#ifndef BASIC_EXPORT
#	if  defined(BASIC_LIBRARY_STATIC)
#		define BASIC_EXPORT
#	elif defined(BASIC_LIBRARY_SHARED)
#		if defined(_WIN32)
#			define BASIC_EXPORT __declspec(dllexport)
#		else
#			define BASIC_EXPORT __attribute__((visibility("default")))
#		endif
#	else // import
#		if defined(_WIN32)
#			define BASIC_EXPORT __declspec(dllimport)
#		else
#			define BASIC_EXPORT
#		endif
#	endif
#endif
// clang-format on

BASIC_BEGIN_NAMESPACE

[[noreturn]] inline void unreachable()
{
	// Uses compiler specific extensions if possible.
	// Even if no extension is used, undefined behavior is still raised by
	// an empty function body and the noreturn attribute.
#if defined(_MSC_VER) && !defined(__clang__) // MSVC
	__assume(false);
#else // GCC, Clang
	__builtin_unreachable();
#endif
}

BASIC_END_NAMESPACE
