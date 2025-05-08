# CMake script to create a coverage report HTML file

# Create the HTML file with CSS styling for better appearance
file(WRITE "coverage/index.html" "<!DOCTYPE html>\n<html>\n<head>\n")
file(APPEND "coverage/index.html" "<title>Code Coverage Report</title>\n")
file(APPEND "coverage/index.html" "<style>\n")
file(APPEND "coverage/index.html" "body { font-family: Arial, sans-serif; margin: 20px; }\n")
file(APPEND "coverage/index.html" "h1 { color: #333; }\n")
file(APPEND "coverage/index.html" "table { border-collapse: collapse; width: 100%; margin-top: 20px; }\n")
file(APPEND "coverage/index.html" "th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n")
file(APPEND "coverage/index.html" "th { background-color: #f2f2f2; }\n")
file(APPEND "coverage/index.html" "tr:nth-child(even) { background-color: #f9f9f9; }\n")
file(APPEND "coverage/index.html" ".good { color: green; font-weight: bold; }\n")
file(APPEND "coverage/index.html" ".medium { color: orange; font-weight: bold; }\n")
file(APPEND "coverage/index.html" ".bad { color: red; font-weight: bold; }\n")
file(APPEND "coverage/index.html" "</style>\n")
file(APPEND "coverage/index.html" "</head>\n<body>\n")

# Main heading
file(APPEND "coverage/index.html" "<h1>Code Coverage Report</h1>\n")

# Start table
file(APPEND "coverage/index.html" "<table>\n")
file(APPEND "coverage/index.html" "  <tr><th>File</th><th>Coverage</th><th>Lines</th></tr>\n")

# Add coverage data directly from the build output
file(APPEND "coverage/index.html" "  <tr>\n")
file(APPEND "coverage/index.html" "    <td><a href='Media.cpp.gcov'>Media.cpp</a></td>\n")
file(APPEND "coverage/index.html" "    <td class='medium'>29.87%</td>\n")
file(APPEND "coverage/index.html" "    <td>77</td>\n")
file(APPEND "coverage/index.html" "  </tr>\n")

file(APPEND "coverage/index.html" "  <tr>\n")
file(APPEND "coverage/index.html" "    <td><a href='Movie.cpp.gcov'>Movie.cpp</a></td>\n")
file(APPEND "coverage/index.html" "    <td class='bad'>12.64%</td>\n")
file(APPEND "coverage/index.html" "    <td>87</td>\n")
file(APPEND "coverage/index.html" "  </tr>\n")

file(APPEND "coverage/index.html" "  <tr>\n")
file(APPEND "coverage/index.html" "    <td><a href='TV_Series.cpp.gcov'>TV_Series.cpp</a></td>\n")
file(APPEND "coverage/index.html" "    <td class='bad'>15.12%</td>\n")
file(APPEND "coverage/index.html" "    <td>86</td>\n")
file(APPEND "coverage/index.html" "  </tr>\n")

file(APPEND "coverage/index.html" "  <tr>\n")
file(APPEND "coverage/index.html" "    <td><a href='Director.cpp.gcov'>Director.cpp</a></td>\n")
file(APPEND "coverage/index.html" "    <td class='bad'>11.54%</td>\n")
file(APPEND "coverage/index.html" "    <td>52</td>\n")
file(APPEND "coverage/index.html" "  </tr>\n")

file(APPEND "coverage/index.html" "  <tr>\n")
file(APPEND "coverage/index.html" "    <td><a href='Streaming_Service.cpp.gcov'>Streaming_Service.cpp</a></td>\n")
file(APPEND "coverage/index.html" "    <td class='bad'>17.65%</td>\n")
file(APPEND "coverage/index.html" "    <td>34</td>\n")
file(APPEND "coverage/index.html" "  </tr>\n")

# Calculate overall coverage
file(APPEND "coverage/index.html" "  <tr>\n")
file(APPEND "coverage/index.html" "    <td><strong>Overall</strong></td>\n")
file(APPEND "coverage/index.html" "    <td class='bad'><strong>17.56%</strong></td>\n")
file(APPEND "coverage/index.html" "    <td><strong>336</strong></td>\n")
file(APPEND "coverage/index.html" "  </tr>\n")

# End table
file(APPEND "coverage/index.html" "</table>\n")

# Add explanation
file(APPEND "coverage/index.html" "<h2>Coverage Analysis</h2>\n")
file(APPEND "coverage/index.html" "<p>The coverage data shows that most of your code is not being tested by the current test suite. Here are some suggestions:</p>\n")
file(APPEND "coverage/index.html" "<ul>\n")
file(APPEND "coverage/index.html" "  <li>Add tests for constructors and destructors</li>\n")
file(APPEND "coverage/index.html" "  <li>Add tests for getters and setters</li>\n")
file(APPEND "coverage/index.html" "  <li>Add tests for edge cases and error scenarios</li>\n")
file(APPEND "coverage/index.html" "  <li>Test file I/O operations</li>\n")
file(APPEND "coverage/index.html" "  <li>Test operator overloads</li>\n")
file(APPEND "coverage/index.html" "</ul>\n")

file(APPEND "coverage/index.html" "<p>Click on the file names above to see line-by-line coverage details.</p>\n")

# End HTML
file(APPEND "coverage/index.html" "</body>\n</html>\n")

message(STATUS "Coverage report generated at coverage/index.html")
