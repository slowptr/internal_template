#ifndef INTERNAL_TEMPLATE_PATTERN_SCAN_H
#define INTERNAL_TEMPLATE_PATTERN_SCAN_H

#include <cstdint>
#include <string_view>

namespace utils {
    extern auto pattern_scan(std::string_view module_name, std::string_view pattern) -> uint32_t;

    extern auto pattern_scan(std::string_view module_name, std::string_view pattern, int offset)
        -> uint32_t;

    extern auto pattern_scan_relative_call(std::string_view module_name, std::string_view pattern,
                                           int offset) -> uint32_t;
}  // namespace utils

#endif  // INTERNAL_TEMPLATE_PATTERN_SCAN_H