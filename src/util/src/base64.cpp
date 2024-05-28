#include <util/base64.h>
#include <boost/beast/core/detail/base64.hpp>

namespace basic_namespace
{
std::string base64_encode(std::string_view input)
{
	const std::size_t len = input.size();
	std::string output;
	output.resize(boost::beast::detail::base64::encoded_size(len));
	output.resize(boost::beast::detail::base64::encode(output.data(), input.data(), len));
	return output;
}

std::string base64_encode(const void* input, const size_t len)
{
	std::string output;
	output.resize(boost::beast::detail::base64::encoded_size(len));
	output.resize(boost::beast::detail::base64::encode(output.data(), input, len));
	return output;
}

std::string base64_decode(std::string_view input)
{
	const std::size_t len = input.size();
	std::string output;
	output.resize(boost::beast::detail::base64::decoded_size(len));
	auto result = boost::beast::detail::base64::decode(output.data(), input.data(), len);
	output.resize(result.first);
	return output;
}

std::string base64_decode(const char* input, const size_t len)
{
	std::string output;
	output.resize(boost::beast::detail::base64::decoded_size(len));
	auto result = boost::beast::detail::base64::decode(output.data(), input, len);
	output.resize(result.first);
	return output;
}

} // namespace basic_namespace