#include "commandBase.hpp"

CommandRegistry& CommandRegistry::instance() {
    static CommandRegistry registry;
    return registry;
}

bool CommandRegistry::has_command(const std::string& cmd) const {
    return commands.find(cmd) != commands.end();
}

void CommandRegistry::run_command(const std::string& cmd, const std::vector<std::string>& args) const {
    auto it = commands.find(cmd);
    if (it != commands.end()) {
        it->second(args);
    } else {
        std::cerr << "Unknown command: " << cmd << "\n";
    }
}

void CommandRegistry::show_help() const {
    for (const auto& [cmd, desc] : helps) {
        std::cout << cmd << " - " << desc << "\n";
    }
}
