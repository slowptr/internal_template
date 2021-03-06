#include "pattern_scan.h"

#include <Psapi.h>
#include <Windows.h>

#include <vector>

namespace utils {
    auto pattern_scan(const std::string_view module_name, const std::string_view pattern)
        -> uint32_t {
        static auto pattern_to_byte = [](const char *pattern) -> std::vector<std::size_t> {
            std::vector<std::size_t> bytes;

            const auto start = const_cast<char *>(pattern);
            const auto end   = const_cast<char *>(pattern) + std::strlen(pattern);
            for (auto current = start; current < end; ++current) {
                if (*current == '?') {
                    ++current;
                    if (*current == '?') ++current;

                    bytes.push_back(static_cast<size_t &&>(-1));
                } else
                    bytes.push_back(std::strtoul(current, &current, 16));
            }

            return bytes;
        };

        const auto module = GetModuleHandle(module_name.data());
        if (!module) return -1;

        MODULEINFO module_info;
        if (!K32GetModuleInformation(GetCurrentProcess(), module, &module_info, sizeof(MODULEINFO)))
            return -1;

        const auto image_bytes = reinterpret_cast<unsigned char *>(module);
        if (!image_bytes) return -1;

        const auto image_size = module_info.SizeOfImage;
        if (!image_size) return -1;

        auto       pattern_bytes   = pattern_to_byte(pattern.data());
        const auto signature_size  = pattern_bytes.size();
        const auto signature_bytes = pattern_bytes.data();

        for (unsigned long i = 0; i < image_size - signature_size; ++i) {
            bool byte_sequence_found = true;
            for (unsigned long j = 0; j < signature_size; ++j) {
                if (image_bytes[i + j] != signature_bytes[j] && signature_bytes[j] != -1) {
                    byte_sequence_found = false;
                    break;
                }
            }

            if (byte_sequence_found) return reinterpret_cast<uint32_t>(&image_bytes[i]);
        }

        return -1;
    }
    auto pattern_scan(const std::string_view module_name, const std::string_view pattern,
                      const int offset) -> uint32_t {
        return pattern_scan(module_name, pattern) + offset;
    }
    auto pattern_scan_relative_call(const std::string_view module_name,
                                    const std::string_view pattern, const int offset) -> uint32_t {
        // OPCODE: 0xE8
        auto *sig = reinterpret_cast<uint32_t *>(pattern_scan(module_name, pattern) + offset);
        return reinterpret_cast<uint32_t>(sig) + *sig + 4;
    }
}  // namespace utils