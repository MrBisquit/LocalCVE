project(cli)

# Set executable name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME localcve)

# Set sources
file(
    GLOB_RECURSE ${PROJECT_NAME}_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Add executable
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})