#include <template_project/log.hpp>
#include <template_project/hash.hpp>
#include <array>
#include <vector>
#include <fmt/core.h>
#include <cstdint>
#include <pqxx/pqxx>
#include <string_view>
#include <string>
#include <template_project/base64.hpp>
#include <template_project/flatbuffers.hpp>
#include <template_project/error_code.hpp>
#include <template_project/multiprecision.hpp>
#include <re2/re2.h>

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
	if (!hash_val.has_value())
	{
		print("/media/tom/Data/test.txt error: {}\n", strerror(errno));
	}
	else
	{
		print("{:x}\n", *hash_val);
	}

	auto val1 = hash_from_file_both("./.gitignore");
	if (!val1.has_value())
	{
		print("./.gitignore error: {}\n", strerror(errno));
	}
	else
	{
		print("{}\n", val1->first);
	}
	constexpr uint64_t x = 0xf74f53b60490421c;
	constexpr uint64_t y = 0x1c429004b6534ff7;
	print("{}\n{}\n", x, y);

	std::array<int, 4> arr = {0, 0, 0, 0};
	hash_val = xxh::xxhash3<64>(arr);
	print("{}\n", *hash_val);

	std::vector<int> vec = {0, 0, 0, 0};
	hash_val = xxh::xxhash3<64>(vec);
	print("{}\n", *hash_val);

	std::vector<char> vec1(16, 'a');
	hash_val = xxh::xxhash3<64>(vec1);
	print("{}\n", *hash_val);
}

} // namespace basic_namespace

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	// basic_namespace::set_default_log("template_project", "logs/mylog.txt", spdlog::level::info);

	// basic_namespace::test_spdlog();

	basic_namespace::test_xxhash();

	// // pqxx::connection C;

	// std::string s = "hello world";
	// s = basic_namespace::base64_encode(s.data(), s.size());
	// fmt::print("{}\n", s);
	// s = basic_namespace::base64_decode(s.data(), s.size());
	// fmt::print("{}\n", s);

	basic_namespace::test_error_code();

	pqxx::connection C("dbname=test_db user=tom password=tom hostaddr=::1 port=5432");
	if (C.is_open())
	{
		pqxx::work W(C);
		fmt::print("db connect true\n");
	}
	else
	{
		fmt::print("db connect false\n");
	}

	std::string text = "My emails are first@example.com, second@example.com, and third@example.com.";
	std::string pattern = R"((\w+@\w+\.\w+))"; // 正则表达式模式
	RE2 re(pattern);

	re2::StringPiece input(text);
	std::string email;

	while (RE2::FindAndConsume(&input, re, &email))
	{
		// std::cout << "Found email: " << email << std::endl;
		fmt::print("Found email: {}\n", email);
	}

	basic_namespace::test_multiprecision();

	// basic_namespace::test_flatbuffers();

	return 0;
}
