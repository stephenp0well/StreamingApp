#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>

// Custom main function to enable colored output
int main(int argc, char **argv) {
    // Force colored output on Windows
    std::cout << "\033[0m"; // Reset color
    
    // Set environment variable for color
    #ifdef _WIN32
    _putenv("GTEST_COLOR=1");
    #else
    setenv("GTEST_COLOR", "1", 1);
    #endif
    
    // Initialize Google Test with explicit color argument
    std::vector<char*> new_argv;
    for (int i = 0; i < argc; i++) {
        new_argv.push_back(argv[i]);
    }
    
    // Add --gtest_color=yes if not already present
    bool has_color = false;
    for (int i = 1; i < argc; i++) {
        if (strstr(argv[i], "--gtest_color") != nullptr) {
            has_color = true;
            break;
        }
    }
    
    if (!has_color) {
        new_argv.push_back(const_cast<char*>("--gtest_color=yes"));
    }
    
    int new_argc = static_cast<int>(new_argv.size());
    testing::InitGoogleTest(&new_argc, new_argv.data());
    
    // Run the tests
    return RUN_ALL_TESTS();
}
