#pragma once

#include <Windows.h>

namespace wsac::module::vsan {
    BOOL CheckObjectVTable(void* object_ptr, size_t max_slots = 64);
}