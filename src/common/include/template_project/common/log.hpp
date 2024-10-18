#pragma once

#include <template_project/common/common.hpp>
#include <template_project/common/literals.hpp>
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>

BASIC_PROJECT_BEGIN_NAMESPACE

inline void set_default_log(spdlog::level::level_enum level = spdlog::level::info, std::string const& log_path = "./logs/log.txt", std::string const& log_name = "basic_namespace")
{
    spdlog::init_thread_pool(8192, 1);
    auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    using namespace basic_namespace::literals;
    auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_path, 10_MiB, 3);
    stdout_sink->set_level(spdlog::level::trace);
    rotating_sink->set_level(spdlog::level::trace);
    std::vector<spdlog::sink_ptr> sinks{stdout_sink, rotating_sink};
    auto logger = std::make_shared<spdlog::async_logger>(log_name, sinks.begin(), sinks.end(), spdlog::thread_pool());
    logger->set_level(level);
    spdlog::set_default_logger(logger);

    using namespace std::chrono_literals;
    spdlog::flush_every(1s);
    spdlog::flush_on(spdlog::level::warn);
}

inline void change_default_log_level(spdlog::level::level_enum level)
{
    spdlog::default_logger()->set_level(level);
}

BASIC_PROJECT_END_NAMESPACE
