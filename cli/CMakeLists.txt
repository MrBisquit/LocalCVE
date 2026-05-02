project(cli)

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

# Compiler options
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -O3)
endif()

# Set executable name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME localcve)

# Target includes
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE localcve::localcve)

# This might not even work
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")