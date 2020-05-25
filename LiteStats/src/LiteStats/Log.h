#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace LiteStats {

	class LS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetServiceLogger() { return s_ServiceLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ServiceLogger;
	};
}

// Core log macros
#define LS_CORE_TRACE(...)    ::LiteStats::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LS_CORE_INFO(...)     ::LiteStats::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LS_CORE_WARN(...)     ::LiteStats::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LS_CORE_ERROR(...)    ::LiteStats::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LS_CORE_FATAL(...)    ::LiteStats::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Service log macros
#define LS_TRACE(...)	      ::LiteStats::Log::GetServiceLogger()->trace(__VA_ARGS__)
#define LS_INFO(...)	      ::LiteStats::Log::GetServiceLogger()->info(__VA_ARGS__)
#define LS_WARN(...)	      ::LiteStats::Log::GetServiceLogger()->warn(__VA_ARGS__)
#define LS_ERROR(...)	      ::LiteStats::Log::GetServiceLogger()->error(__VA_ARGS__)
#define LS_FATAL(...)	      ::LiteStats::Log::GetServiceLogger()->fatal(__VA_ARGS__)