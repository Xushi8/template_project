// #include <boost/asio.hpp>
// #include <boost/unordered/unordered_flat_map.hpp>
// #include <boost/unordered/unordered_flat_set.hpp>
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_hash.hpp>
// #include <chrono>
// #include <fmt/format.h>
// #include <numeric>
// #include <random>
// #include <unordered_set>
// #include <execution>
// using namespace std::chrono_literals;
// namespace asio = boost::asio;
// using fmt::print;

// template <typename F>
// std::chrono::duration<double, std::milli> time_test(F&& f)
// {
// 	auto first = std::chrono::steady_clock::now();
// 	f();
// 	auto last = std::chrono::steady_clock::now();
// 	return last - first;
// }

// int main()
// {
// 	// std::chrono::duration<double, std::milli> tim;
// 	// constexpr size_t n = 100000;
// 	// tim = time_test([]()
// 	// 	{
// 	// 		boost::unordered_flat_set<boost::uuids::uuid> st(n);
// 	// 		// std::unordered_set<boost::uuids::uuid> st;
// 	// 		boost::uuids::random_generator ge;
// 	// 		for (size_t i = 0; i < n; i++)
// 	// 		{
// 	// 			st.emplace(ge());
// 	// 		}
// 	// 	});

// 	// print("{:.3f}ms\n", tim.count());

// 	// tim = time_test([]()
// 	// 	{
// 	// 		boost::unordered_flat_set<boost::uuids::uuid> st(n);
// 	// 		// std::unordered_set<boost::uuids::uuid> st;
// 	// 		// boost::uuids::random_generator ge;
// 	// 		boost::uuids::random_generator_pure ge;
// 	// 		for (size_t i = 0; i < n; i++)
// 	// 		{
// 	// 			st.emplace(ge());
// 	// 		}
// 	// 	});

// 	// print("{:.3f}ms\n", tim.count());

// 	// tim = time_test([]()
// 	// 	{
// 	// 		boost::unordered_flat_set<boost::uuids::uuid> st(n);
// 	// 		// std::unordered_set<boost::uuids::uuid> st;
// 	// 		// boost::uuids::random_generator ge;
// 	// 		// boost::uuids::random_generator_pure ge;
// 	// 		boost::uuids::random_generator_mt19937 ge;
// 	// 		for (size_t i = 0; i < n; i++)
// 	// 		{
// 	// 			st.emplace(ge());
// 	// 		}
// 	// 	});

// 	// print("{:.3f}ms\n", tim.count());

// 	// asio::io_context ctx;
// 	// asio::steady_timer timer{ctx, 500ms};
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 1\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 2\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 3\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 4\n");
// 	// 		}
// 	// 	});
// 	// timer.async_wait([](std::error_code ec)
// 	// 	{
// 	// 		if (!ec)
// 	// 		{
// 	// 			print("timer 5\n");
// 	// 		}
// 	// 	});
// 	// timer.cancel();
// 	// ctx.run();

// 	constexpr int n = 1000000;
// 	std::vector<int64_t> a(n);
// 	constexpr size_t seed = 1331;
// 	std::mt19937_64 rng(seed);
// 	std::generate(a.begin(), a.end(), rng);
// 	auto b = a;
// 	std::shuffle(a.begin(), a.end(), rng);
// 	std::shuffle(b.begin(), b.end(), rng);
// 	boost::unordered_flat_map<int64_t, int64_t> mp(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		mp.try_emplace(a[i], b[i]);
// 	}

// 	auto query = b;
// 	std::shuffle(query.begin(), query.end(), rng);
// 	for (int t = 0; t < 100; t++)
// 	{
// 		__int128_t total = 0;
// 		auto tim = time_test([&]
// 			{
// 				for (auto key : query)
// 				{
// 					total += mp[key];
// 				}
// 			});
// 		if (t > 95)
// 		{
// 			print("t: {}, total: {}, elapsed: {:.3f}ms\n", t, total, tim.count());
// 		}
// 	}
// }

#include <expected>
#include <system_error>
#include <xxhash/xxhash.hpp>
#include <fmt/format.h>
#include <fstream>
using fmt::print;

std::expected<int, std::error_code> sqrfloor(int x)
{
	if (x < 1)
	{
		std::ifstream ifs("a.txt");
		return std::unexpected{std::make_error_code(static_cast<std::errc>(errno))};
	}
	return 1;
}

int main()
{
	auto x = sqrfloor(0);
	if (x.has_value())
	{
		print("great\n");
	}
	else
	{
		print("bad\n{}\n", x.error().message());
		throw std::system_error(x.error(), "main");
	}

	print("{}\n", __cpp_concepts);
}
