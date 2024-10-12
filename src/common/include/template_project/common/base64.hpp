#pragma once

#include <string_view>
#include <cstddef>
#include <boost/container/string.hpp>
#include <template_project/common/common.hpp>
#include <boost/beast/core/detail/base64.hpp>

BASIC_PROJECT_BEGIN_NAMESPACE

inline boost::container::string base64_encode(std::string_view input)
{
    const std::size_t len = input.size();
    boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
    output.resize(boost::beast::detail::base64::encode(output.data(), input.data(), len), boost::container::default_init);
    return output;
}
inline boost::container::string base64_encode(const void* input, size_t len)
{
    boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
    output.resize(boost::beast::detail::base64::encode(output.data(), input, len), boost::container::default_init);
    return output;
}

inline boost::container::string base64_decode(std::string_view input)
{
    const std::size_t len = input.size();
    boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
    auto result = boost::beast::detail::base64::decode(output.data(), input.data(), len);
    output.resize(result.first, boost::container::default_init);
    return output;
}

inline boost::container::string base64_decode(const char* input, size_t len)
{
    boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
    auto result = boost::beast::detail::base64::decode(output.data(), input, len);
    output.resize(result.first, boost::container::default_init);
    return output;
}

BASIC_PROJECT_END_NAMESPACE
