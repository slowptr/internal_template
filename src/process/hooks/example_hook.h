#ifndef INTERNAL_TEMPLATE_EXAMPLE_HOOK_H
#define INTERNAL_TEMPLATE_EXAMPLE_HOOK_H

#include <cstdint>
#include "../../utils/pattern_scan.h"

namespace process::hooks::example_hook {
    uint32_t get_address() {
        // return address;
        return utils::pattern_scan("module_name.dll", "AA ?? BB ?? CC ?? DD ?? EE ?? FF");
    }

    using type = void (__cdecl *)(void *);
    type original;

    auto function(void *a1) -> void {

    }
}

#endif //INTERNAL_TEMPLATE_EXAMPLE_HOOK_H
