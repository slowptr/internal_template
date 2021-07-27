#ifndef INTERNAL_TEMPLATE_C_HOOK_MGR_H
#define INTERNAL_TEMPLATE_C_HOOK_MGR_H

namespace utils {
    class c_hook_mgr {
       public:
        static auto init() -> bool;
        static auto finish() -> bool;
    };
}  // namespace utils

#endif  // INTERNAL_TEMPLATE_C_HOOK_MGR_H
