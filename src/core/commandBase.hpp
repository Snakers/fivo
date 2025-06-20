#pragma once
#include <vector>
#include <string>

template<typename Derived>
class Command {
public:
    void operator()(const std::vector<std::string>& args) const {
        static_cast<const Derived*>(this)->execute(args);
    }

    static std::string name() {
        return Derived::command_name();
    }

    static std::string help() {
        return Derived::command_help();
    }
};
