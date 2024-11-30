# Define the test executable
add_executable(common_test
    common_test.cpp
)

# Link Google Test to your test executable
target_link_libraries(common_test PUBLIC GTest::GTest GTest::gtest_main)

target_include_directories(common_test PRIVATE ../../src/common/include)
target_include_directories(common_test PRIVATE ../../src/gui/include)

# Add tests to CTest
add_test(NAME common_test COMMAND common_test)