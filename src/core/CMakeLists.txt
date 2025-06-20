add_library(command_core
    commandRegistry.cpp
)

target_include_directories(command_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
