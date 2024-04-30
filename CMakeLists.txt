cmake_minimum_required(VERSION 3.1)

project(more_thread LANGUAGES C CXX VERSION 0.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT CMAKE_LINK_WHAT_YOU_USE)
    set(CMAKE_LINK_WHAT_YOU_USE ON)
endif()

# set(BUILD_SHARED_LIBS ON)

set(CMAKE_UNITY_BUILD ON)

include(./cmake/options.cmake)
include(./cmake/compiler_options.cmake)
include(./cmake/compiler_definitions.cmake)
include(./cmake/ccache.cmake)
include(./cmake/package.cmake)
include(./cmake/print_info.cmake)

include_directories(./external/include)

add_subdirectory(src)
add_subdirectory(external)
