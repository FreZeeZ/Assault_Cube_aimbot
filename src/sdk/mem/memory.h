#pragma once
#include <cstdint>
#include <Windows.h>

namespace Mem {
    uintptr_t GetModuleBase(const char* moduleName);
}