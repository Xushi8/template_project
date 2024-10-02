#pragma once

#include <string_view>
#include <cstddef>
#include <boost/container/string.hpp>
#include <template_project/common/common.hpp>

BASIC_BEGIN_NAMESPACE
BASIC_EXPORT
boost::container::string base64_encode(std::string_view input);
BASIC_EXPORT
boost::container::string base64_encode(const void* input, size_t len);

BASIC_EXPORT
boost::container::string base64_decode(std::string_view input);
BASIC_EXPORT
boost::container::string base64_decode(const char* input, size_t len);
BASIC_END_NAMESPACE
