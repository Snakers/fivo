add_library(command_help
    helpCommand.hpp
)

target_include_directories(command_help PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Depends on core because it includes CommandBase
target_link_libraries(command_help PUBLIC command_core)
