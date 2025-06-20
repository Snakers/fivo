#pragma once
#include "../core/commandBase.hpp"
#include <iostream>
#include <cmath>

class Mul : public Command<Mul> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.empty()) {
            std::cerr << "Usage: sqrt x\n";
            return;
        }
        double a = std::stod(args[0]);
        double b = std::stod(args[1]);

        std::cout << "Result: " << (a * b) << "\n";
    }

    static std::string command_name() { return "mul"; }
    static std::string command_help() { return "Computes multiplication. Usage: mul x y"; }
};
