#ifndef INTERNAL_TEMPLATE_HOOKS_H
#define INTERNAL_TEMPLATE_HOOKS_H

#include <cstdint>

#include "../../utils/c_hook.h"

#define ADD_HOOK(name, _type)            \
    namespace name {                     \
        using type = _type;              \
        inline type          original;   \
        extern utils::c_hook get_hook(); \
    }

namespace process::hooks {
    ADD_HOOK(example_hook, void(__cdecl *)())
}

#endif  // INTERNAL_TEMPLATE_HOOKS_H
