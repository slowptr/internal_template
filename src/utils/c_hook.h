#ifndef INTERNAL_TEMPLATE_C_HOOK_H
#define INTERNAL_TEMPLATE_C_HOOK_H

#include <string>
namespace utils {
    class c_hook {
       public:
        c_hook(const std::string &name, void *target, void *detour, void **original);

        bool create();
        bool remove();

        bool set_state(bool enabled);

        static bool set_all_states(bool enabled);
        static bool initialize();
        static bool shutdown();

        std::string get_name();

       private:
        std::string _name;
        void       *_target;
        void       *_detour;
        void      **_original;
    };
}  // namespace utils

#endif  // INTERNAL_TEMPLATE_C_HOOK_H
