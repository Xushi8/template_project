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

// BASIC_END_NAMESPACE

// #include <numbers>
// #include <fmt/format.h>
// using fmt::print;
// int main()
// {
// 	intrusive_ptr<basic_namespace::Test> ret = basic_namespace::func();
// 	cout << "main over\n";

// 	constexpr double pi = M_PI; // 正常使用 M_PI
// 	constexpr long double pi1 = std::numbers::pi_v<long double>;
// 	print("{:.30f}\n{:.30f}\n", pi, pi1);

// 	return 0;
// }

// #include <fmt/format.h>
// #include <xsimd/xsimd.hpp>
// using fmt::print;

// gather
/**
int main()
{
	alignas(32) int data[8] = {10, 20, 30, 40, 50, 60, 70, 80};
	xsimd::batch<int, xsimd::fma3<xsimd::avx2>> index = {0, 2, 4, 6, 1, 3, 5, 7};
	decltype(index) result;
	result = result.gather(data, index);

	alignas(32) int res[8];
	result.store_aligned(res);
	for (std::size_t i = 0; i < result.size; ++i)
	{
		print("{} ", res[i]);
	}
}
*/

// int main()
// {
// 	const xsimd::batch<int> c(1);
// 	const xsimd::batch<int> z(0);

// 	xsimd::batch<int> s(0);

// 	constexpr size_t N = 3248324979843;
// 	int* a = new int[N];

// 	for (size_t i = 0; i + s.size <= N; i += s.size)
// 	{
// 		xsimd::batch<int> x = xsimd::load_unaligned(&a[i]);
// 		auto mask = (x > c);
// 		x = xsimd::select(mask, x, z);
// 		s += x;
// 	}

// 	return xsimd::reduce_add(s);
// }

// int func()
// {
// 	const xsimd::batch<int> c(1);

// 	xsimd::batch<int> s(0);

// 	constexpr size_t N = 3248324979843;
// 	int* a = new int[N];

// 	for (size_t i = 0; i + s.size <= N; i += s.size)
// 	{
// 		xsimd::batch<int> x = xsimd::load_unaligned(&a[i]);
// 		auto mask = (x > c);
// 		x &= static_cast<xsimd::batch<int>>(mask);
// 		s += x;
// 	}

// 	return xsimd::reduce_add(s);
// }

// inline int horizontal_sum(__m256i x)
// {
// 	// 提取低128位和高128位
// 	__m128i low = _mm256_extracti128_si256(x, 0);  // 低128位
// 	__m128i high = _mm256_extracti128_si256(x, 1); // 高128位

// 	// 先对每个128位向量中的元素求和
// 	__m128i sum128 = _mm_add_epi32(low, high);

// 	// 水平加法：将128位中的4个int求和
// 	sum128 = _mm_hadd_epi32(sum128, sum128);
// 	sum128 = _mm_hadd_epi32(sum128, sum128);

// 	// 提取结果
// 	return _mm_cvtsi128_si32(sum128);
// }

// int func2()
// {
// 	constexpr size_t N = 3248324979843;
// 	int* a = new int[N];
// 	const __m256i c = _mm256_set1_epi32(50);
// 	__m256i s = _mm256_setzero_si256();

// 	for (size_t i = 0; i < N; i += 8)
// 	{
// 		__m256i x = _mm256_load_si256((__m256i*)&a[i]);
// 		__m256i mask = _mm256_cmpgt_epi32(c, x);
// 		x = _mm256_and_si256(x, mask);
// 		s = _mm256_add_epi32(s, x);
// 	}

// 	return horizontal_sum(s);
// }

// #include <chrono>
// #include <xsimd/xsimd.hpp>
// #include <fmt/format.h>
// #include <execution>
// #include <boost/container/vector.hpp>
// #include <fstream>
// using fmt::print;

// namespace container = boost::container;

// #define celve std::execution::unseq

// template <typename Func>
// std::chrono::duration<double, std::milli> time_test(Func&& func)
// {
// 	auto t_begin = std::chrono::steady_clock::now();
// 	func();
// 	auto t_end = std::chrono::steady_clock::now();
// 	return t_end - t_begin;
// }

