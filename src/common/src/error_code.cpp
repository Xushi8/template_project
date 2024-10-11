#include <template_project/common/error_code.hpp>

BASIC_BEGIN_NAMESPACE
[[nodiscard]] error_category const& get_error_category() noexcept
{
    static error_category error_category_instance;
    return error_category_instance;
}

BASIC_END_NAMESPACE