#include <util/base64.h>
#include <common/common.h>
#include <boost/beast/core/detail/base64.hpp>
#include <boost/container/string.hpp>

namespace basic_namespace
{

std::string base64_encode(std::string_view input)
{
	const std::size_t len = input.size();
	boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
	output.resize(boost::beast::detail::base64::encode(output.data(), input.data(), len), boost::container::default_init);
	return static_cast<std::string>(output);
}

std::string base64_encode(const void* input, const size_t len)
{
	boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
	output.resize(boost::beast::detail::base64::encode(output.data(), input, len), boost::container::default_init);
	return static_cast<std::string>(output);
}

std::string base64_decode(std::string_view input)
{
	const std::size_t len = input.size();
	boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
	auto result = boost::beast::detail::base64::decode(output.data(), input.data(), len);
	output.resize(result.first, boost::container::default_init);
	return static_cast<std::string>(output);
}

std::string base64_decode(const char* input, const size_t len)
{
	boost::container::string output(boost::beast::detail::base64::encoded_size(len), boost::container::default_init);
	auto result = boost::beast::detail::base64::decode(output.data(), input, len);
	output.resize(result.first, boost::container::default_init);
	return static_cast<std::string>(output);
}

} // namespace basic_namespace