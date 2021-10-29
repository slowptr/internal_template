#ifndef INTERNAL_TEMPLATE_FEATURES_H
#define INTERNAL_TEMPLATE_FEATURES_H

#include "c_feature.h"

namespace features {
    class c_example_feature : public c_feature {
        auto function() -> void override;
    };

}  // namespace features

#endif  // INTERNAL_TEMPLATE_FEATURES_H
