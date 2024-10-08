#include <template_project/common/common.hpp>
#include <cstddef>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <fmt/format.h>
using namespace std;
int main()
{
    constexpr size_t N = (1 << 30);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> uni(numeric_limits<int>::min(), numeric_limits<int>::max());
    std::vector<int> a(N);
    std::generate_n(a.begin(), N, [&]
        {
            return uni(rng);
        });
    ofstream ofs("in.txt");
    ofs.write(reinterpret_cast<const char*>(a.data()), sizeof(int) * N);
}
