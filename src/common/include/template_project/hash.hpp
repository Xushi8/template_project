#pragma once

#include <xxhash/xxhash.hpp>
#include <string_view>
#include <string>
#include <fstream>
#include <array>
#include <optional>
#include <utility>
#include <expected>

#include <template_project/common.hpp>

BASIC_BEGIN_NAMESPACE
static constexpr size_t hash_buffer_size = 64 * 1024;

template <size_t N = 64>
inline std::expected<xxh::hash_t<N>, std::error_code> hash_from_file(std::string file_name)
{
	std::ifstream ifs(file_name);
	if (ifs.fail()) [[unlikely]]
	{
		// perror("hash_from_file");
		// return std::nullopt;
		std::unexpected{std::make_error_code(static_cast<std::errc>(errno))};
	}
	ifs.seekg(0, std::ios::end);
	const size_t n = static_cast<size_t>(ifs.tellg()) / sizeof(char);
	ifs.seekg(0);
	xxh::hash3_state_t<N> hash_stream;
	size_t now_size = 0;
	std::array<char, hash_buffer_size> buf;
	while (now_size < n)
	{
		size_t adds = std::min(n - now_size, hash_buffer_size);
		now_size += adds;
		ifs.read(buf.data(), static_cast<std::streamsize>(adds));
		hash_stream.update(buf.data(), adds);
	}
	return hash_stream.digest();
}

inline std::expected<std::pair<xxh::hash_t<64>, xxh::hash_t<128>>, std::error_code> hash_from_file_both(std::string file_name)
{
	std::ifstream ifs(file_name);
	if (ifs.fail()) [[unlikely]]
	{
		// perror("hash_from_file");
		// return std::nullopt;
		std::unexpected{std::make_error_code(static_cast<std::errc>(errno))};
	}
	ifs.seekg(0, std::ios::end);
	const size_t n = static_cast<size_t>(ifs.tellg()) / sizeof(char);
	ifs.seekg(0);
	xxh::hash3_state_t<64> hash_stream1;
	xxh::hash3_state_t<128> hash_stream2;
	size_t now_size = 0;
	std::array<char, hash_buffer_size> buf;
	while (now_size < n)
	{
		size_t adds = std::min(n - now_size, hash_buffer_size);
		now_size += adds;
		ifs.read(buf.data(), static_cast<std::streamsize>(adds));
		hash_stream1.update(buf.data(), adds);
		hash_stream2.update(buf.data(), adds);
	}
	return std::make_pair(hash_stream1.digest(), hash_stream2.digest());
}
BASIC_END_NAMESPACE
