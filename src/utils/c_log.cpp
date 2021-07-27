#include "c_log.h"

#include <Windows.h>

#include <iostream>

namespace utils {
    auto c_log::set_console_handle(void *handle) -> void { _cmd_handle = handle; }
    auto c_log::info(const std::string &msg) const -> void {
        SetConsoleTextAttribute(_cmd_handle, 8);
        std::cout << "[!] " << msg << std::endl;
        _reset_color();
    }
    auto c_log::warn(const std::string &msg) const -> void {
        SetConsoleTextAttribute(_cmd_handle, 12);
        std::cout << "[$] " << msg << std::endl;
        _reset_color();
    }
    auto c_log::_reset_color() const -> void { SetConsoleTextAttribute(_cmd_handle, 15); }

    std::unique_ptr<c_log> g_log =
        std::make_unique<c_log>();  // Clang-Tidy: Initialization of 'g_log' with static storage
                                    // duration may throw an exception that cannot be caught
}  // namespace utils