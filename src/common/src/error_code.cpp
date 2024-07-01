#include <common/error_code.h>

#include <fmt/core.h>
using fmt::print;
using fmt::println;

namespace basic_namespace
{
void test_error_code()
{
	std::error_code ec = basic_namespace::error_code::file_error;
    println("value: {}, message: {}.", ec.value(), ec.message());
}
}