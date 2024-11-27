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
}