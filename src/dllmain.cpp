#include <Windows.h>

#include <chrono>
#include <thread>

#include "process/hooks/hooks.h"

auto __stdcall entry_loop(void *hinstance) -> unsigned long {
    try {
        utils::c_hook::initialize();
        {
            using namespace process::hooks;
            example_hook::get_hook().create();
        }

        while (!(GetAsyncKeyState(VK_NUMPAD0))) {
            using namespace std::chrono_literals;

            std::this_thread::sleep_for(150ms);
        }
    } catch (const std::runtime_error &e) {
        //
    }

    FreeLibraryAndExitThread(static_cast<HMODULE>(hinstance), 0);
}

auto __stdcall DllMain(void *hinstance, const unsigned long reason, void *) -> int {
    DisableThreadLibraryCalls(static_cast<HMODULE>(hinstance));
    if (reason == DLL_PROCESS_ATTACH) {
        if (const auto thread = CreateThread(nullptr, 0, entry_loop, hinstance, 0, nullptr); thread)
            CloseHandle(thread);
    }

    return TRUE;
}