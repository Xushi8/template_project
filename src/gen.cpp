#include <template_project/common/common.hpp>
#include <cstddef>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <fmt/format.h>
using namespace std;

#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif
int main()
{
#ifdef _WIN32
    // -finput-charset=utf-8 -fexec-charset=utf-8
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(CP_UTF8);       // 设置控制台输入编码，用于 std::cin
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出编码，或者写 system("chcp 65001") 也行，这里 CP_UTF8 = 65001
#elif defined __linux__
    setlocale(LC_ALL, "C.UTF-8");
#elif defined __APPLE__
    setlocale(LC_ALL, "UTF-8");
#endif

    constexpr size_t N = (1 << 30);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> uni(numeric_limits<int>::min(), numeric_limits<int>::max());
    std::vector<int> a(N);
    std::generate_n(a.begin(), N, [&]
        { return uni(rng); });
    ofstream ofs("in.txt");
    ofs.write(reinterpret_cast<const char*>(a.data()), sizeof(int) * N);
}
