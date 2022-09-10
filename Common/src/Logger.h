#pragma once
#include "util.h"
#include "spdlog/fmt/ostr.h"

extern shared_ptr<spdlog::logger> logger;

string errorCodeToString(const cpr::ErrorCode& errorCode);

namespace Logger
{

void init(string loggerName, bool truncate);

}
