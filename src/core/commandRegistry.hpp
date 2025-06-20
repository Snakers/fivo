#pragma once

#include <map>
#include <string>
#include <vector>
#include <functional>
#include <iostream>

class CommandRegistry {
public:
    using CommandFunc = std::function<void(const std::vector<std::string>&)>;

    // Singleton access
    static CommandRegistry& instance();

    // Template command registration
    template<typename T>
    void register_command() {
        commands[T::name()] = T();  // Instantiates T and stores the callable
        helps[T::name()] = T::help();
    }

    bool has_command(const std::string& cmd);
    void run_command(const std::string& cmd, const std::vector<std::string>& args);
    void show_help();

private:
    std::map<std::string, CommandFunc> commands;
    std::map<std::string, std::string> helps;
};
