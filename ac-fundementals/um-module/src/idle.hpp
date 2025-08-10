#pragma once

#include <windows.h>

namespace wsac::idle {
    /*
     * @brief Starts the idle monitor.
     * @param interval_ms The interval in milliseconds.
     * @return TRUE if successful, FALSE otherwise.
     */
    BOOL StartIdleMonitor(DWORD interval_ms = 5000);

    /*
     * @brief Stops the idle monitor.
     */
    void StopIdleMonitor();

    BOOL IsIdleMonitorRunning();
}