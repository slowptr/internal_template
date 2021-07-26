#ifndef INTERNAL_TEMPLATE_C_EXAMPLE_FEATURE_H
#define INTERNAL_TEMPLATE_C_EXAMPLE_FEATURE_H

#include "c_feature.h"

namespace features {
    class c_example_feature : c_feature {
        auto function() -> void override {}
    };
    // inline c_example_feature g_example_feature;
}  // namespace features

#endif  // INTERNAL_TEMPLATE_C_EXAMPLE_FEATURE_H
