cmake_minimum_required(VERSION 3.25)

project(more_thread LANGUAGES C CXX VERSION 0.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(./cmake/options.cmake)
include(./cmake/compiler_options.cmake)
include(./cmake/compiler_definitions.cmake)
include(./cmake/ccache.cmake)
include(./cmake/package.cmake)
include(./cmake/print_info.cmake)

include_directories(./external/include)
include_directories(${PROJECT_SOURCE_DIR}/src/common/include)
include_directories(${PROJECT_SOURCE_DIR}/src/flatbuffers/include)

add_subdirectory(src)
add_subdirectory(external)