// size_t find1(container::vector<int> const& vec, int val)
// {
// 	return std::find(celve, vec.begin(), vec.end(), val) - vec.begin();
// }

// size_t find2(container::vector<int> const& vec, int val)
// {
// 	__m256i x = _mm256_set1_epi32(val);
// 	const int* a = vec.data();

// 	for (size_t i = 0; i < vec.size(); i += 16)
// 	{
// 		__m256i y1 = _mm256_load_si256((__m256i*)&a[i]);
// 		__m256i y2 = _mm256_load_si256((__m256i*)&a[i + 8]);
// 		__m256i m1 = _mm256_cmpeq_epi32(x, y1);
// 		__m256i m2 = _mm256_cmpeq_epi32(x, y2);
// 		__m256i m = _mm256_or_si256(m1, m2);
// 		if (!_mm256_testz_si256(m, m))
// 		{
// 			int mask = (_mm256_movemask_ps((__m256)m2) << 8)
// 					   + _mm256_movemask_ps((__m256)m1);
// 			return i + __builtin_ctz(mask);
// 		}
// 	}

// 	return vec.size();
// }

// int main()
// {
// 	std::ifstream ifs("a.txt");
// 	ifs.seekg(0, std::ios::end);
// 	const size_t N = ifs.tellg() / sizeof(char) / sizeof(int);
// 	ifs.seekg(0);
// 	print("vector before\n");
// 	container::vector<int> a(N, container::default_init);
// 	print("vector default init over\n");
// 	print("vector read begin\n");
// 	ifs.read(reinterpret_cast<char*>(a.data()), N * sizeof(int));
// 	print("vector read over\n");

// 	const int target = a[N - 1];
// 	size_t res;
// 	auto time_use = time_test([&]
// 		{
// 			res = find1(a, target);
// 		});
// 	print("{} {}ms\n", res, time_use.count());

// 	time_use = time_test([&]
// 		{
// 			res = find2(a, target);
// 		});
// 	print("{} {}ms\n", res, time_use.count());
// }

// #include <boost/multiprecision/gmp.hpp>
// #include <boost/multiprecision/mpfr.hpp>
// #include <fmt/format.h>
// #include <numbers>
// using fmt::print;

// namespace multiprecision =  boost::multiprecision;

// int main()
// {
// 	multiprecision::mpf_float ans1{};
// 	constexpr size_t n = 30;
// 	for (size_t i = 1; i <= n; i++)
// 	{
// 		ans1 += multiprecision::log(multiprecision::mpf_float(i)) / (i * i);
// 	}

// 	print("{}\n", ans1.str());

// 	multiprecision::mpf_float ans2{};
// 	for (size_t i = 1; i <= n; i++)
// 	{
// 		ans2 += multiprecision::mpf_float(1) / (i * i);
// 	}
// 	print("{}\n", ans2.str());

// 	print("{}\n", std::numbers::pi * std::numbers::pi / 6);
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

// #include <deque>
// #include <list>
// #include <template_project/common/common.hpp>
// #include <template_project/common/atomic.hpp>
// #include <cstddef>
// #include <random>
// #include <algorithm>
// #include <array>
// #include <tbb/parallel_for.h>
// #include <fmt/format.h>
// #include <fmt/ranges.h>
// using fmt::print;

// enum class choice
// {
// 	huan,
// 	buhuan,
// };

// template <choice game_choice>
// bool game()
// {
// 	thread_local std::mt19937 rng(std::random_device{}());
// 	std::uniform_int_distribution<size_t> uni(0, 2);
// 	std::array<bool, 3> men{true, false, false};
// 	std::shuffle(men.begin(), men.end(), rng);
// 	size_t index = uni(rng);
// 	if constexpr (game_choice == choice::buhuan)
// 		return men[index];

// 	size_t wrong_index = [&]
// 	{
// 		for (size_t i = 0; i < 3; i++)
// 		{
// 			if (i != index && !men[i])
// 			{
// 				return i;
// 			}
// 		}
// 		basic_namespace::unreachable();
// 	}();

