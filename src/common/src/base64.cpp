#include <template_project/common/base64.hpp>
#include <template_project/common/common.hpp>
#include <boost/beast/core/detail/base64.hpp>
#include <boost/container/string.hpp>

BASIC_BEGIN_NAMESPACE

namespace container = boost::container;
using namespace boost::beast::detail::base64;

container::string base64_encode(std::string_view input)
{
	const std::size_t len = input.size();
	container::string output(encoded_size(len), container::default_init);
	output.resize(encode(output.data(), input.data(), len), container::default_init);
	return output;
}

container::string base64_encode(const void* input, size_t len)
{
	container::string output(encoded_size(len), container::default_init);
	output.resize(encode(output.data(), input, len), container::default_init);
	return output;
}

container::string base64_decode(std::string_view input)
{
	const std::size_t len = input.size();
	container::string output(encoded_size(len), container::default_init);
	auto result = decode(output.data(), input.data(), len);
	output.resize(result.first, container::default_init);
	return output;
}

container::string base64_decode(const char* input, size_t len)
{
	container::string output(encoded_size(len), container::default_init);
	auto result = decode(output.data(), input, len);
	output.resize(result.first, container::default_init);
	return output;
}
BASIC_END_NAMESPACE