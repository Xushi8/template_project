#pragma once

#include <string>
#include <spdlog/spdlog.h>

namespace basic_namespace
{
void set_default_log(std::string const& log_path = "./logs/log.txt", std::string const& log_name = "basic_namespace", spdlog::level::level_enum level = spdlog::level::info);

void change_default_log_level(spdlog::level::level_enum level);
} // namespace basic_namespace
