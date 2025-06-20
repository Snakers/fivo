#pragma once
#include <string>
#include <sstream>
#include <vector>

inline std::vector<std::string> split(const std::string& input) {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> result;

    while (ss >> word) {
        result.push_back(word);
    }

    return result;
}
