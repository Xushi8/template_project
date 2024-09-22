#include <template_project/common/common.hpp>
#include <cstddef>
#include <vector>
#include <random>
#include <algorithm>
#include <array>
#include <fstream>
#include <fmt/format.h>
using fmt::print;
using namespace std;
int main()
{
	constexpr size_t N = 1e9;
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> uni;
	std::vector<int> a(N);
	std::generate_n(a.begin(), N, [&]
		{
			return uni(rng);
		});
	ofstream ofs("a.txt");
	ofs.write(reinterpret_cast<const char*>(a.data()), sizeof(int) * N);
}
