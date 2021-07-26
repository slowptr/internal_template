#ifndef INTERNAL_TEMPLATE_HOOK_MGR_H
#define INTERNAL_TEMPLATE_HOOK_MGR_H

#include <MinHook.h>

#include "../process/hooks/example_hook.h"

#define ADD_HOOK(x)                                                        \
    MH_CreateHook(reinterpret_cast<void *>(x::get_address()), x::function, \
                  reinterpret_cast<void **>(&x::original))

namespace utils::hook_mgr {
    auto init() -> bool {
        if (MH_Initialize() != MH_OK)
            throw std::runtime_error(
                "utils::hook_mgr::init(): "
                "MH_Initialize() failed.");

        {
            using namespace process::hooks;

            if (ADD_HOOK(example_hook) != MH_OK)
                throw std::runtime_error(
                    "utils::hook_mgr::init(): "
                    "MH_CreateHook(example_hook) failed.");
        }

        if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
            throw std::runtime_error(
                "utils::hook_mgr::init(): "
                "MH_EnableHook(MH_ALL_HOOKS) failed.");

        return true;
    }

    auto finish() -> bool {
        if (MH_DisableHook(MH_ALL_HOOKS) != MH_OK)
            throw std::runtime_error(
                "utils::hook_mgr::finish(): "
                "MH_DisableHook(MH_ALL_HOOKS) failed.");

        if (MH_Uninitialize() != MH_OK)
            throw std::runtime_error(
                "utils::hook_mgr::finish(): "
                "MH_Uninitialize() failed.");

        return true;
    }
}  // namespace utils::hook_mgr

#endif  // INTERNAL_TEMPLATE_HOOK_MGR_H
