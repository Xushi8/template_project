#include <util/hash.h>
#include <cstddef>
#include <fstream>
#include <array>
#include <algorithm>

namespace basic_namespace
{
static constexpr size_t hash_buffer_size = 32 * 1024;

/**
 * @brief
 *
 * @param file_name
 * @return u64
 */
u64 hash_from_file(std::string_view file_name)
{
	xxh::hash3_state_t<64> hash_stream;
	std::ifstream ifs(file_name.data());
	if (ifs.fail()) [[unlikely]]
	{
		perror("hash_from_file");
		return {};
	}
	ifs.seekg(0, std::ios::end);
	const size_t n = ifs.tellg() / sizeof(char);
	ifs.seekg(0);
	size_t now_siz = 0;
	std::array<char, hash_buffer_size> buf;
	while (now_siz < n)
	{
		size_t adds = std::min(n - now_siz, size_t(32) * 1024);
		now_siz += adds;
		ifs.read(buf.data(), adds);
		hash_stream.update(buf);
	}
	return hash_stream.digest();
}

/**
 * @brief
 *
 * @param file_name
 * @return u64
 */
u64 hash_from_file64(std::string_view file_name)
{
	return hash_from_file(file_name);
}

/**
 * @brief
 *
 * @param file_name
 * @return xxh::hash_t<128> which equals xxh::uint128_t
 */
xxh::hash_t<128> hash_from_file128(std::string_view file_name)
{
	xxh::hash3_state_t<128> hash_stream;
	std::ifstream ifs(file_name.data());
	if (ifs.fail()) [[unlikely]]
	{
		perror("hash_from_file128");
		return {};
	}
	ifs.seekg(0, std::ios::end);
	const size_t n = ifs.tellg() / sizeof(char);
	ifs.seekg(0);
	size_t now_siz = 0;
	std::array<char, hash_buffer_size> buf;
	while (now_siz < n)
	{
		size_t adds = std::min(n - now_siz, size_t(32) * 1024);
		now_siz += adds;
		ifs.read(buf.data(), adds);
		hash_stream.update(buf);
	}
	return hash_stream.digest();
}
} // namespace basic_namespace