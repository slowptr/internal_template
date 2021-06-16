#include <Windows.h>
#include <chrono>
#include <thread>
#include "utils/hook_mgr.h"

auto __stdcall entry_loop(void *hinstance) -> unsigned long {
#ifdef DEBUG
    AllocConsole();
    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout); // redirect stdout stream to console.
#endif

    {
        utils::hook_mgr::init();

        while (!(GetAsyncKeyState(VK_NUMPAD0))) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(150ms);
        }

        utils::hook_mgr::finish();
    }

    FreeConsole(); // detach console (if it's there).
    FreeLibraryAndExitThread((HMODULE) hinstance, 0);
}

auto __stdcall DllMain(void *hinstance, const unsigned long reason, void *) -> int {
    DisableThreadLibraryCalls((HMODULE) hinstance);
    if (reason == DLL_PROCESS_ATTACH) {
        const auto thread = CreateThread(nullptr, 0, entry_loop, hinstance, 0, nullptr);
        if (thread)
            CloseHandle(thread);
    }

    return TRUE;
}