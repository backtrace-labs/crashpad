#pragma once

#include <string_view>

namespace backtrace
{
bool initialize_crashpad(std::string_view url);
void crash_memset();
}
