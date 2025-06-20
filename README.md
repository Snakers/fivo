🧠 Fivo Terminal CLI Framework
A modular, extensible C++ terminal-based command framework using CRTP, CMake, and libcurl. Inspired by REPL design and built for performance, testability, and ease of extension.

✨ Features
🔌 Modular architecture – Add commands without touching the core

⚙️ Command Registry – Dynamically registers and executes commands

🚀 Static polymorphism (CRTP) – Zero runtime overhead for dispatch

🌐 Network support – HTTP GET, POST, PUT, DELETE via libcurl

🧵 Multithreaded-ready – Supports std::async or custom threads

📦 Modern CMake – Modular, header-first structure

🧪 Header-only commands – Clean, testable, and easy to extend

📁 Project Structure
>fivo/
>├── CMakeLists.txt
>├── src/
>│   ├── main.cpp
>│   ├── core/                # Command base classes and CommandRegistry
>│   │   ├── commandBase.hpp
>│   │   └── commandRegistry.hpp / .cpp
>│   ├── utils/               # Optional utility headers
>│   └── commands/
>│       ├── help/            # Help command
>│       │   └── helpCommand.hpp
>│       ├── math/            # Mathematical commands
>│       │   ├── addCommand.hpp
>│       │   ├── subCommand.hpp
>│       │   └── sqrtCommand.hpp
>│       ├── system/          # System/shell commands
>│       │   └── shellCommand.hpp
>│       └── network/         # HTTP client
>│           └── httpCommand.hpp


🏁 Getting Started
🔧 Prerequisites
Install dependencies (for Ubuntu/Debian):
sudo apt update
sudo apt install build-essential cmake libcurl4-openssl-dev


⚙️ Build
git clone https://github.com/yourname/fivo.git
cd fivo
mkdir build && cd build
cmake ..
make
./fivo


🧪 Usage Examples
> help
List of available commands...

> add 5 2
Result: 7

> sub 9 4
Result: 5

> sqrt 25
Result: 5

> shell ls -l
... system output ...

> http get https://httpbin.org/get
... JSON response ...

> http post https://httpbin.org/post '{"msg":"hello"}'
... JSON response ...

➕ How to Add a New Command
Let’s say you want to create a command named echo:

1. Create the Header
📄 src/commands/echo/echoCommand.hpp
#pragma once
#include "commandBase.hpp"
#include <iostream>

class Echo : public Command<Echo> {
public:
    void execute(const std::vector<std::string>& args) const override {
        for (const auto& arg : args)
            std::cout << arg << " ";
        std::cout << "\n";
    }

    static std::string command_name() { return "echo"; }
    static std::string command_help() { return "Echoes the input arguments."; }
};


2. Create a CMake File for the Command
📄 src/commands/echo/CMakeLists.txt

add_library(command_echo INTERFACE)
target_include_directories(command_echo INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


3. Add the Echo Command to Command List
📄 src/commands/CMakeLists.txt
add_subdirectory(echo)


4. Link the Echo Command
📄 src/CMakeLists.txt

target_link_libraries(fivo
    ...
    command_echo
)


5. Register the Command
📄 inc/startup.hpp

#include "echoCommand.hpp"

void init_commands() {
    CommandRegistry::instance().register_command<Echo>();
}


✅ Done!
Now you can use it:

> echo Hello from Fivo!
Hello from Fivo!
