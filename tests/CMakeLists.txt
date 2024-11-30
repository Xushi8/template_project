# Enable testing
enable_testing()

# Define the test executable
add_executable(my_tests
    my_test.cpp
)

# Link Google Test to your test executable
target_link_libraries(my_tests PUBLIC GTest::gtest GTest::gtest_main)

# Add tests to CTest
add_test(NAME my_test COMMAND my_tests)