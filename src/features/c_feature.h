#ifndef INTERNAL_TEMPLATE_C_FEATURE_H
#define INTERNAL_TEMPLATE_C_FEATURE_H

#include <thread>

namespace features {
    class c_feature {
       public:
        auto         get_thread() -> std::thread;
        virtual auto function() -> void = 0;
        bool         panic              = false;

       private:
        static auto _run_func(c_feature* feature) -> void;
    };
}  // namespace features

#endif  // INTERNAL_TEMPLATE_C_FEATURE_H
