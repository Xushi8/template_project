#pragma once

#include <string_view>
#include <spdlog/spdlog.h>

namespace basic_namespace
{
void set_default_log(std::string_view log_name, std::string_view log_path, spdlog::level::level_enum level = spdlog::level::info);

void change_default_log_level(spdlog::level::level_enum level);
} // namespace basic_namespace
