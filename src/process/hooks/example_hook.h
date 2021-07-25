#ifndef INTERNAL_TEMPLATE_EXAMPLE_HOOK_H
#define INTERNAL_TEMPLATE_EXAMPLE_HOOK_H

#include <cstdint>

#include "../../utils/pattern_scan.h"

namespace process::hooks::example_hook {
    auto get_address() -> uint32_t {
        // return address;
        return utils::pattern_scan("module_name.dll", "AA ?? BB ?? CC ?? DD ?? EE ?? FF");
    }

    using type = void(__cdecl *)(void *);
    type original;

    auto function(void *a1) -> void {}
}  // namespace process::hooks::example_hook

#endif  // INTERNAL_TEMPLATE_EXAMPLE_HOOK_H
