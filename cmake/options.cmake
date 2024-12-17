set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

if(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

option(BASIC_PROJECT_STRICT_STL_CHECKS "Enable strict debugging and runtime checks" OFF)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BASIC_PROJECT_STRICT_STL_CHECKS ON)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BASIC_PROJECT_STATIC_EXTERNAL_LIB "Enable static external lib" ON)
if(BASIC_PROJECT_STATIC_EXTERNAL_LIB)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".a")
endif()

option(BASIC_PROJECT_TEST "Enable google test" OFF)

if(NOT DEFINED BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS OFF)
endif()

if(BUILD_SHARED_LIBS)
    message(STATUS "Building shared libraries")
else()
    message(STATUS "Building static libraries")
endif()

option(BASIC_PROJECT_INSTALL_STATIC_LIB "Install static lib" OFF)

option(BASIC_PROJECT_STATIC_LIBSTDCXX "Link static libstdc++" ON)

if(NOT WIN32)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif()

option(BASIC_PROJECT_SSE4 "Enable sse4.1 sse4.2" OFF)
option(BASIC_PROJECT_AVX "Enable avx" OFF)
option(BASIC_PROJECT_AVX2 "Enable avx2 fma" OFF)
option(BASIC_PROJECT_NATIVE_ARCH "-march=native" OFF)

option(BASIC_PROJECT_MOLD "Enable mold linker" OFF)

option(BASIC_PROJECT_ADDRESS_SANITIZER "-fsanitize=address" OFF)
option(BASIC_PROJECT_UNDEFINED_SANITIZER "-fsanitize=undefined" OFF)
option(BASIC_PROJECT_THREAD_SANITIZER "-fsanitize=thread" OFF)
option(BASIC_PROJECT_MEMORY_SANITIZER "-fsanitize=memory" OFF)

# lto
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
