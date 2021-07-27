#include "c_feature.h"

namespace features {
    auto c_feature::get_thread() -> std::thread { return std::thread{_run_func, this}; }
    auto c_feature::_run_func(c_feature *feature) -> void {
        if (feature->panic) return;

        feature->function();
    }
}  // namespace features