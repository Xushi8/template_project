#pragma once
#include <template_project/common/common.hpp>
#include <cassert>
#include <cstdint>

BASIC_PROJECT_BEGIN_NAMESPACE

namespace literals
{

constexpr uint64_t operator""_kib(unsigned long long x)
{
    return static_cast<uint64_t>(x) * 1024;
}

constexpr uint64_t operator""_mib(unsigned long long x)
{
    return 1024_kib * x;
}

constexpr uint64_t operator""_gib(unsigned long long x)
{
    return 1024_mib * x;
}

constexpr uint64_t operator""_tib(unsigned long long x)
{
    return 1024_gib * x;
}

constexpr uint64_t operator""_pib(unsigned long long x)
{
    return 1024_tib * x;
}

constexpr uint64_t operator""_kb(unsigned long long x)
{
    return static_cast<uint64_t>(x) * 1000;
}

constexpr uint64_t operator""_mb(unsigned long long x)
{
    return 1000_kb * x;
}

constexpr uint64_t operator""_gb(unsigned long long x)
{
    return 1000_mb * x;
}

constexpr uint64_t operator""_tb(unsigned long long x)
{
    return 1000_gb * x;
}

constexpr uint64_t operator""_pb(unsigned long long x)
{
    return 1000_tb * x;
}

constexpr uint64_t operator""_kib(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024 * x);
}

constexpr uint64_t operator""_mib(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_kib * x);
}

constexpr uint64_t operator""_gib(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_mib * x);
}

constexpr uint64_t operator""_tib(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_gib * x);
}

constexpr uint64_t operator""_pib(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1024_tib * x);
}

constexpr uint64_t operator""_kb(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(100 * x);
}

constexpr uint64_t operator""_mb(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_kb * x);
}

constexpr uint64_t operator""_gb(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_mb * x);
}

constexpr uint64_t operator""_tb(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_gb * x);
}

constexpr uint64_t operator""_pb(long double x)
{
    assert(x >= 0.L);
    return static_cast<uint64_t>(1000_tb * x);
}

} // namespace literals

BASIC_PROJECT_END_NAMESPACE
