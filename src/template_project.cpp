#include <util/log.h>

namespace basic_namespace
{
int main()
{
	set_default_log("template_project", spdlog::level::info, "logs/mylog.txt");

	spdlog::warn("warn log");
	spdlog::info("info log");

	return 0;
}
} // namespace basic_namespace
