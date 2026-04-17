project(cli)

# Set executable name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME localcve)

# Set sources
file(
    GLOB_RECURSE ${PROJECT_NAME}_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set CXX standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

# Target includes
target_include_directories(${PROJECT_NAME} include)

# Link libraries
target_link_libraries(${PROJECT_NAME} backend)