#include <util/log.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>
#include <string>

namespace basic_namespace
{
using std::string_view;
using std::string;

/**
 * @brief Set the default log object, this should be called during initialization(the first line of main).
 *
 * @param log_name
 * @param level
 * @param log_path
 */
void set_default_log(string const& log_name, string const& log_path, spdlog::level::level_enum level)
{
	spdlog::init_thread_pool(8192, 1);
	auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(string(log_path), size_t(1024) * 1024 * 10, 3);
	stdout_sink->set_level(spdlog::level::trace);
	rotating_sink->set_level(spdlog::level::trace);
	std::vector<spdlog::sink_ptr> sinks{stdout_sink, rotating_sink};
	auto logger = std::make_shared<spdlog::async_logger>(string(log_name), sinks.begin(), sinks.end(), spdlog::thread_pool());
	logger->set_level(level);
	spdlog::set_default_logger(logger);

	using namespace std::chrono_literals;
	spdlog::flush_every(1s);
	spdlog::flush_on(spdlog::level::warn);
}

void change_default_log_level(spdlog::level::level_enum level)
{
	spdlog::default_logger()->set_level(level);
}
} // namespace basic_namespace
