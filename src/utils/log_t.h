#ifndef INTERNAL_TEMPLATE_LOG_T_H
#define INTERNAL_TEMPLATE_LOG_T_H

#include <stdexcept>

namespace utils {
    struct log_t {
        auto set_console_handle(void* handle) -> void { cmd_handle = handle; }
        auto info(const std::string& msg) -> void {
            SetConsoleTextAttribute(cmd_handle, 8);
            std::cout << "[!] " << msg << std::endl;
            reset_color();
        }
        auto warn(const std::string& msg) -> void {
            SetConsoleTextAttribute(cmd_handle, 12);
            std::cout << "[$] " << msg << std::endl;
            reset_color();
        }

       private:
        auto  reset_color() -> void { SetConsoleTextAttribute(cmd_handle, 15); }
        void* cmd_handle{};
    };
    inline log_t m_log;
}  // namespace utils

#endif  // INTERNAL_TEMPLATE_LOG_T_H
