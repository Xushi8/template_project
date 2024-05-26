#include <xxhash/xxhash.hpp>
#include <string_view>
#include <cstdint>

namespace basic_namespace
{
uint64_t hash_from_file(std::string_view file_name);

uint64_t hash_from_file64(std::string_view file_name);

xxh::hash_t<128> hash_from_file128(std::string_view file_name);
} // namespace basic_namespace
