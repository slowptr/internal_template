#ifndef INTERNAL_TEMPLATE_HOOK_MGR_H
#define INTERNAL_TEMPLATE_HOOK_MGR_H

#include <MinHook.h>

#include "../process/hooks/example_hook.h"

#define ADD_HOOK(x)                                                        \
    MH_CreateHook(reinterpret_cast<void *>(x::get_address()), x::function, \
                  reinterpret_cast<void **>(&x::original))

namespace utils::hook_mgr {
    auto init() -> bool {
        // maybe replace false-returns with exceptions

        if (MH_Initialize() != MH_OK) return false;

        {
            using namespace process::hooks;
            if (!ADD_HOOK(example_hook)) return false;
        }

        if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) return false;

        return true;
    }

    auto finish() -> bool {
        return (MH_DisableHook(MH_ALL_HOOKS) == MH_OK &&
                MH_Uninitialize() == MH_OK);
    }
}  // namespace utils::hook_mgr

#endif  // INTERNAL_TEMPLATE_HOOK_MGR_H
