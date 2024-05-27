#include <xxhash/xxhash.hpp>
#include <string_view>
#include <cstdint>
#include <utility>
#include <functional>

namespace basic_namespace
{
uint64_t hash_from_file(std::string_view file_name);

uint64_t hash_from_file64(std::string_view file_name);

xxh::hash_t<128> hash_from_file128(std::string_view file_name);

template <typename T>
struct hash;

template <typename T>
	// requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
struct hash
{
	constexpr size_t operator()(T const& val) const noexcept
	{
		if constexpr (SIZE_MAX == 0xffffffffffffffff)
			return xxh::xxhash3<64>(&val, sizeof(val));
		else
			return xxh::xxhash<32>(&val, sizeof(val));
	}
};

} // namespace basic_namespace
