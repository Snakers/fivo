add_library(command_http
    httpCommand.hpp
)

target_include_directories(command_http PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Depends on core because it includes CommandBase
target_link_libraries(command_http PUBLIC command_core)
