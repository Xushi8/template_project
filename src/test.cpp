// #include <boost/asio.hpp>
// #include <boost/unordered/unordered_flat_map.hpp>
// #include <boost/unordered/unordered_flat_set.hpp>
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_hash.hpp>
// #include <chrono>
// #include <fmt/format.h>
// #include <numeric>
// #include <random>
// #include <unordered_set>
// #include <execution>
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

// 	// asio::io_context ctx;
// 	// asio::steady_timer timer{ctx, 500ms};
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 1\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 2\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 3\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 4\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 5\n");
// 	// 		}
// 	// 	});
// 	// timer.cancel();
// 	// ctx.run();

// 	constexpr int n = 1000000;
// 	std::vector<int64_t> a(n);
// 	constexpr size_t seed = 1331;
// 	std::mt19937_64 rng(seed);
// 	std::generate(a.begin(), a.end(), rng);
// 	auto b = a;
// 	std::shuffle(a.begin(), a.end(), rng);
// 	std::shuffle(b.begin(), b.end(), rng);
// 	boost::unordered_flat_map<int64_t, int64_t> mp(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		mp.try_emplace(a[i], b[i]);
// 	}

// 	auto query = b;
// 	std::shuffle(query.begin(), query.end(), rng);
// 	for (int t = 0; t < 100; t++)
// 	{
// 		__int128_t total = 0;
// 		auto tim = time_test([&]
// 			{
// 				for (auto key : query)
// 				{
// 					total += mp[key];
// 				}
// 			});
// 		if (t > 95)
// 		{
// 			print("t: {}, total: {}, elapsed: {:.3f}ms\n", t, total, tim.count());
// 		}
// 	}
// }

// #include <expected>
// #include <system_error>
// #include <xxhash/xxhash.hpp>
// #include <fmt/format.h>
// #include <fstream>
// using fmt::print;

// std::expected<int, std::error_code> sqrfloor(int x)
// {
// 	if (x < 1)
// 	{
// 		std::ifstream ifs("a.txt");
// 		return std::unexpected{std::make_error_code(static_cast<std::errc>(errno))};
// 	}
// 	return 1;
// }

// int main()
// {
// 	auto x = sqrfloor(0);
// 	if (x.has_value())
// 	{
// 		print("great\n");
// 	}
// 	else
// 	{
// 		print("bad\n{}\n", x.error().message());
// 		throw std::system_error(x.error(), "main");
// 	}

// 	print("{}\n", __cpp_concepts);
// }

// #include <mio/mio.hpp>
// #include <system_error>
// #include <string_view>
// #include <fmt/format.h>
// #include <template_project/hash.hpp>
// using fmt::print;

// int main()
// {
// 	std::error_code ec;
// 	std::string_view path = "./a.txt";
// 	mio::mmap_source mmap = mio::make_mmap_source(path, ec);
// 	// std::string_view s(mmap.begin(), mmap.end());
// 	// print("{}\n", s);

// 	auto res = basic_namespace::hash_from_file_both(path);
// 	if (res.has_value())
// 	{
// 		auto x = res->second;
// 		__uint128_t val = (__uint128_t(x.high64) << 64) | x.low64;
// 		print("{:x}\n", val);
// 	}
// 	else
// 	{
// 		print("{}\n", res.error().message());
// 	}
// }

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

#include <template_project/common.hpp>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
using namespace std;
using namespace boost;

void* operator new(size_t size)
{
	std::cout << "Global new: Allocating " << size << " bytes\n";
	return std::malloc(size); // 使用 std::malloc 分配内存
}

void operator delete(void* pointer) noexcept
{
	std::cout << "Global delete: Releasing memory\n";
	std::free(pointer); // 使用 std::free 释放内存
}


BASIC_BEGIN_NAMESPACE

// 自定义对象类
class Test;
ostream& operator<<(ostream& out, const Test& t);

class Test : public boost::intrusive_ref_counter<
				 Test,
				 boost::thread_safe_counter>
{
	friend ostream& operator<<(ostream& out, const Test& t);

public:
	Test(int d = 0) :
		data(d)
	{
		cout << "Test()\n";
	}

	~Test()
	{
		cout << "~Test()\n";
	}

private:
	int data;
};

ostream& operator<<(ostream& out, const Test& t)
{
	out << t.data;
	return out;
}

__attribute__((noinline)) intrusive_ptr<Test> func()
{
	Test* pt = new Test(10);
	intrusive_ptr<Test> ip(pt);
	cout << *ip << endl;
	auto tmp = ip;
	cout << *tmp << endl;
	cout << "func over\n";
	return tmp;
}

BASIC_END_NAMESPACE

int main()
{
	intrusive_ptr<basic_namespace::Test> ret = basic_namespace::func();
	cout << "main over\n";

	return 0;
}
