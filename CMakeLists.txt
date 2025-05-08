cmake_minimum_required(VERSION 3.10)
project(StreamingMediaApp CXX)

# Set the compiler options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/MediaTests.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/exceptions)

# Main application sources
set(APP_SOURCES
    main.cpp
    Media.cpp
    Movie.cpp
    TV_Series.cpp
    Director.cpp
    Streaming_Service.cpp
)

# Create main executable
add_executable(StreamingMediaApp ${APP_SOURCES})

# Add googletest subdirectory
add_subdirectory(googletest)
include_directories(googletest/include)  # this is so we can #include <gtest/gtest.h>

# Set the test sources
set(TEST_SOURCES
    TestDisplay.cpp
    Media.cpp
    Movie.cpp
    TV_Series.cpp
    Director.cpp
    Streaming_Service.cpp
)

# Create the test executable
add_executable(MediaTests ${TEST_SOURCES})

# Link with gtest
target_link_libraries(MediaTests PRIVATE gtest gtest_main)

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# Testing
enable_testing()
add_test(output_tests ${CMAKE_CURRENT_BINARY_DIR}/MediaTests)

