#include <common/error_code.h>

#include <fmt/core.h>
using fmt::print;

namespace basic_namespace
{
void test_error_code()
{
	std::error_code ec = basic_namespace::error_code::file_error;
	print("value: {}, message: {}.\n", ec.value(), ec.message());
}
} // namespace basic_namespace