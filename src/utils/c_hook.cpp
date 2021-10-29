#include "c_hook.h"

#include <MinHook.h>

namespace utils {
    c_hook::c_hook(const std::string &name, void *target, void *detour, void **original) {
        _name     = name;
        _target   = target;
        _detour   = detour;
        _original = original;
    }

    /*
     * code copied off of another project from me, done in the last 2-3 months
     * prob. gonna replace my log shit with spdlog or smth
     * commented out for now tho
     */

    bool c_hook::create() {
        auto action = MH_CreateHook(_target, _detour, _original);
        if (action != MH_OK) {
            // spdlog::warn("hook creation failed ({0}): {1} [0x{2:x}]", action, _name, _target);
            return false;
        }
        // spdlog::info("{0}: 0x{1:x}", _name, (uint32_t)_target);
        return true;
    }

    bool c_hook::remove() {
        auto action = MH_RemoveHook(_target);
        if (action != MH_OK) {
            // spdlog::warn("hook deletion failed ({0}): {1} [0x{2:x}]", action, _name, _target);
            return false;
        }
        return true;
    }

    bool c_hook::set_state(bool enabled) {
        auto action = enabled ? MH_EnableHook(_target) : MH_RemoveHook(_target);
        if (action != MH_OK) {
            // spdlog::warn("hook set_state failed ({0}): {1} [0x{2:x}]", action, _name, _target);
            return false;
        }
        return true;
    }

    bool c_hook::set_all_states(bool enabled) {
        auto action = enabled ? MH_EnableHook(MH_ALL_HOOKS) : MH_RemoveHook(MH_ALL_HOOKS);
        if (action != MH_OK) {
            // spdlog::warn("hook set_state failed ({0}): MH_ALL_HOOKS", action);
            return false;
        }
        return true;
    }

    bool c_hook::initialize() {
        auto action = MH_Initialize();
        if (action != MH_OK) {
            // spdlog::warn("minhook initialization failed ({0})", action);
            return false;
        }
        return true;
    }

    bool c_hook::shutdown() {
        set_all_states(false);

        auto action = MH_Uninitialize();
        if (action != MH_OK) {
            // spdlog::warn("minhook shutdown failed ({0})", action);
            return false;
        }
        return true;
    }

    std::string c_hook::get_name() { return _name; }
}  // namespace utils