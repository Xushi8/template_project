message(STATUS "------------------ General configuration for ${PROJECT_NAME} ${${PROJECT_NAME}_VERSION} -----------------")
message(STATUS )
message(STATUS "CMake Version =         ${CMAKE_VERSION}")
message(STATUS "CMake Generator =       ${CMAKE_GENERATOR}")
message(STATUS "Compiler =              ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Compiler Version =      ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Build type =            ${CMAKE_BUILD_TYPE}")
message(STATUS "CMake C Standard =      ${CMAKE_C_STANDARD}")
message(STATUS "CMake C++ Standard =    ${CMAKE_CXX_STANDARD}")
message(STATUS "CMAKE_INSTALL_PREFIX =  ${CMAKE_INSTALL_PREFIX}" )


# 获取全局的编译选项
get_property(GLOBAL_COMPILE_OPTIONS DIRECTORY PROPERTY COMPILE_OPTIONS)

# 打印编译选项
message(STATUS "Global compile options: ${GLOBAL_COMPILE_OPTIONS}")



if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
    message(FATAL_ERROR "The binary directory of CMake cannot be the same as source directory!")
endif()


# message(STATUS)
# message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
# message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
# message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
# message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")
# message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
# message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
# message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
# message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")