// 	for (size_t i = 0; i < 3; i++)
// 	{
// 		if (i != index && i != wrong_index)
// 		{
// 			return men[i];
// 		}
// 	}

// 	basic_namespace::unreachable();
// }

// int main()
// {
// 	constexpr size_t N = 1e5;
// 	double ans_huan, ans_buhuan;

// 	basic_namespace::atomic_relaxed<size_t> sum_huan = 0, sum_buhuan = 0;
// 	// check random_access_iterator and input_iterator
// 	// input iterator not support
// 	std::deque<int> a(N);
// 	iota(a.begin(), a.end(), 0);
// 	tbb::parallel_for(tbb::blocked_range<decltype(a.begin())>(a.begin(), a.end()), [&](tbb::blocked_range<decltype(a.begin())> const& r)
// 		{
// 			size_t local_sum_huan = 0, local_sum_buhuan = 0;
// 			std::vector<size_t> vec;
// 			for(auto i = r.begin(); i != r.end(); i++)
// 			{
// 				local_sum_huan += game<choice::huan>();
// 				local_sum_buhuan += game<choice::buhuan>();
// 				vec.emplace_back(*i);
// 			}
// 			sum_huan += local_sum_huan;
// 			sum_buhuan += local_sum_buhuan;
// 			print("{}\n {}\n", vec.size(), vec);
// 		});
// 	ans_huan = sum_huan * 100.0 / N;
// 	ans_buhuan = sum_buhuan * 100.0 / N;

// 	print("huan: {}%, buhaun: {}%\n", ans_huan, ans_buhuan);
// }

/**
single thread:
unstable use boost::sort::spinsort
  stable use boost::sort::pdqsort

multi thread
unstable use boost::block_indirect_sort
  stable use boost::sample_sort
*/

#include <fmt/format.h>
#include <fmt/chrono.h>
#include <random>
#include <boost/container/vector.hpp>
#include <execution>
#include <tbb/parallel_sort.h>
#include <boost/sort/sort.hpp>
using fmt::print;
namespace container = boost::container;

template <typename Func>
std::chrono::duration<double, std::milli> time_test(Func&& func)
{
	auto t_begin = std::chrono::steady_clock::now();
	func();
	auto t_end = std::chrono::steady_clock::now();
	return (t_end - t_begin);
}

int main()
{
	constexpr size_t N = 1e8;
	container::vector<size_t> a(N, container::default_init);
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<size_t> uni;

	auto time_use = time_test([&]
		{
			std::generate(a.begin(), a.end(), [&]
				{
					return uni(rng);
				});
		});
	print("std::generate:\t\t\t {:.3f}ms\n", time_use.count());

	auto b = a;

	time_use = time_test([&]
		{
			std::sort(a.begin(), a.end());
		});
	print("std::sort:\t\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			std::stable_sort(a.begin(), a.end());
		});
	print("std::stable_sort:\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			std::sort(std::execution::par_unseq, a.begin(), a.end());
		});
	print("std::sort with par_unseq:\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			tbb::parallel_sort(a.begin(), a.end());
		});
	print("tbb::parallel_sort:\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::spreadsort::spreadsort(a.begin(), a.end());
		});
	print("boost::spreadsort:\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::pdqsort(a.begin(), a.end());
		});
	print("boost::pdqsort:\t\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::spinsort(a.begin(), a.end());
		});
	print("boost::spinsort:\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::flat_stable_sort(a.begin(), a.end());
		});
	print("boost::flat_stable_sort:\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::block_indirect_sort(a.begin(), a.end());
		});
	print("boost::block_indirect_sort:\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::sample_sort(a.begin(), a.end());
		});
	print("boost::sample_sort:\t\t {:.3f}ms\n", time_use.count());

	a = b;
	time_use = time_test([&]
		{
			boost::sort::parallel_stable_sort(a.begin(), a.end());
		});
	print("boost::parallel_stable_sort:\t {:.3f}ms\n", time_use.count());
}