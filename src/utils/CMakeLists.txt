# Create a header-only library called `command_utils`
add_library(command_utils INTERFACE)

# Make the utils headers visible to other targets
target_include_directories(command_utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
