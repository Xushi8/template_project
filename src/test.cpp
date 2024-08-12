// #include <boost/unordered/unordered_flat_set.hpp>
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_hash.hpp>
// #include <chrono>
// #include <fmt/format.h>
// #include <unordered_set>
// #include <boost/asio.hpp>
// #include <chrono>
// using namespace std::chrono_literals;
// namespace asio = boost::asio;
// using fmt::print;

// template <typename F>
// std::chrono::duration<double, std::milli> time_test(F&& f)
// {
// 	auto first = std::chrono::steady_clock::now();
// 	f();
// 	auto last = std::chrono::steady_clock::now();
// 	return last - first;
// }

// int main()
// {
// 	// std::chrono::duration<double, std::milli> tim;
// 	// constexpr size_t n = 100000;
// 	// tim = time_test([]()
// 	// 	{
// 	// 		boost::unordered_flat_set<boost::uuids::uuid> st(n);
// 	// 		// std::unordered_set<boost::uuids::uuid> st;
// 	// 		boost::uuids::random_generator ge;
// 	// 		for (size_t i = 0; i < n; i++)
// 	// 		{
// 	// 			st.emplace(ge());
// 	// 		}
// 	// 	});

// 	// print("{:.3f}ms\n", tim.count());

// 	// tim = time_test([]()
// 	// 	{
// 	// 		boost::unordered_flat_set<boost::uuids::uuid> st(n);
// 	// 		// std::unordered_set<boost::uuids::uuid> st;
// 	// 		// boost::uuids::random_generator ge;
// 	// 		boost::uuids::random_generator_pure ge;
// 	// 		for (size_t i = 0; i < n; i++)
// 	// 		{
// 	// 			st.emplace(ge());
// 	// 		}
// 	// 	});

// 	// print("{:.3f}ms\n", tim.count());

// 	// tim = time_test([]()
// 	// 	{
// 	// 		boost::unordered_flat_set<boost::uuids::uuid> st(n);
// 	// 		// std::unordered_set<boost::uuids::uuid> st;
// 	// 		// boost::uuids::random_generator ge;
// 	// 		// boost::uuids::random_generator_pure ge;
// 	// 		boost::uuids::random_generator_mt19937 ge;
// 	// 		for (size_t i = 0; i < n; i++)
// 	// 		{
// 	// 			st.emplace(ge());
// 	// 		}
// 	// 	});

// 	// print("{:.3f}ms\n", tim.count());

// 	asio::io_context ctx;
// 	asio::steady_timer timer{ctx, 500ms};
// 	timer.async_wait([](std::error_code ec)
// 		{
// 			if (!ec)
// 			{
// 				print("timer 1\n");
// 			}
// 		});
// 	timer.async_wait([](std::error_code ec)
// 		{
// 			if (!ec)
// 			{
// 				print("timer 2\n");
// 			}
// 		});
// 	timer.async_wait([](std::error_code ec)
// 		{
// 			if (!ec)
// 			{
// 				print("timer 3\n");
// 			}
// 		});
// 	timer.async_wait([](std::error_code ec)
// 		{
// 			if (!ec)
// 			{
// 				print("timer 4\n");
// 			}
// 		});
// 	timer.async_wait([](std::error_code ec)
// 		{
// 			if (!ec)
// 			{
// 				print("timer 5\n");
// 			}
// 		});
// 	timer.cancel();
// 	ctx.run();
// }

// #include <vectorclass/vectorclass.h>
// #include <iostream>
// #include <template_project/common.hpp>
// using namespace std;

// int main()
// {
// 	vectorclass::Vec8d v8;
// 	double arr[8];
// 	v8.store(arr);
// 	BASIC_UNROLL_LOOP(8)
// 	for (int i = 0; i < 8; i++)
// 	{
// 		cout << arr[i] << ' ';
// 	}
// }

// #include <iostream>
// #include <boost/multiprecision/gmp.hpp>

// int main()
// {
// 	// 创建 gmp_int 类型的变量
// 	boost::multiprecision::mpz_int a, b, c;

// 	// 从用户输入初始化变量
// 	std::cout << "Enter the first number: ";
// 	std::cin >> a;
// 	std::cout << "Enter the second number: ";
// 	std::cin >> b;

// 	// 执行一些操作
// 	c = a * b;

// 	// 输出结果
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << "c = a * b: " << c << std::endl;

// 	return 0;
// }

// #include <algorithm>
// using namespace std;

// int main()
// {
// 	int a[10] = {};
// 	sort(a, a + 10, [](int lhs, int rhs)
// 		{ return lhs < rhs; });
// }

#include <xxhash/xxhash.hpp>
#include <boost/unordered/unordered_flat_set.hpp>
#include <boost/container/set.hpp>
#include <vector>
using namespace std;

int main()
{
	vector<int> a(10);
	xxh::hash_t<128> val = xxh::xxhash3<128>(a);
	// boost::unordered_flat_set<xxh::hash_t<128>> st;
	boost::container::set<xxh::hash_t<128>> st;
	st.emplace(val);
}
