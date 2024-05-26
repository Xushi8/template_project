#include <util/log.h>
#include <util/hash.h>
#include <array>
#include <fmt/core.h>

namespace basic_namespace
{
using fmt::print;

void test_spdlog()
{
	spdlog::warn("warn log");
	spdlog::info("info log");
}

void test_xxhash()
{
	u64 hash_val = hash_from_file("test.txt");
	print("{}\n", hash_val);

	std::array<int, 4> arr = {0, 0, 0, 0};
	hash_val = xxh::xxhash3<64>(arr);
	print("{}\n", hash_val);
}

} // namespace basic_namespace

int main()
{
	basic_namespace::set_default_log("template_project", spdlog::level::info, "logs/mylog.txt");

	basic_namespace::test_xxhash();

	return 0;
}
