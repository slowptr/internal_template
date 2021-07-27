#ifndef INTERNAL_TEMPLATE_C_FEATURE_MGR_H
#define INTERNAL_TEMPLATE_C_FEATURE_MGR_H

#include <memory>
#include <vector>

#include "../features/c_feature.h"

namespace utils {
    class c_feature_mgr {
       public:
        auto init() -> bool;
        auto loop() -> void;
       private:
        std::vector<std::unique_ptr<features::c_feature>> _features;
    };
    extern std::unique_ptr<c_feature_mgr> g_features;
}

#endif  // INTERNAL_TEMPLATE_C_FEATURE_MGR_H
