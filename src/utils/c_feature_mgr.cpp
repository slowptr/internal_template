#include "c_feature_mgr.h"

#include "../features/features.h"
namespace utils {
    auto c_feature_mgr::init() -> bool {
        _features.push_back(std::make_unique<features::c_example_feature>());

        return false;
    }
    auto c_feature_mgr::loop() -> void {
        for (const auto& feature : _features) {
            feature->get_thread().join();
        }
    }

    std::unique_ptr<c_feature_mgr> g_features =
        std::make_unique<c_feature_mgr>();  // Clang-Tidy: Initialization of 'g_features' with
                                            // static storage duration may throw an exception that
                                            // cannot be caught
}  // namespace utils