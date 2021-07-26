#ifndef INTERNAL_TEMPLATE_C_FEATURE_H
#define INTERNAL_TEMPLATE_C_FEATURE_H

#include <iostream>
#include <thread>

namespace features {
    class c_feature {
       public:
        auto         get_thread() -> std::thread { return std::thread{_run_func, this}; }
        virtual auto function() -> void = 0;
        bool         panic              = false;

       private:
        static auto _run_func(c_feature* feature) -> void {
            if (feature->panic) return;

            feature->function();
        }
    };
}  // namespace features

#endif  // INTERNAL_TEMPLATE_C_FEATURE_H
