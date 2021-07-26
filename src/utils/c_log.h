#ifndef INTERNAL_TEMPLATE_C_LOG_H
#define INTERNAL_TEMPLATE_C_LOG_H

#include <stdexcept>

namespace utils {
    class c_log {
       public:
        auto set_console_handle(void* handle) -> void { cmd_handle = handle; }
        auto info(const std::string& msg) const -> void {
            SetConsoleTextAttribute(cmd_handle, 8);
            std::cout << "[!] " << msg << std::endl;
            reset_color();
        }
        auto warn(const std::string& msg) const -> void {
            SetConsoleTextAttribute(cmd_handle, 12);
            std::cout << "[$] " << msg << std::endl;
            reset_color();
        }

       private:
        auto  reset_color() const -> void { SetConsoleTextAttribute(cmd_handle, 15); }
        void* cmd_handle{};
    };
    inline c_log g_log;
}  // namespace utils

#endif  // INTERNAL_TEMPLATE_C_LOG_H
