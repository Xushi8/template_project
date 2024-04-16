#include <fmt/core.h>
#include <asio.hpp>
using fmt::print;

asio::awaitable<void> listener()
{
	auto executor = co_await asio::this_coro::executor;
	asio::ip::tcp::acceptor acceptor(executor, {asio::ip::tcp::v6(), 10086});
}

int main()
{
	try
	{
		asio::io_context ctx;
		asio::signal_set signals(ctx, SIGINT, SIGTERM);
		signals.async_wait([&](auto, auto)
			{
				ctx.stop();
			});

		co_spawn(ctx, listener(), asio::detached);
		ctx.run();
	}
	catch (std::exception const& e)
	{
		print(stderr, "Exception is: {}\n", e.what());
	}

	return 0;
}