add_library(command_shell
    shellCommand.hpp
)

target_include_directories(command_shell PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Depends on core because it includes CommandBase
target_link_libraries(command_shell PUBLIC command_core)
