#ifndef INTERNAL_TEMPLATE_EXAMPLE_HOOK_H
#define INTERNAL_TEMPLATE_EXAMPLE_HOOK_H

#include <cstdint>

#include "../../utils/log_t.h"
#include "../../utils/pattern_scan.h"

namespace process::hooks::example_hook {
    auto get_address() -> uint32_t {
        auto address = utils::pattern_scan("module_name.dll", "AA ?? BB ?? CC ?? DD ?? EE ?? FF");

        std::stringstream stream;
        stream << "process::hooks::example_hook::get_address(): 0x" << std::hex << address;
        utils::m_log.info(stream.str());

        return address;
    }

    using type = void(__cdecl *)(void *);
    type original;

    auto function(void *a1) -> void {}
}  // namespace process::hooks::example_hook

#endif  // INTERNAL_TEMPLATE_EXAMPLE_HOOK_H
