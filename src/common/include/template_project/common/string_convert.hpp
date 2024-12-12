#pragma once

#include <template_project/common/common.hpp>
#include <charconv>
#include <optional>
#include <string_view>

BASIC_PROJECT_BEGIN_NAMESPACE

template <typename T>
    requires std::integral<T> || std::floating_point<T>
constexpr std::optional<T> from_string(std::string_view s, int base = 10) noexcept
{
    T res;
    if constexpr (std::is_integral_v<T>)
    {
        // 对于整数类型，使用 base 参数
        auto result = std::from_chars(s.data(), s.data() + s.size(), res, base);
        if (result.ec == std::errc{}) [[likely]]
        {
            return res;
        }
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        // 对于浮点类型，忽略 base 参数（std::from_chars 不支持非十进制浮点解析）
        auto result = std::from_chars(s.data(), s.data() + s.size(), res);
        if (result.ec == std::errc{} && result.ptr == s.data() + s.size()) [[likely]]
        {
            return res;
        }
    }

    return std::nullopt;
}

BASIC_PROJECT_END_NAMESPACE