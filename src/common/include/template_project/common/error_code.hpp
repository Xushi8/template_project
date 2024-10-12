#pragma once

#include <system_error>

#include <template_project/common/common.hpp>

BASIC_PROJECT_BEGIN_NAMESPACE
enum class error_code
{
    success = 0,
    network_error,
    file_error,
};

struct BASIC_PROJECT_EXPORT error_category : public std::error_category
{
    const char* name() const noexcept override
    {
        return "BASIC_PROJECT_namespace::error_category";
    }

    std::string message(int ev) const noexcept override
    {
        switch (static_cast<error_code>(ev))
        {
        case error_code::success:
            return "Success";
            break;
        case error_code::network_error:
            return "Newwork error";
            break;
        case error_code::file_error:
            return "File error";
            break;
        default:
            return "Unkown error";
            break;
        }
    }
};

[[nodiscard]] BASIC_PROJECT_EXPORT error_category const& get_error_category() noexcept;

inline std::error_code make_error_code(error_code ec) noexcept
{
    return {static_cast<int>(ec), get_error_category()};
}

BASIC_PROJECT_END_NAMESPACE

template <>
struct std::is_error_code_enum<BASIC_PROJECT_namespace::error_code> : public std::true_type
{
};
