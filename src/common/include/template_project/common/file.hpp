#pragma once

#include <template_project/common/common.hpp>
#include <string>
#include <system_error>
#include <cstddef>
#include <fstream>

BASIC_PROJECT_BEGIN_NAMESPACE

[[nodiscard]] inline std::error_code create_reserve_file(std::string const& file_name, size_t len)
{
    std::ofstream ofs(file_name);
    if (!ofs) [[unlikely]]
        return std::make_error_code(static_cast<std::errc>(errno));
    if (len == 0) [[unlikely]]
        return {};
    ofs.seekp(len - 1);
    ofs.write("", 1);
    if (!ofs) [[unlikely]]
        return std::make_error_code(static_cast<std::errc>(errno));
    return {};
}

BASIC_PROJECT_END_NAMESPACE