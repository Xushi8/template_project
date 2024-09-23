#pragma once

#include <template_project/common/common.hpp>
#include <atomic>

BASIC_BEGIN_NAMESPACE

// Same with std::atomic but use relaxed memory order
// Support load, store, exchange, operators(++, --, +=, -=, &=, |= ^=)
template <typename T>
struct atomic_relaxed : std::atomic<T>
{
	static constexpr std::memory_order memory_order = std::memory_order_relaxed;
	using std::atomic<T>::atomic;

	atomic_relaxed(const atomic_relaxed<T>& other) noexcept :
		std::atomic<T>(other.load(memory_order)) {}

	atomic_relaxed<T>& operator=(const atomic_relaxed<T>& other) noexcept
	{
		store(other.load(memory_order));
		return *this;
	}

	void operator=(T val) noexcept
	{
		store(val, memory_order);
	}
	operator T() const noexcept
	{
		return load(memory_order);
	}

	void store(T val, std::memory_order order = memory_order) noexcept
	{
		std::atomic<T>::store(val, order);
	}

	T load(std::memory_order order = memory_order) const noexcept
	{
		return std::atomic<T>::load(order);
	}

	T exchange(T val) noexcept
	{
		return std::atomic<T>::exchange(val, memory_order);
	}

	T operator&=(T val) noexcept
	{
		return std::atomic<T>::fetch_and(val, memory_order);
	}
	T operator|=(T val) noexcept
	{
		return std::atomic<T>::fetch_or(val, memory_order);
	}
	T operator^=(T val) noexcept
	{
		return std::atomic<T>::fetch_xor(val, memory_order);
	}
	T operator++() noexcept
	{
		return std::atomic<T>::fetch_add(1, memory_order) + 1;
	}
	T operator--() noexcept
	{
		return std::atomic<T>::fetch_sub(1, memory_order) - 1;
	}
	T operator++(int) noexcept
	{
		return std::atomic<T>::fetch_add(1, memory_order);
	}
	T operator--(int) noexcept
	{
		return std::atomic<T>::fetch_sub(1, memory_order);
	}
	T operator+=(T val) noexcept
	{
		return std::atomic<T>::fetch_add(val, memory_order);
	}
	T operator-=(T val) noexcept
	{
		return std::atomic<T>::fetch_sub(val, memory_order);
	}
};

BASIC_END_NAMESPACE