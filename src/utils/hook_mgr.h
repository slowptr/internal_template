#ifndef INTERNAL_TEMPLATE_HOOK_MGR_H
#define INTERNAL_TEMPLATE_HOOK_MGR_H

#include <MinHook.h>

namespace utils::hook_mgr {
    auto init() -> bool {
        // maybe replace false-returns with exceptions

        if (MH_Initialize() != MH_OK)
            return false;



        if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
            return false;

        return true;
    }

    auto finish() -> bool {
        return (MH_DisableHook(MH_ALL_HOOKS) == MH_OK && MH_Uninitialize() == MH_OK);
    }
}

#endif //INTERNAL_TEMPLATE_HOOK_MGR_H
