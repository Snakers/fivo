cmake_minimum_required(VERSION 3.10)
project(fivo)

set(CMAKE_CXX_STANDARD 17)

# Add subdirectories for modules
add_subdirectory(src/core)
add_subdirectory(src/commands)
add_subdirectory(src/utils)

find_package(CURL REQUIRED)

# Main executable (only list cpp files here)
add_executable(fivo src/main.cpp)

# Include path for headers
target_include_directories(fivo PRIVATE inc)

# Link libraries
target_link_libraries(fivo PRIVATE
    command_core
    command_utils
    command_commands
    command_help
    command_shell
    command_http
    CURL::libcurl
)
