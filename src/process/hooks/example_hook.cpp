#include "hooks.h"
#include <mutex>

#include "../../utils/c_log.h"
#include "../../utils/pattern_scan.h"

namespace process::hooks::example_hook {
    auto get_address() -> uint32_t {
        const auto address =
            utils::pattern_scan("module_name.dll", "AA ?? BB ?? CC ?? DD ?? EE ?? FF");

        std::stringstream stream;
        stream << "process::hooks::example_hook::get_address(): 0x" << std::hex << address;
        utils::g_log->info(stream.str());

        return address;
    }
    auto function(void *a1) -> void {
        static std::once_flag flag;
        std::call_once(flag, [&]() {
            utils::g_log->info("process::hooks::example_hook::function() hooking successful.");
        });
    }
}  // namespace process::hooks::example_hook