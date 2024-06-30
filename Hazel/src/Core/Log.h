#pragma once

#include "Core.h"

#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"


namespace Hazel {

	class HAZEL_API Log
	{
	public:
		static void Init();

		inline static Hazel::Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static Hazel::Ref<spdlog::logger>& GetClientlogger() { return s_ClientLogger; };

	private:
		static Hazel::Ref<spdlog::logger> s_CoreLogger;
		static Hazel::Ref<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define HZ_CORE_TRACE(...) ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HZ_TRACE(...) ::Hazel::Log::GetClientlogger()->trace(__VA_ARGS__)
#define HZ_INFO(...) ::Hazel::Log::GetClientlogger()->info(__VA_ARGS__)
#define HZ_WARN(...) ::Hazel::Log::GetClientlogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...) ::Hazel::Log::GetClientlogger()->error(__VA_ARGS__)
#define HZ_FATAL(...) ::Hazel::Log::GetClientlogger()->fatal(__VA_ARGS__)

