find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SOURCES
    test_echo.t.cc
)

# Create test executable
add_executable(tests ${TEST_SOURCES})

# Link libraries to the test executable
target_link_libraries(tests
    ${GTEST_BOTH_LIBRARIES}
)