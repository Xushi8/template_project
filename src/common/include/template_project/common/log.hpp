#pragma once

#include <string>
#include <spdlog/spdlog.h>
#include <template_project/common/common.hpp>

BASIC_BEGIN_NAMESPACE
BASIC_EXPORT
void set_default_log(std::string const& log_path = "./logs/log.txt", std::string const& log_name = "basic_namespace", spdlog::level::level_enum level = spdlog::level::info);

BASIC_EXPORT
void change_default_log_level(spdlog::level::level_enum level);
BASIC_END_NAMESPACE