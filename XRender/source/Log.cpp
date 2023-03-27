// Log.cpp

#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace XRender
{

Log::Log()
{
	mLogger = spdlog::basic_logger_mt("XRender", "logs.txt");
	mLogger->set_level(spdlog::level::trace);
	mLogger->flush_on(spdlog::level::trace);
}

}