#include <template_project/multiprecision.hpp>
#include <fmt/format.h>

#include <template_project/common.hpp>

BASIC_BEGIN_NAMESPACE
using fmt::print;
using namespace boost::multiprecision;
void test_multiprecision()
{
	mpz_int v1("1234567890123456789012345678901234567890");
	mpz_int v2 = v1 << 8;
	print("{}\n", v2.str());
}
BASIC_END_NAMESPACE