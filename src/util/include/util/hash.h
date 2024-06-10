#pragma once

#include <xxhash/xxhash.hpp>
#include <string_view>
#include <fstream>
#include <array>

namespace basic_namespace
{
static constexpr size_t hash_buffer_size = 64 * 1024;

template <size_t N = 128>
xxh::hash_t<N> hash_from_file(std::string_view file_name)
{
	xxh::hash3_state_t<N> hash_stream;
	std::ifstream ifs(file_name.data());
	if (ifs.fail()) [[unlikely]]
	{
		perror("hash_from_file128");
		return {};
	}
	ifs.seekg(0, std::ios::end);
	const size_t n = static_cast<size_t>(ifs.tellg()) / sizeof(char);
	ifs.seekg(0);
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
