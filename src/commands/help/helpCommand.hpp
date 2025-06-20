#pragma once
#include "../core/commandBase.hpp"
#include <iostream>
#include "commandRegistry.hpp"


class Help : public Command<Help> {
public:
    void execute(const std::vector<std::string>&) const {
        CommandRegistry::instance().show_help();
    }

    static std::string command_name() { return "help"; }
    static std::string command_help() { return "Shows this help message."; }
};
