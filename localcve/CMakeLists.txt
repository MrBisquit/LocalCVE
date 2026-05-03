project(localcve)

# Set sources
file(
    GLOB_RECURSE ${PROJECT_NAME}_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Find packages
find_package(SQLite3 REQUIRED)
if(WIN32)
    find_package(libgit2 CONFIG REQUIRED)
else()
    find_package(PkgConfig REQUIRED)
	pkg_check_modules(LIBGIT2 REQUIRED libgit2)
endif()

# Create library
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Compiler options
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    # -Werror
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -O1
        -fsanitize=address,undefined -fno-omit-frame-pointer)

    target_link_options(
        ${PROJECT_NAME} PRIVATE
		-fsanitize=address,undefined
	)
endif()

# Some properties
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Install stuff
install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    EXPORT ${PROJECT_NAME}targets
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

install(
    DIRECTORY include/
    DESTINATION include
)

# Target includes
target_include_directories(
    ${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE libgit2::libgit2package)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE ${LIBGIT2_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBGIT2_LIBRARIES})
endif()