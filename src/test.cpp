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
// using fmt::print;
// struct A
// {
// 	int m_data{};

// 	friend constexpr bool operator==(A const& lhs, A const& rhs) noexcept = default;

// 	friend constexpr auto operator<=>(A const& lhs, A const& rhs) noexcept = default;
// };

// template <typename T>
// T add(T lhs, T rhs)
// {
// 	return lhs + rhs;
// }

// /**
// 在头文件里声明
// extern template int add<int>(int, int);

// 在cpp里定义
// template int add<int>(int, int);

// */

// int main()
// {
// 	A x, y;
// 	print("{}\n", x < y);
// 	print("{}\n", x == y);
// 	print("{}\n", x > y);

// 	return add(1, 2);
// }

// #include <fmt/format.h>
// using fmt::print;
// #include <template_project/common/file.hpp>
// #include <template_project/common/error_code.hpp>
// #include <template_project/common/hash.hpp>

// int main()
// {
// 	auto ec = basic_namespace::create_reserve_file("a.txt", 0);
// 	print("{} {}\n", ec.value(), ec.message());
// 	ec = basic_namespace::error_code::file_error;
// 	print("value: {}, message: {}.\n", ec.value(), ec.message());
// 	// print("hash val: {}\n", *basic_namespace::hash_from_file("a.txt"));

// 	return ec.value();
// }

// #include <vectorclass/vectorclass.h>
// #include <array>
// #include <fmt/format.h>
// #include <fmt/ranges.h>
// #include <vector>
// #include <boost/container/vector.hpp>
// #include <random>
// #include <algorithm>
// using fmt::print;

// template <typename T>
// std::vector<T> gen_vec(const size_t n)
// {
// 	if constexpr (std::is_integral_v<T>)
// 	{
// 		std::mt19937 rng(std::random_device{}());
// 		std::uniform_int_distribution<T> un;
// 		boost::container::vector<T> res(n, boost::container::default_init);
// 		return {res.begin(), res.end()};
// 	}
// 	else if constexpr (std::is_floating_point_v<T>)
// 	{
// 		std::mt19937 rng(std::random_device{}());
// 		std::uniform_real_distribution<T> un;
// 		std::vector<T> res(n);
// 		return res;
// 	}
// 	else
// 	{
// 		static_assert(false, "gen_vec only support integral or floating_point");
// 	}
// }

// template <typename T, typename A = std::allocator<T>>
// class default_init_allocator : public A
// {
// 	typedef std::allocator_traits<A> a_t;

// public:
// 	template <typename U>
// 	struct rebind
// 	{
// 		using other =
// 			default_init_allocator<
// 				U, typename a_t::template rebind_alloc<U>>;
// 	};

// 	using A::A;

// 	template <typename U>
// 	void construct(U* ptr) noexcept(std::is_nothrow_default_constructible<U>::value)
// 	{
// 		::new (static_cast<void*>(ptr)) U;
// 	}
// 	template <typename U, typename... Args>
// 	void construct(U* ptr, Args&&... args)
// 	{
// 		a_t::construct(static_cast<A&>(*this),
// 			ptr, std::forward<Args>(args)...);
// 	}
// };

// namespace container = boost::container;

// container::vector<int> gen_vec(size_t n)
// {
// 	std::mt19937 rng(std::random_device{}());
// 	std::uniform_int_distribution<int> un;
// 	container::vector<int> res(n, container::default_init);
// 	std::generate_n(res.begin(), n, [&]
// 		{
// 			return un(rng);
// 		});
// 	return res;
// }

// int main()
// {
// 	vectorclass::Vec8uq vec;
// 	std::array<uint64_t, 8> arr;
// 	vec.store(arr.data());
// 	print("{}\n", arr);

// 	(void)gen_vec<int>(100);
// 	(void)gen_vec<double>(100);
// 	// (void)gen_vec<std::array<int, 1>>(100);
// }

#include <xsimd/xsimd.hpp>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <random>
using fmt::print;

void func(float* a, size_t n)
{
	size_t i;
	constexpr size_t siz = xsimd::batch<double>::size;
	for (i = 0; i + siz <= n; i += siz)
	{
		auto vec = xsimd::load_unaligned(&a[i]);
		vec = xsimd::sin(vec);
		vec.store_unaligned(&a[i]);
	}
}

xsimd::batch<double> func1(xsimd::batch<double> const& a, xsimd::batch<double> const& b, xsimd::batch<double> const& c)
{
	return a * b + c;
}

int main()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<double> unf;
	xsimd::batch<double> a(unf(rng));
	xsimd::batch<double> b(unf(rng));
	xsimd::batch<double> c(unf(rng));
	auto mean = a * b + c;
	auto mean1 = xsimd::fma(a, b, c);
	std::array<double, mean.size> tmp;
	mean.store_unaligned(tmp.data());
	print("{}\n", tmp);
	mean1.store_unaligned(tmp.data());
	print("{}\n", tmp);
}