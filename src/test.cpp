#include <boost/unordered/unordered_flat_set.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_hash.hpp>
#include <chrono>
#include <fmt/format.h>
#include <unordered_set>
using fmt::print;

template <typename F>
std::chrono::duration<double, std::milli> time_test(F&& f)
{
	auto first = std::chrono::steady_clock::now();
	f();
	auto last = std::chrono::steady_clock::now();
	return last - first;
}

int main()
{
	std::chrono::duration<double, std::milli> tim;
	constexpr size_t n = 100000;
	tim = time_test([]()
		{
			boost::unordered_flat_set<boost::uuids::uuid> st(n);
			// std::unordered_set<boost::uuids::uuid> st;
			boost::uuids::random_generator ge;
			for (size_t i = 0; i < n; i++)
			{
				st.emplace(ge());
			}
		});

	print("{:.3f}ms\n", tim.count());

	tim = time_test([]()
		{
			boost::unordered_flat_set<boost::uuids::uuid> st(n);
			// std::unordered_set<boost::uuids::uuid> st;
			// boost::uuids::random_generator ge;
			boost::uuids::random_generator_pure ge;
			for (size_t i = 0; i < n; i++)
			{
				st.emplace(ge());
			}
		});

	print("{:.3f}ms\n", tim.count());

	tim = time_test([]()
		{
			boost::unordered_flat_set<boost::uuids::uuid> st(n);
			// std::unordered_set<boost::uuids::uuid> st;
			// boost::uuids::random_generator ge;
			// boost::uuids::random_generator_pure ge;
			boost::uuids::random_generator_mt19937 ge;
			for (size_t i = 0; i < n; i++)
			{
				st.emplace(ge());
			}
		});

	print("{:.3f}ms\n", tim.count());
}