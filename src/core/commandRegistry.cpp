#include "commandRegistry.hpp"
#include <future>

CommandRegistry& CommandRegistry::instance() {
    static CommandRegistry registry;
    return registry;
}
bool CommandRegistry::has_command(const std::string& cmd) {
    return commands.find(cmd) != commands.end();
}

void CommandRegistry::run_command(const std::string& cmd, const std::vector<std::string>& args) {
    auto it = commands.find(cmd);
    if (it != commands.end()) {
      auto fut = std::async(std::launch::async, it->second, args);

    } else {
        std::cerr << "Unknown command: " << cmd << "\n";
    }
}

void CommandRegistry::show_help() {
    for (const auto& [cmd, desc] : helps) {
        std::cout << cmd << " - " << desc << "\n";
    }
}

