#include <Windows.h>

#include <chrono>
#include <thread>

#include "process/hooks/hooks.h"
#include "utils/c_feature_mgr.h"
#include "utils/c_hook.h"
#include "utils/c_log.h"

#define DEBUG

auto __stdcall entry_loop(void *hinstance) -> unsigned long {
#ifdef DEBUG
    AllocConsole();
    freopen_s(reinterpret_cast<FILE **>(stdout), "CONOUT$", "w",
              stdout);  // redirect stdout stream to console.
    utils::g_log->set_console_handle(GetStdHandle(STD_OUTPUT_HANDLE));
#endif

    try {
        utils::c_hook::initialize();
        {
            using namespace process::hooks;
            example_hook::get_hook().create();
        }
        utils::g_features->init();

        while (!(GetAsyncKeyState(VK_NUMPAD0))) {
            using namespace std::chrono_literals;

            utils::g_features->loop();

            std::this_thread::sleep_for(150ms);
        }
    } catch (const std::runtime_error &e) {
        utils::g_log->warn(e.what());
    }

    utils::g_log->info("console detached.");
    FreeConsole();  // detach console (if it's there).
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