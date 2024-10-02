// #include <boost/intrusive/bs_set.hpp>
// #include <iostream>

// class MyClass : public boost::intrusive::bs_set_base_hook<>
// {
// public:
// 	int data;
// 	MyClass(int d) :
// 		data(d) {}

// 	// 定义比较函数以确保树的有序性
// 	bool operator<(const MyClass& other) const
// 	{
// 		return data < other.data;
// 	}
// };

// int main()
// {
// 	using namespace boost::intrusive;

// 	// 创建 bs_set 容器
// 	bs_set<MyClass> my_btree;

// 	// 插入对象
// 	MyClass obj1(1), obj2(2), obj3(3);
// 	my_btree.insert(obj1);
// 	my_btree.insert(obj2);
// 	my_btree.insert(obj3);

// 	// 遍历 B 树中的元素
// 	for (auto& obj : my_btree)
// 	{
// 		std::cout << obj.data << std::endl;
// 	}

// 	// 查找元素
// 	auto it = my_btree.find(MyClass(2));
// 	if (it != my_btree.end())
// 	{
// 		std::cout << "Found: " << it->data << std::endl;
// 	}

// 	// 删除元素
// 	my_btree.erase(it);

// 	return 0;
// }

// #include <cmath>
// #include <template_project/common/common.hpp>
// #include <iostream>
// #include <boost/smart_ptr.hpp>
// #include <boost/smart_ptr/intrusive_ref_counter.hpp>
// using namespace std;
// using namespace boost;

// BASIC_BEGIN_NAMESPACE

// // 自定义对象类
// class Test;
// ostream& operator<<(ostream& out, const Test& t);

// class Test : public boost::intrusive_ref_counter<
// 				 Test,
// 				 boost::thread_safe_counter>
// {
// 	friend ostream& operator<<(ostream& out, const Test& t);

// public:
// 	Test(int d = 0) :
// 		data(d)
// 	{
// 		cout << "Test()\n";
// 	}

// 	~Test()
// 	{
// 		cout << "~Test()\n";
// 	}

// private:
// 	int data;
// };

// ostream& operator<<(ostream& out, const Test& t)
// {
// 	out << t.data;
// 	return out;
// }

// __attribute__((noinline)) intrusive_ptr<Test> func()
// {
// 	Test* pt = new Test(10);
// 	intrusive_ptr<Test> ip(pt);
// 	cout << *ip << endl;
// 	auto tmp = ip;
// 	cout << *tmp << endl;
// 	cout << "func over\n";
// 	return tmp;
// }


/**

*   1

*   1
*

 *  3
***
 *

 *  3
***
***
 *

*/

// #include <iostream>
// #include <string>

// int main()
// {
// 	int n;
// 	std::cin >> n;
// 	const int max_len = (n % 2 == 0 ? n - 1 : n); // 最长边的长度
// 	for (int row = 0, num_of_star = -1; row < n; row++)
// 	{
// 		if (row <= n / 2)
// 		{
// 			if (num_of_star < max_len)
// 			{
// 				num_of_star += 2;
// 			}
// 		}
// 		else
// 		{
// 			num_of_star -= 2;
// 		}

// 		std::string space((max_len - num_of_star) / 2, ' ');
// 		std::string star(num_of_star, '*');

// 		std::cout << space << star << '\n';
// 	}

// 	return 0;
// }


/**
single thread:
unstable use boost::sort::spinsort
  stable use boost::sort::pdqsort

multi thread
unstable use boost::block_indirect_sort
  stable use boost::sample_sort
*/

// #include <fmt/format.h>
// #include <fmt/chrono.h>
// #include <random>
// #include <boost/container/vector.hpp>
// #include <execution>
// #include <tbb/parallel_sort.h>
// #include <boost/sort/sort.hpp>
// using fmt::print;
// namespace container = boost::container;

// template <typename Func>
// std::chrono::duration<double, std::milli> time_test(Func&& func)
// {
// 	auto t_begin = std::chrono::steady_clock::now();
// 	func();
// 	auto t_end = std::chrono::steady_clock::now();
// 	return (t_end - t_begin);
// }

// int main()
// {
// 	constexpr size_t N = 1e8;
// 	container::vector<size_t> a(N, container::default_init);
// 	std::mt19937 rng(std::random_device{}());
// 	std::uniform_int_distribution<size_t> uni;

// 	auto time_use = time_test([&]
// 		{
// 			std::generate(a.begin(), a.end(), [&]
// 				{
// 					return uni(rng);
// 				});
// 		});
// 	print("std::generate:\t\t\t {:.3f}ms\n", time_use.count());

// 	auto b = a;

// 	time_use = time_test([&]
// 		{
// 			std::sort(a.begin(), a.end());
// 		});
// 	print("std::sort:\t\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			std::stable_sort(a.begin(), a.end());
// 		});
// 	print("std::stable_sort:\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			std::sort(std::execution::par_unseq, a.begin(), a.end());
// 		});
// 	print("std::sort with par_unseq:\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			tbb::parallel_sort(a.begin(), a.end());
// 		});
// 	print("tbb::parallel_sort:\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::spreadsort::spreadsort(a.begin(), a.end());
// 		});
// 	print("boost::spreadsort:\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::pdqsort(a.begin(), a.end());
// 		});
// 	print("boost::pdqsort:\t\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::pdqsort_branchless(a.begin(), a.end());
// 		});
// 	print("boost::pdqsort_branchless:\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::spinsort(a.begin(), a.end());
// 		});
// 	print("boost::spinsort:\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::flat_stable_sort(a.begin(), a.end());
// 		});
// 	print("boost::flat_stable_sort:\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::block_indirect_sort(a.begin(), a.end());
// 		});
// 	print("boost::block_indirect_sort:\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::sample_sort(a.begin(), a.end());
// 		});
// 	print("boost::sample_sort:\t\t {:.3f}ms\n", time_use.count());

// 	a = b;
// 	time_use = time_test([&]
// 		{
// 			boost::sort::parallel_stable_sort(a.begin(), a.end());
// 		});
// 	print("boost::parallel_stable_sort:\t {:.3f}ms\n", time_use.count());
// }

// #include <ratio>
// #include <fmt/format.h>
// using fmt::print;
// int main()
// {
// 	using milli = std::ratio<1, 1000>;
// 	print("{} {}\n", milli::num, milli::den);

// 	using one = std::ratio<1, 1>;
// 	using result = std::ratio_divide<one, milli>;
// 	print("{} {}\n", result::num, result::den);
// }

#include <atomic>
template <typename T>
struct atomic_relaxed : std::atomic<T>
{
	static constexpr std::memory_order memory_order = std::memory_order_relaxed;
	using std::atomic<T>::atomic;

	atomic_relaxed(const atomic_relaxed<T>& other) noexcept :
		std::atomic<T>(other.load(memory_order)) {}

	atomic_relaxed<T>& operator=(const atomic_relaxed<T>& other) = delete;

	T operator=(T val) noexcept // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
	{
		store(val, memory_order);
		return val;
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

	T exchange(T val, std::memory_order order = memory_order) noexcept
	{
		return std::atomic<T>::exchange(val, order);
	}

	bool compare_exchange_weak(T& expected, T desired, std::memory_order order = memory_order)
	{
		return std::atomic<T>::compare_exchange_weak(expected, desired, order);
	}

	bool compare_exchange_strong(T& expected, T desired, std::memory_order order = memory_order)
	{
		return std::atomic<T>::compare_exchange_strong(expected, desired, order);
	}

	void wait(T old, std::memory_order order = memory_order)
	{
		std::atomic<T>::wait(old, order);
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