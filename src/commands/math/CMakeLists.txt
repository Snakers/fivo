add_library(command_commands
    addCommand.hpp
    subCommand.hpp
    sqrtCommand.hpp
    mulCommand.hpp
)

target_include_directories(command_commands PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Depends on core because it includes CommandBase
target_link_libraries(command_commands PUBLIC command_core)
