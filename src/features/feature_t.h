#ifndef INTERNAL_TEMPLATE_FEATURE_T_H
#define INTERNAL_TEMPLATE_FEATURE_T_H

#include <iostream>
#include <thread>

namespace features {
    struct feature_t {
        std::thread get_thread() {
            return std::thread{_run_func, this};
        }
        virtual void function() {
            std::cout << "[WARN] no feature to be executed." << std::endl;
        }

        bool panic = false;

    private:
        static void _run_func(feature_t* feature) {
            if (feature->panic)
                return;

            feature->function();
        }
    };
}

#endif //INTERNAL_TEMPLATE_FEATURE_T_H
