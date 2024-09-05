cmake_minimum_required(VERSION 3.25)

project(more_thread LANGUAGES C CXX VERSION 0.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_definitions.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccache.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/package.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/print_info.cmake)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/common/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/flatbuffers/include)

add_subdirectory(src)
add_subdirectory(external)
