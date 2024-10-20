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

#include <fmt/format.h>
using fmt::print;
#include <tbb/tbb.h>

int x;
tbb::spin_rw_mutex mtx;

void func1()
{
    std::scoped_lock lock(mtx);
    x++;
}

int func2()
{
    std::shared_lock lock(mtx);
    return x;
}

std::atomic<int> x1;

void func3()
{
    x1.fetch_add(1, std::memory_order_relaxed);
}

int func4()
{
    return x1.load(std::memory_order_relaxed);
}

int main()
{
    constexpr size_t n = 10000;
    tbb::parallel_for(tbb::blocked_range<size_t>(0, n), [&](tbb::blocked_range<size_t> const& r)
        {
            for (size_t i = r.begin(); i != r.end(); i++)
            {
                func3();
                print("{}\n", func4());
            }
        });
}