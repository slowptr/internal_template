#include <mutex>

#include "../../utils/c_hook.h"
#include "../../utils/c_log.h"
#include "hooks.h"

#define NAME   example_hook
#define NAME_S "example_hook"

namespace process::hooks::NAME {
    void function() {
        static std::once_flag flag;
        // std::call_once(flag, [&]() { spdlog::info("{0}::function(): called once", NAME_S); });
        std::call_once(flag, [&]() {
            std::stringstream sstream;
            sstream << NAME_S << "::function(): called once";
            utils::g_log->info(sstream.str());
        });

        /* return */ original();
    }

    utils::c_hook get_hook() {
        auto address = 0xDEADBEEF;
        return {NAME_S,                                 //
                reinterpret_cast<void *>(address),      //
                function,                               //
                reinterpret_cast<void **>(&original)};  //
    }
}  // namespace process::hooks::NAME