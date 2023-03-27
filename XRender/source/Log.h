#pragma once

// Log.h

#include "spdlog/logger.h"
#include "spdlog/fmt/ostr.h"

namespace XRender
{
	class Log
	{
	public:
		static Log& GetInstance()
		{
			static Log log;
			return log;
		}

		template<typename... Types>
		static void Error(const Types... args)
		{
			GetInstance().mLogger->error(args...);
		}

		template<typename... Types>
		static void Warning(const Types... args)
		{
			GetInstance().mLogger->warn(args...);
		}

		template<typename... Types>
		static void Info(const Types... args)
		{
			GetInstance().mLogger->info(args...);
		}

		template<typename... Types>
		static void Trace(const Types... args)
		{
			GetInstance().mLogger->trace(args...);
		}


	private:
		Log();
		~Log() {};
		Log(const Log& log) = delete;
		Log& operator=(const Log& log) = delete;

	private:

		std::shared_ptr<spdlog::logger>	mLogger;
	};
}