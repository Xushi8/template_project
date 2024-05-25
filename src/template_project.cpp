#include <util/log.h>

int main()
{
	basic_namespace::set_default_log("template_project", spdlog::level::info, "logs/mylog.txt");

	spdlog::warn("warn log");
	spdlog::info("info log");

	return 0;
}
