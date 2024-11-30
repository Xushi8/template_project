# Enable testing
enable_testing()

# Define the test executable
add_executable(main_test
    main_test.cpp
)

# Link Google Test to your test executable
target_link_libraries(main_test GTest::GTest)

# Add tests to CTest
add_test(NAME main_test COMMAND main_test)