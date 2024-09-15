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


#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/mpfr.hpp>
#include <fmt/format.h>
using fmt::print;

namespace multiprecision =  boost::multiprecision;

int main()
{
	multiprecision::mpf_float ans{};
	constexpr size_t n = 1e6;
	for (size_t i = 1; i <= n; i++)
	{
		ans += multiprecision::log(multiprecision::mpf_float(i)) / (i * i);
	}

	print("{}\n", ans.str());
}