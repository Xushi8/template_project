#pragma once

#include <xxhash/xxhash.hpp>
#include <string_view>
#include <utility>
#include <mio/mio.hpp>
#include <system_error>
#include <tl/expected.hpp>

#include <template_project/common/common.hpp>
#include <template_project/common/literals.hpp>

BASIC_PROJECT_BEGIN_NAMESPACE

template <size_t N = 64>
inline tl::expected<xxh::hash_t<N>, std::error_code> hash_from_file(std::string_view file_name)
{
    std::error_code ec;
    auto file = mio::make_mmap_source(file_name, ec);
    if (ec)
    {
        return tl::unexpected(ec);
    }
    xxh::hash3_state_t<64> hash_stream;
    hash_stream.update(file.begin(), file.end());
    return hash_stream.digest();
}

inline tl::expected<std::pair<xxh::hash_t<64>, xxh::hash_t<128>>, std::error_code> hash_from_file_both(std::string_view file_name)
{
    std::error_code ec;
    auto file = mio::make_mmap_source(file_name, ec);
    if (ec)
    {
        return tl::unexpected(ec);
    }
    xxh::hash3_state_t<64> hash_stream1;
    xxh::hash3_state_t<128> hash_stream2;
    using namespace basic_namespace::literals;
    static constexpr size_t hash_buffer_size = 64_KiB;
    for (size_t now = 0; now < file.size(); now += hash_buffer_size)
    {
        size_t adds = std::min(file.size() - now, hash_buffer_size);
        hash_stream1.update(file.begin() + now, adds);
        hash_stream2.update(file.begin() + now, adds);
    }
    return std::make_pair(hash_stream1.digest(), hash_stream2.digest());
}
BASIC_PROJECT_END_NAMESPACE
