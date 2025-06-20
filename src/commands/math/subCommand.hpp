#pragma once
#include "commandBase.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

template<typename T>
class Sub : public Command<Sub<T>> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.size() < 2) {
            std::cerr << "Usage: sub x y [z ...]\n";
            return;
        }

        std::vector<T> values;
        for (const auto& str : args) {
            std::istringstream iss(str);
            T val;
            iss >> val;
            values.push_back(val);
        }

        // Apply subtraction using fold-like logic
        T result = std::accumulate(
            std::next(values.begin()), values.end(),
            values[0],
            [](T acc, T val) { return acc - val; }
            );

        std::cout << "Result: " << result << "\n";
    }

    static std::string command_name() { return "sub"; }
    static std::string command_help() { return "Subtracts all numbers from the first."; }
};
