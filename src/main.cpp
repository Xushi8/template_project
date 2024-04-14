#include <fmt/core.h>
#include <boost/asio.hpp>
using fmt::print;

boost::asio::awaitable<void> listener()
{
	auto executor = co_await boost::asio::this_coro::executor;
	boost::asio::ip::tcp::acceptor acceptor(executor, {boost::asio::ip::tcp::v6(), 10086});
}

int main()
{
	try
	{
		boost::asio::io_context ctx;
		boost::asio::signal_set signals(ctx, SIGINT, SIGTERM);
		signals.async_wait([&](auto, auto)
			{
				ctx.stop();
			});

		co_spawn(ctx, listener(), boost::asio::detached);
	}
	catch (std::exception const& e)
	{
		print(stderr, "Exception is: {}\n", e.what());
	}

	return 0;
}