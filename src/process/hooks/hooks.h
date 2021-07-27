#ifndef INTERNAL_TEMPLATE_HOOKS_H
#define INTERNAL_TEMPLATE_HOOKS_H

#include <cstdint>
#include <mutex>

#include "../../utils/c_log.h"
#include "../../utils/pattern_scan.h"

namespace process::hooks::example_hook {
    inline auto get_address() -> uint32_t;

    using type = void(__cdecl *)(void *);
    inline type original;

    inline auto function(void *a1) -> void;
}  // namespace process::hooks::example_hook

#endif  // INTERNAL_TEMPLATE_HOOKS_H
