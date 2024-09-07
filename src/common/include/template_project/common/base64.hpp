#pragma once

#include <string_view>
#include <string>
#include <cstddef>

#include <template_project/common/common.hpp>

BASIC_BEGIN_NAMESPACE
BASIC_EXPORT
std::string base64_encode(std::string_view input);
BASIC_EXPORT
std::string base64_encode(const void* input, const size_t len);

BASIC_EXPORT
std::string base64_decode(std::string_view input);
BASIC_EXPORT
std::string base64_decode(const char* input, const size_t len);
BASIC_END_NAMESPACE