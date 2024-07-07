#include <gtest/gtest.h>
#include "echo.h"  // Replace with the appropriate header file

// Example test case for the echo function
TEST(EchoFunctionTest, BasicTest) {
    // Test input and expected output
    std::string input = "Hello, World!";
    std::string expected_output = "Echo: Hello, World!";

    // Call the function under test
    std::string result = echo(input);

    // Assert the result
    EXPECT_EQ(result, expected_output);
}
