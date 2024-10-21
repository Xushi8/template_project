#include <template_project/common/log.hpp>
#include <template_project/common/hash.hpp>
#include <array>
#include <vector>
#include <fmt/core.h>
#include <cstdint>
#include <string_view>
#include <string>
#include <template_project/common/error_code.hpp>
#include <re2/re2.h>

#include <template_project/common/common.hpp>

#include <clocale>

#ifdef _WIN32
#include <windows.h>
#endif

BASIC_PROJECT_BEGIN_NAMESPACE
using u64 = uint64_t;
using fmt::print;

void test_spdlog()
{
    spdlog::info("info log");
    spdlog::warn("warn log");
}

void test_xxhash()
{
    auto hash_val = hash_from_file("/media/tom/Data/test.txt");
    if (!hash_val.has_value())
    {
        print("/media/tom/Data/test.txt error: {}\n", hash_val.error().message());
    }
    else
    {
        print("{:x}\n", *hash_val);
    }

    auto val1 = hash_from_file_both("./.gitignore");
    if (!val1.has_value())
    {
        print("./.gitignore error: {}\n", val1.error().message());
    }
    else
    {
        print("{:x}\n", val1->first);
    }
    constexpr uint64_t x = 0xf74f53b60490421c;
    constexpr uint64_t y = 0x1c429004b6534ff7;
    print("{}\n{}\n", x, y);

    std::array<int, 4> arr = {0, 0, 0, 0};
    hash_val = xxh::xxhash3<64>(arr);
    print("{}\n", *hash_val);

    std::vector<int> vec = {0, 0, 0, 0};
    hash_val = xxh::xxhash3<64>(vec);
    print("{}\n", *hash_val);

    std::vector<char> vec1(16, 'a');
    hash_val = xxh::xxhash3<64>(vec1);
    print("{}\n", *hash_val);
}
BASIC_PROJECT_END_NAMESPACE

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef _WIN32
    setlocale(LC_ALL, ".utf-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#else
    setlocale(LC_ALL, "");
#endif

    basic_namespace::set_default_log(spdlog::level::info, "logs/mylog.txt", "template_project");

    basic_namespace::test_xxhash();

    std::string text = "My emails are first@example.com, second@example.com, and third@example.com.";
    std::string pattern = R"((\w+@\w+\.\w+))"; // 正则表达式模式
    RE2 re(pattern);

    re2::StringPiece input(text);
    std::string email;

    while (RE2::FindAndConsume(&input, re, &email))
    {
        fmt::print("Found email: {}\n", email);
    }

    return 0;
}
