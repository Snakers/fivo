#pragma once
#include "commandBase.hpp"
#include <iostream>

class Add : public Command<Add> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.size() < 2) {
            std::cerr << "Usage: add x y\n";
            return;
        }
        double a = std::stod(args[0]);
        double b = std::stod(args[1]);
        std::cout << "Result: " << (a + b) << "\n";
    }

    static std::string command_name() { return "add"; }
    static std::string command_help() { return "Adds two numbers. Usage: add x y"; }
};
