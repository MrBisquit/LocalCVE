project(backend)

# Set sources
file(
    GLOB_RECURSE ${PROJECT_NAME}_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Find packages
find_package(SQLite3 REQUIRED)

# Create library
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})

# Target includes
target_include_directories(${PROJECT_NAME} include)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)