#include <util/log.h>
#include <util/hash.h>
#include <array>
#include <vector>
#include <fmt/core.h>
#include <unordered_set>
#include <random>

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
	hash_val = xxh::xxhash3<64>(arr);
	print("{}\n", hash_val);

	std::vector<int> vec = {0, 0, 0, 0};
	hash_val = xxh::xxhash3<64>(vec);
	print("{}\n", hash_val);

	std::vector<char> vec1(16, 'a');
	hash_val = xxh::xxhash3<64>(vec1);
	print("{}\n", hash_val);
}

void test_xxhash_std()
{
	std::unordered_set<int, hash<int>> st;

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> uni(1, 1000000);
	for (size_t i = 0; i < 1000; i++)
	{
		st.emplace(uni(rng));
	}
}

} // namespace basic_namespace

int main()
{
	basic_namespace::set_default_log("template_project", spdlog::level::info, "logs/mylog.txt");

	basic_namespace::test_xxhash();

	return 0;
}
