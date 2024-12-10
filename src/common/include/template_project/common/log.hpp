#pragma once

#include <template_project/common/common.hpp>
#include <string>
#include <spdlog/spdlog.h>

BASIC_PROJECT_BEGIN_NAMESPACE

struct log_options
{
    spdlog::level::level_enum level = spdlog::level::info;
    std::string log_name{};  // NOLINT(readability-redundant-member-init)
    std::string file_path{}; // NOLINT(readability-redundant-member-init)
    bool with_time = false;
};

BASIC_PROJECT_EXPORT
void set_default_log(const log_options& opts);

BASIC_PROJECT_END_NAMESPACE
