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
    test_main.cpp  # Use our custom main function
    TestDisplay.cpp
    Media.cpp
    Movie.cpp
    TV_Series.cpp
    Director.cpp
    Streaming_Service.cpp
)

# Create the test executable
add_executable(MediaTests ${TEST_SOURCES})

# Link with gtest (not gtest_main since we have our own main)
target_link_libraries(MediaTests PRIVATE gtest)

# Enable code coverage with gcov
if(CMAKE_COMPILER_IS_GNUCXX)
    # Add coverage flags to the compiler
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage -fprofile-arcs -ftest-coverage")
    # Link with gcov
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Create a custom target for running tests with coverage
add_custom_target(coverage
    # Run the tests first
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/MediaTests
    
    # Create coverage directory
    COMMAND ${CMAKE_COMMAND} -E make_directory coverage
    
    # Try to find coverage files with explicit paths
    COMMAND ${CMAKE_COMMAND} -E echo "Generating coverage reports..."
    
    # Use a different approach to generate coverage for specific source files
    COMMAND gcov -o ${CMAKE_BINARY_DIR}/CMakeFiles/MediaTests.dir/ ${CMAKE_SOURCE_DIR}/Media.cpp
    COMMAND gcov -o ${CMAKE_BINARY_DIR}/CMakeFiles/MediaTests.dir/ ${CMAKE_SOURCE_DIR}/Movie.cpp
    COMMAND gcov -o ${CMAKE_BINARY_DIR}/CMakeFiles/MediaTests.dir/ ${CMAKE_SOURCE_DIR}/TV_Series.cpp
    COMMAND gcov -o ${CMAKE_BINARY_DIR}/CMakeFiles/MediaTests.dir/ ${CMAKE_SOURCE_DIR}/Director.cpp
    COMMAND gcov -o ${CMAKE_BINARY_DIR}/CMakeFiles/MediaTests.dir/ ${CMAKE_SOURCE_DIR}/Streaming_Service.cpp
    
    # Copy generated .gcov files individually to avoid wildcard issues on Windows
    COMMAND ${CMAKE_COMMAND} -E copy_if_different Media.cpp.gcov coverage/ || ${CMAKE_COMMAND} -E echo "No Media.cpp.gcov file"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different Movie.cpp.gcov coverage/ || ${CMAKE_COMMAND} -E echo "No Movie.cpp.gcov file"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different TV_Series.cpp.gcov coverage/ || ${CMAKE_COMMAND} -E echo "No TV_Series.cpp.gcov file"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different Director.cpp.gcov coverage/ || ${CMAKE_COMMAND} -E echo "No Director.cpp.gcov file"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different Streaming_Service.cpp.gcov coverage/ || ${CMAKE_COMMAND} -E echo "No Streaming_Service.cpp.gcov file"
    
    # Create a simple HTML report without redirection
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/create_coverage_report.cmake
    
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating coverage report in the 'coverage' directory"
)

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# Testing
enable_testing()
add_test(output_tests ${CMAKE_CURRENT_BINARY_DIR}/MediaTests)

