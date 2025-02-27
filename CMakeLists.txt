cmake_minimum_required(VERSION 3.25)

project(template_project LANGUAGES C CXX VERSION 0.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(NOT (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
    message(FATAL_ERROR "This project only supports gcc and clang")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_definitions.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccache.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/package.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/print_info.cmake)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/common/include)

add_subdirectory(external)
add_subdirectory(src)

if(BASIC_PROJECT_TEST)
    add_subdirectory(tests)
endif()
