#ifndef INTERNAL_TEMPLATE_HOOKS_H
#define INTERNAL_TEMPLATE_HOOKS_H

#include <cstdint>

namespace process::hooks::example_hook {
    extern auto get_address() -> uint32_t;

    using type = void(__cdecl *)(void *);
    inline type original;

    extern auto function(void *a1) -> void;
}  // namespace process::hooks::example_hook

#endif  // INTERNAL_TEMPLATE_HOOKS_H
