#pragma once

#include <Windows.h>
#include <unordered_set>
#include <iostream>

namespace wsac::module::pgck {
    /*
    * @brief Performs a page check.
    * @details Check the article for more information.
    * @return TRUE if positive, else negative.
    */
    BOOL PerformPageCheck();
}