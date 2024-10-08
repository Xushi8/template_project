#include <template_project/common/error_code.hpp>

#include <fmt/core.h>
using fmt::print;

#include <template_project/common/common.hpp>

BASIC_BEGIN_NAMESPACE
[[nodiscard]] error_category const& get_error_category() noexcept
{
    static error_category error_category_instance;
    return error_category_instance;
}

void test_error_code()
{
    std::error_code ec = basic_namespace::error_code::file_error;
    print("value: {}, message: {}.\n", ec.value(), ec.message());
}
BASIC_END_NAMESPACE