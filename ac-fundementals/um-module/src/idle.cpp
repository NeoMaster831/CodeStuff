#include "idle.hpp"
#include "module/page_check.hpp"
#include "module/vtable_sanity.hpp"
#include "module/veh_detection.hpp"
#include "vobject.hpp"
#include <thread>
#include <atomic>
#include <iostream>

namespace wsac::idle {

    static std::atomic<bool> g_running(false);
    static HANDLE g_thread = nullptr;
    static HANDLE g_stopEvent = nullptr;
    static DWORD g_intervalMs = 5000;

    static DWORD WINAPI MonitorThread(LPVOID) {
        std::cout << "idle monitor thread started" << '\n';
        while (1) {
            DWORD wait = WaitForSingleObject(g_stopEvent, g_intervalMs);
            if (wait == WAIT_OBJECT_0) break;

            BOOL hit = FALSE;
            hit |= wsac::module::pgck::PerformPageCheck();
            hit |= wsac::module::vsan::CheckObjectVTable(g_circle);
            hit |= wsac::module::vehd::PerformCheck();
            std::cout << "Circle Info: Radius = " << g_circle->getRadius() << ", Area = " << g_circle->area() << '\n';

            std::cout << (hit ? "Hit" : "Miss") << '\n';
        }
        std::cout << "idle monitor thread ended" << '\n';
        return 0;
    }

    BOOL StartIdleMonitor(DWORD interval_ms) {
        if (g_running.load()) return FALSE;

        if (!g_stopEvent)
        {
            g_stopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
            if (!g_stopEvent) return FALSE;
        }
        else {
            ResetEvent(g_stopEvent);
        }

        g_intervalMs = interval_ms ? interval_ms : 1;
        g_thread = CreateThread(nullptr, 0, MonitorThread, nullptr, 0, nullptr);

        if (!g_thread)
        {
            CloseHandle(g_stopEvent);
            g_stopEvent = nullptr;
            return FALSE;
        }

        g_running.store(true);
        return TRUE;
    }

    void StopIdleMonitor()
    {
        if (!g_running.load()) return;

        if (g_stopEvent) SetEvent(g_stopEvent);
        if (g_thread)
        {
            WaitForSingleObject(g_thread, INFINITE);
            CloseHandle(g_thread);
            g_thread = nullptr;
        }
        if (g_stopEvent)
        {
            CloseHandle(g_stopEvent);
            g_stopEvent = nullptr;
        }
        g_running.store(false);
    }

    BOOL IsIdleMonitorRunning() {
        return g_running.load() ? TRUE : FALSE;
    }
}