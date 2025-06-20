#pragma once
#include "commandBase.hpp"
#include "addCommand.hpp"
#include "subCommand.hpp"
#include "sqrtCommand.hpp"
#include "helpCommand.hpp"
#include "mulCommand.hpp"
#include "shellCommand.hpp"
#include "httpCommand.hpp"
#include "utils.hpp"


// Register all available commands
void init_commands() {
    CommandRegistry::instance().register_command<Help>();

    CommandRegistry::instance().register_command<Add<int>>();
    CommandRegistry::instance().register_command<Add<double>>();

    CommandRegistry::instance().register_command<Sub<int>>();
    CommandRegistry::instance().register_command<Sub<double>>();

    CommandRegistry::instance().register_command<Mul<int>>();
    CommandRegistry::instance().register_command<Mul<double>>();

    CommandRegistry::instance().register_command<Sqrt>();

    CommandRegistry::instance().register_command<Shell>();
    CommandRegistry::instance().register_command<Http>();
}

void initTerminal() { 
std::string line;
std::cout << "Welcome to CRTB Terminal! Type 'help' for a list of commands.\n";

while (true) {
    std::cout << "> ";
    std::getline(std::cin, line);

    if (line.empty())
        continue;

    auto tokens = split(line);  // from Utils.hpp
    std::string cmd = tokens[0];
    tokens.erase(tokens.begin());

    if (cmd == "exit")
        break;

    CommandRegistry::instance().run_command(cmd, tokens);
}

}

void run()
{
    init_commands();
    initTerminal();
}
