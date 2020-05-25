#include "lspch.h"

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace LiteStats {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ServiceLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("LiteStats");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ServiceLogger = spdlog::stdout_color_mt("SVC");
		s_ServiceLogger->set_level(spdlog::level::trace);
	}
}