#pragma once
#include "../../core/commandBase.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

class Shell : public Command<Shell> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.empty()) {
            std::cerr << "Usage: shell <command> [args...]\n";
            return;
        }

        // Join args into a single string
        std::ostringstream oss;
        for (const auto& arg : args) {
            oss << arg << " ";
        }

        std::string command =  oss.str();
        std::cout << "[Executing]: " << command << "\n";

        // Execute the command using system()
        int status = std::system(command.c_str());

        if (status == -1) {
            std::cerr << "Failed to execute command\n";
        } else {
            std::cout << "[Exit code]: " << status << "\n";
        }
    }

    static std::string command_name() { return "shell"; }
    static std::string command_help() { return "Executes a bash shell command. Usage: shell ls -la"; }
};
