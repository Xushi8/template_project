// #include <cmath>
// #include <template_project/common/common.hpp>
// #include <iostream>
// #include <boost/smart_ptr.hpp>
// #include <boost/smart_ptr/intrusive_ref_counter.hpp>
// using namespace std;
// using namespace boost;

// BASIC_PROJECT_BEGIN_NAMESPACE

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
// using fmt::print;
// #include <template_project/common/error_code.hpp>
// #include <memory>
// #include <cstdio>

// struct fclose_deleter
// {
//     void operator()(FILE* fp) const noexcept
//     {
//         fclose(fp);
//     }
// };
// using file_ptr = std::unique_ptr<FILE, fclose_deleter>;

// struct free_deleter
// {
//     void operator()(void* p) const noexcept
//     {
//         free(p); // NOLINT(cppcoreguidelines-no-malloc)
//     }
// };
// template <typename T>
// using c_unique_ptr = std::unique_ptr<T, free_deleter>;

// int main()
// {
//     std::error_code ec{basic_namespace::make_error_code(basic_namespace::error_code::file_error)};
//     print("{} {}\n", ec.value(), ec.message());
// }

// #include <ranges>
// #include <fmt/base.h>
// #include <vector>
// using fmt::print;

// int main()
// {
//     auto split_string = std::string_view{"Hello,World,, ,C++20!"}
//                         | std::ranges::views::split(',')
//                         | std::ranges::views::transform([](auto const& rng)
//                             { return std::string_view(rng.data(), rng.size()); })
//                         | std::ranges::views::filter([](std::string_view sv)
//                             { return !sv.empty(); });
//     for (auto const& str : split_string)
//     {
//         print("{}\n", str);
//     }

//     auto rng = std::views::iota(1, 10) | std::views::take(5) | std::views::transform([](int x)
//                    { return std::to_string(x); });

//     std::vector<std::string> vec{rng.begin(), rng.end()};
//     for (auto const& x : vec)
//     {
//         print("{}\n", x);
//     }

//     std::string input = "part1|||part2|||part3";
//     std::string delimiter = "|||";
//     auto parts = input | std::views::split(delimiter)
//                  | std::views::transform([](auto const& part)
//                      { return std::string_view(part.begin(), part.end()); })
//                  | std::views::filter([](std::string_view sv)
//                      { return !sv.empty(); });

//     for (std::string_view sv : parts)
//     {
//         print("{}\n", sv);
//     }

//     for (std::string_view sv : parts)
//     {
//         print("{}\n", sv);
//     }
// }

// #include <random>
// #include <cassert>

// int main()
// {
//     auto rnd = std::mt19937(1080100664);
//     assert(rnd() == 7);

//     rnd.seed(736640520);
//     assert(rnd() == 7);

//     rnd.seed(1292535796);
//     assert(rnd() == 13);

//     auto x = std::mt19937::result_type{10};
// }

// void func(int n, int m)
// {
//     std::vector<std::vector<int>> a(n, std::vector<int>(m));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; i++)
//         {
//             a[i][j] = 1000;
//         }
//     }
// }

#include <fmt/format.h>
#include <source_location>
using fmt::print;

int main()
{
    print("{} {} {} {}\n", std::source_location::current().file_name(), std::source_location::current().line(), std::source_location::current().column(), std::source_location::current().function_name());
}
