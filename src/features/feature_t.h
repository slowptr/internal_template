#ifndef INTERNAL_TEMPLATE_FEATURE_T_H
#define INTERNAL_TEMPLATE_FEATURE_T_H

#include <iostream>
#include <thread>

namespace features {
    struct feature_t {
        auto get_thread() -> std::thread {
            return std::thread{_run_func, this};
        }
        virtual auto function() -> void {
            std::cout << "[WARN] no feature to be executed." << std::endl;
        }

        bool panic = false;

       private:
        static auto _run_func(feature_t* feature) -> void {
            if (feature->panic) return;

            feature->function();
        }
    };
}  // namespace features

#endif  // INTERNAL_TEMPLATE_FEATURE_T_H
