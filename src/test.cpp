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

#include <cmath>
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

#include <numbers>
#include <fmt/format.h>
using fmt::print;
int main()
{
	intrusive_ptr<basic_namespace::Test> ret = basic_namespace::func();
	cout << "main over\n";

	constexpr double pi = M_PI; // 正常使用 M_PI
	constexpr long double pi1 = std::numbers::pi_v<long double>;
	print("{:.30f}\n{:.30f}\n", pi, pi1);

	return 0;
}
