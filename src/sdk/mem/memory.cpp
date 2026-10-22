#include "memory.h"

namespace Mem {
    uintptr_t GetModuleBase(const char* moduleName)
    {
        return reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName));
    }
}