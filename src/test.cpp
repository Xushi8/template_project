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
unstable use boost::sort::pdqsort     附带一个branch_less版本的比较函数
  stable use boost::sort::spinsort

multi thread
unstable use boost::sort::block_indirect_sort
  stable use boost::sort::sample_sort
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

/*

#include <iostream>
#include <cstring>
#include <cerrno>

#include <fcntl.h>
#include <unistd.h>

#ifdef __APPLE__
#include <sys/fcntl.h>
#include <sys/stat.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

#include <cstdint>

#ifdef _WIN32
void PrintLastError(const std::string& function_name)
{
    DWORD error_code = GetLastError();
    std::cerr << "Error in function " << function_name << ": " << error_code << " (" << error_code << ")" << std::endl;
}
#endif

bool reserve_file_size(std::string_view file_name, uint64_t file_size)
{
    int fd = open(file_name.data(), O_RDWR | O_CREAT, 0644); // 打开文件
    if (fd == -1)
    {
        std::cerr << "Failed to open file: " << strerror(errno) << std::endl;
        return false;
    }

#if defined(__linux__) && !defined(__APPLE__) && !defined(__MINGW32__)
    // Linux 使用 fallocate
    int r;
    while ((r = fallocate(fd, 0, 0, file_size)) == -1 && errno == EINTR)
    {
        // 如果遇到 EINTR 错误，重试
    }
    if (r == -1)
    {
        std::cerr << "fallocate failed: " << strerror(errno) << std::endl;
        close(fd);
        return false;
    }
#elif defined(__APPLE__)
    // macOS 使用 fcntl 进行预分配
    fstore_t fstore = {F_ALLOCATECONTIG | F_ALLOCATEALL, F_PEOFPOSMODE, 0, file_size, 0};
    if (fcntl(fd, F_PREALLOCATE, &fstore) == -1)
    {
        fstore.fst_flags = F_ALLOCATEALL; // 尝试非连续分配
        if (fcntl(fd, F_PREALLOCATE, &fstore) == -1)
        {
            std::cerr << "fcntl(F_PREALLOCATE) failed: " << strerror(errno) << std::endl;
            close(fd);
            return false;
        }
    }
    // 扩展文件大小，确保逻辑大小正确
    if (ftruncate(fd, file_size) == -1)
    {
        std::cerr << "ftruncate failed: " << strerror(errno) << std::endl;
        close(fd);
        return false;
    }
#elif defined(_WIN32)
    // 获取并调整进程令牌的权限
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
    {
        PrintLastError("OpenProcessToken");
        return false;
    }

    TOKEN_PRIVILEGES tp;
    tp.PrivilegeCount = 1;
    if (!LookupPrivilegeValue(NULL, SE_MANAGE_VOLUME_NAME, &tp.Privileges[0].Luid))
    {
        PrintLastError("LookupPrivilegeValue");
        CloseHandle(hToken);
        return false;
    }

    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL))
    {
        PrintLastError("AdjustTokenPrivileges");
        CloseHandle(hToken);
        return false;
    }

    CloseHandle(hToken);

    // 打开文件
    HANDLE hFile = CreateFileA(
        file_name.data(),
        GENERIC_WRITE,
        FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        PrintLastError("CreateFileA");
        return false;
    }

    // 设置文件大小
    LARGE_INTEGER distanceToMove;
    distanceToMove.QuadPart = file_size;
    if (!SetFilePointerEx(hFile, distanceToMove, NULL, FILE_BEGIN))
    {
        PrintLastError("SetFilePointerEx");
        CloseHandle(hFile);
        return false;
    }

    if (!SetEndOfFile(hFile))
    {
        PrintLastError("SetEndOfFile");
        CloseHandle(hFile);
        return false;
    }

    if (!SetFileValidData(hFile, distanceToMove.QuadPart))
    {
        PrintLastError("SetFileValidData");
        CloseHandle(hFile);
        return false;
    }

    // 关闭句柄
    CloseHandle(hFile);
    return true;
#else
    std::cerr << "Unsupported platform" << std::endl;
    close(fd);
    return false;
#endif

    close(fd); // 关闭文件
    return true;
}

int main()
{
    const std::string filename = "testfile.dat";
    uint64_t file_size = uint64_t(1024) * 1024 * 1024 * 1;

    if (reserve_file_size(filename, file_size))
    {
        std::cout << "File space reserved successfully." << std::endl;
    }
    else
    {
        std::cerr << "Failed to reserve space for the file." << std::endl;
    }

    return 0;
}

*/

#include <boost/asio.hpp>
namespace asio = boost::asio;
#include <fmt/format.h>
using fmt::print;

namespace
{
asio::awaitable<void> file_test()
{
    asio::stream_file file(co_await asio::this_coro::executor, "/home/tom/a.txt", asio::stream_file::write_only | asio::stream_file::create | asio::stream_file::append);

    using namespace std::string_view_literals;
    constexpr std::string_view buf = "asdlkjaowijdlasjlasijdlajasd\n"sv;
    size_t n = co_await asio::async_write(file, asio::buffer(buf), asio::use_awaitable);
    if (buf.size() == n) [[likely]]
    {
        print("write well\n");
    }
    else
    {
        print("write bad\n");
    }
}
} // namespace

int main()
{
    asio::io_context ctx;
    asio::co_spawn(ctx, file_test(), asio::detached);

    ctx.run();
}
