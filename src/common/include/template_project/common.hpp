#pragma once

#include <memory>

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

namespace basic_namespace
{

[[noreturn]] inline void unreachable()
{
#if defined(_MSC_VER) && !defined(__clang__) // MSVC
	__assume(false);
#else // GCC, Clang
	__builtin_unreachable();
#endif
}

template <typename T, typename A = std::allocator<T>>
class default_init_allocator : public A
{
	typedef std::allocator_traits<A> a_t;

public:
	template <typename U>
	struct rebind
	{
		using other =
			default_init_allocator<
				U, typename a_t::template rebind_alloc<U>>;
	};

	using A::A;

	template <typename U>
	void construct(U* ptr) noexcept(std::is_nothrow_default_constructible<U>::value)
	{
		::new (static_cast<void*>(ptr)) U;
	}
	template <typename U, typename... Args>
	void construct(U* ptr, Args&&... args)
	{
		a_t::construct(static_cast<A&>(*this),
			ptr, std::forward<Args>(args)...);
	}
};

} // namespace basic_namespace
