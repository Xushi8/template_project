#pragma once

#include <template_project/common/common.hpp>
#include <string>
#include <system_error>
#include <cstddef>

BASIC_BEGIN_NAMESPACE
std::error_code create_reserve_file(std::string const& file_name, size_t len);
BASIC_END_NAMESPACE