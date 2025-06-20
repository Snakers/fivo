#pragma once
#include "commandBase.hpp"
#include <iostream>

class Mul : public Command<Mul> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.size() < 2) {
            std::cerr << "Usage: mul x y\n";
            return;
        }
        double a = std::stod(args[0]);
        double b = std::stod(args[1]);
        std::cout << "Result: " << (a * b) << "\n";
    }

    static std::string command_name() { return "mul"; }
    static std::string command_help() { return "Multiply with number with second number. Usage: mul x y"; }
};
