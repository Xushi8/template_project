#include <template_project/error_code.hpp>

#include <fmt/core.h>
using fmt::print;

namespace basic_namespace
{
inline namespace v0
{
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
} // namespace v0
} // namespace basic_namespace