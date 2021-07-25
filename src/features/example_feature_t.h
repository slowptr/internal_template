#ifndef INTERNAL_TEMPLATE_EXAMPLE_FEATURE_T_H
#define INTERNAL_TEMPLATE_EXAMPLE_FEATURE_T_H

#include "c_feature.h"

namespace features {
    struct example_feature_t : c_feature {
        auto function() -> void override {}
    };
    // inline example_feature_t g_example_feature;
}  // namespace features

#endif  // INTERNAL_TEMPLATE_EXAMPLE_FEATURE_T_H
