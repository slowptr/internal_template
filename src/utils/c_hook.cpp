#include "c_hook.h"

#include <MinHook.h>

namespace utils {
    c_hook::c_hook(const std::string &name, void *target, void *detour, void **original) {
        _name     = name;
        _target   = target;
        _detour   = detour;
        _original = original;
    }

    bool c_hook::create() {
        auto action = MH_CreateHook(_target, _detour, _original);
        return action == MH_OK;
    }

    bool c_hook::remove() {
        auto action = MH_RemoveHook(_target);
        return action == MH_OK;
    }

    bool c_hook::set_state(bool enabled) {
        auto action = enabled ? MH_EnableHook(_target) : MH_RemoveHook(_target);
        return action == MH_OK;
    }

    bool c_hook::set_all_states(bool enabled) {
        auto action = enabled ? MH_EnableHook(MH_ALL_HOOKS) : MH_RemoveHook(MH_ALL_HOOKS);
        return action == MH_OK;
    }

    bool c_hook::initialize() {
        auto action = MH_Initialize();
        return action == MH_OK;
    }

    bool c_hook::shutdown() {
        set_all_states(false);

        auto action = MH_Uninitialize();
        return action == MH_OK;
    }

    std::string c_hook::get_name() { return _name; }
}  // namespace utils