// #include <mimalloc-new-delete.h>
// #include <fmt/core.h>
// #include <asio/asio.hpp>
// using fmt::print;

// asio::awaitable<void> listener()
// {
// 	auto executor = co_await asio::this_coro::executor;
// 	asio::ip::tcp::acceptor acceptor(executor, {asio::ip::tcp::v6(), 10086});
// }

// int main()
// {
// 	try
// 	{
// 		asio::io_context ctx;
// 		asio::signal_set signals(ctx, SIGINT, SIGTERM);
// 		signals.async_wait([&](auto, auto)
// 			{
// 				ctx.stop();
// 			});

// 		co_spawn(ctx, listener(), asio::detached);
// 		ctx.run();
// 	}
// 	catch (std::exception const& e)
// 	{
// 		print(stderr, "Exception is: {}\n", e.what());
// 	}

// 	return 0;
// }

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>

int main()
{
	// spdlog::info("Welcome to spdlog!");
	// spdlog::error("Some error message with arg: {}", 1);
	// spdlog::warn("Easy padding in numbers like {:08d}", 12);
	// spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);

	// auto my_logger = spdlog::rotating_logger_mt("rotating_logger", "logs/rotating-log.txt", 1024 * 1024 * 5, 3);
	// my_logger->info("spdlog is very easy to use!");

	// auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	// console_sink->set_level(spdlog::level::warn);
	// auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/multisink.txt", 1024 * 1024 * 5, 3);
	// file_sink->set_level(spdlog::level::debug);

	// spdlog::logger logger("multi_sink", {console_sink, file_sink});
	// logger.set_level(spdlog::level::debug);
	// spdlog::set_default_logger(std::make_shared<spdlog::logger>(std::move(logger)));

	// // logger.warn("this should appear in both console and file");
	// // logger.info("this should only appear in file");

	// spdlog::default_logger()->warn("this should appear in both console and file");
	// spdlog::default_logger()->info("this should only appear in file");

	spdlog::init_thread_pool(8192, 1);
	auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/mylog.txt", 1024 * 1024 * 10, 3);
	stdout_sink->set_level(spdlog::level::warn);
	rotating_sink->set_level(spdlog::level::trace);
	std::vector<spdlog::sink_ptr> sinks{stdout_sink, rotating_sink};
	auto logger = std::make_shared<spdlog::async_logger>("loggername", sinks.begin(), sinks.end(), spdlog::thread_pool());
	logger->set_level(spdlog::level::debug);
	spdlog::set_default_logger(logger);

	spdlog::default_logger()->warn("this should appear in both console and file");
	spdlog::default_logger()->info("this should only appear in file");
	spdlog::default_logger()->trace("this should not appear");

	return 0;
}