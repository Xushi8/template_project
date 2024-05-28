#include <util/log.h>
#include <util/hash.h>
#include <array>
#include <vector>
#include <fmt/core.h>
#include <cstdint>
#include <pqxx/pqxx>
#include <string_view>
#include <string>
#include <util/base64.h>


namespace basic_namespace
{
using u64 = uint64_t;
using fmt::print;

void test_spdlog()
{
	spdlog::warn("warn log");
	spdlog::info("info log");
}

void test_xxhash()
{
	u64 hash_val = hash_from_file("/media/tom/Data/test.txt");
	print("{:x}\n", hash_val);
	constexpr uint64_t x = 0xf74f53b60490421c;
	constexpr uint64_t y = 0x1c429004b6534ff7;
	print("{}\n{}\n", x, y);

	std::array<int, 4> arr = {0, 0, 0, 0};
	hash_val = xxh::xxhash3(arr);
	print("{}\n", hash_val);

	std::vector<int> vec = {0, 0, 0, 0};
	hash_val = xxh::xxhash3(vec);
	print("{}\n", hash_val);

	std::vector<char> vec1(16, 'a');
	hash_val = xxh::xxhash3(vec1);
	print("{}\n", hash_val);
}

} // namespace basic_namespace

int main()
{
	basic_namespace::set_default_log("template_project", spdlog::level::info, "logs/mylog.txt");

	basic_namespace::test_xxhash();

	// pqxx::connection C;

	std::string s = "hello world";
	s = basic_namespace::base64_encode(s.data(), s.size());
	fmt::print("{}\n", s);
	s = basic_namespace::base64_decode(s.data(), s.size());
	fmt::print("{}\n", s);

	return 0;
}
