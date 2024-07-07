#pragma once

#include <string_view>
#include <string>
#include <cstddef>

namespace basic_namespace
{
std::string base64_encode(std::string_view input);
std::string base64_encode(const void* input, const size_t len);

std::string base64_decode(std::string_view input);
std::string base64_decode(const char* input, const size_t len);
} // namespace basic_namespace
