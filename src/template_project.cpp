#include <util/log.hpp>
#include <util/hash.hpp>
#include <array>
#include <vector>
#include <fmt/core.h>
#include <cstdint>
// #include <pqxx/pqxx>
#include <string_view>
#include <string>
#include <util/base64.hpp>
#include <util/flatbuffers.hpp>
#include <common/error_code.hpp>

namespace basic_namespace
{
using u64 = uint64_t;
using fmt::print;

void test_spdlog()
{
	spdlog::info("info log");
	spdlog::warn("warn log");
}

void test_xxhash()
{
	std::optional<xxh::hash_t<64>> hash_val = hash_from_file("/media/tom/Data/test.txt");
	print("{:x}\n", *hash_val);
	constexpr uint64_t x = 0xf74f53b60490421c;
	constexpr uint64_t y = 0x1c429004b6534ff7;
	print("{}\n{}\n", x, y);

	std::array<int, 4> arr = {0, 0, 0, 0};
	hash_val = xxh::xxhash3(arr);
	print("{}\n", *hash_val);

	std::vector<int> vec = {0, 0, 0, 0};
	hash_val = xxh::xxhash3(vec);
	print("{}\n", *hash_val);

	std::vector<char> vec1(16, 'a');
	hash_val = xxh::xxhash3(vec1);
	print("{}\n", *hash_val);
}

} // namespace basic_namespace

int main()
{
	basic_namespace::set_default_log("template_project", "logs/mylog.txt", spdlog::level::info);

	basic_namespace::test_spdlog();

	basic_namespace::test_xxhash();

	// pqxx::connection C;

	std::string s = "hello world";
	s = basic_namespace::base64_encode(s.data(), s.size());
	fmt::print("{}\n", s);
	s = basic_namespace::base64_decode(s.data(), s.size());
	fmt::print("{}\n", s);

	basic_namespace::test_error_code();

	// basic_namespace::test_flatbuffers();

	return 0;
}
