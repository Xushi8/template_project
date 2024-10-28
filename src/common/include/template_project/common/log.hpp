#pragma once

#include <template_project/common/common.hpp>
#include <template_project/common/literals.hpp>
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>

BASIC_PROJECT_BEGIN_NAMESPACE

struct log_options
{
    spdlog::level::level_enum level = spdlog::level::info;
    std::string log_name{};  // NOLINT(readability-redundant-member-init)
    std::string file_path{}; // NOLINT(readability-redundant-member-init)
    bool with_time = true;
};

inline void set_default_log(const log_options& opts)
{
    spdlog::init_thread_pool(8192, 1);
    auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    stdout_sink->set_level(spdlog::level::trace);
    std::vector<spdlog::sink_ptr> sinks{stdout_sink};

    // file
    if (!opts.file_path.empty())
    {
        using namespace basic_namespace::literals;
        auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(opts.file_path, 10_MiB, 3);
        rotating_sink->set_level(spdlog::level::trace);
        sinks.emplace_back(rotating_sink);
    }

    auto logger = std::make_shared<spdlog::async_logger>(opts.log_name, sinks.begin(), sinks.end(), spdlog::thread_pool());
    logger->set_level(opts.level);

    std::string pattern;
    pattern.append(R"(%^)"); // 开始颜色设置

    // 设置时间
    if (opts.with_time)
    {
        pattern.append(R"([%Y-%m-%d %H:%M:%S.%e] )"); // 时间部分
    }

    // 设置日志名称
    if (!opts.log_name.empty())
    {
        pattern.append(R"([%n] )"); // 日志名称部分
    }

    // 设置日志级别颜色和消息
    pattern.append(R"([%^%l%$] %v)"); // 日志级别部分添加颜色

    logger->set_pattern(pattern);

    spdlog::set_default_logger(logger);

    using namespace std::chrono_literals;
    spdlog::flush_every(1s);
    spdlog::flush_on(spdlog::level::warn);
}

BASIC_PROJECT_END_NAMESPACE
