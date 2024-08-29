#include <fstream>
#include <cstddef>
#include <vector>
using namespace std;
int main()
{
	constexpr size_t n = 1e9;
	vector<size_t> a(n, 654596146489);
	ofstream ofs("a.txt");
	ofs.write(reinterpret_cast<const char*>(a.data()), sizeof(size_t) * n);
}