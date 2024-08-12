#pragma once

#include <xxhash/xxhash.hpp>
#include <string_view>
#include <string>
#include <fstream>
#include <array>
#include <optional>

namespace basic_namespace
{
static constexpr size_t hash_buffer_size = 64 * 1024;

template <size_t N = 64>
std::optional<xxh::hash_t<N>> hash_from_file(std::string_view file_name)
{
	std::ifstream ifs((std::string(file_name)));
	if (ifs.fail()) [[unlikely]]
	{
		// perror("hash_from_file");
		return std::nullopt;
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

} // namespace basic_namespace
