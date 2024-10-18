#pragma once
#include <cassert>
#include <template_project/common/common.hpp>
#include <cstdint>

BASIC_PROJECT_BEGIN_NAMESPACE

namespace literals
{

constexpr uint64_t operator""_KiB(unsigned long long x)
{
    return static_cast<uint64_t>(x) * 1024;
}

constexpr uint64_t operator""_MiB(unsigned long long x)
{
    return 1024_KiB * x;
}

constexpr uint64_t operator""_GiB(unsigned long long x)
{
    return 1024_MiB * x;
}

constexpr uint64_t operator""_TiB(unsigned long long x)
{
    return 1024_GiB * x;
}

constexpr uint64_t operator""_PiB(unsigned long long x)
{
    return 1024_TiB * x;
}

constexpr uint64_t operator""_KB(unsigned long long x)
{
    return static_cast<uint64_t>(x) * 1000;
}

constexpr uint64_t operator""_MB(unsigned long long x)
{
    return 1000_KB * x;
}

constexpr uint64_t operator""_GB(unsigned long long x)
{
    return 1000_MB * x;
}

constexpr uint64_t operator""_TB(unsigned long long x)
{
    return 1000_GB * x;
}

constexpr uint64_t operator""_PB(unsigned long long x)
{
    return 1000_TB * x;
}

constexpr uint64_t operator""_KiB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024 * x);
}

constexpr uint64_t operator""_MiB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_KiB * x);
}

constexpr uint64_t operator""_GiB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_MiB * x);
}

constexpr uint64_t operator""_TiB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_GiB * x);
}

constexpr uint64_t operator""_PiB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_TiB * x);
}

constexpr uint64_t operator""_KB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(100 * x);
}

constexpr uint64_t operator""_MB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_KB * x);
}

constexpr uint64_t operator""_GB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_MB * x);
}

constexpr uint64_t operator""_TB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_GB * x);
}

constexpr uint64_t operator""_PB(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_TB * x);
}

} // namespace literals

BASIC_PROJECT_END_NAMESPACE