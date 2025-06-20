#pragma once
#include "commandBase.hpp"
#include <iostream>
#include <cmath>

class Sqrt : public Command<Sqrt> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.empty()) {
            std::cerr << "Usage: sqrt x\n";
            return;
        }
        double a = std::stod(args[0]);
        std::cout << "Result: " << std::sqrt(a) << "\n";
    }

    static std::string command_name() { return "sqrt"; }
    static std::string command_help() { return "Computes square root. Usage: sqrt x"; }
};
