option(BASIC_AUTHOR "Author model" OFF)

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

set(CMAKE_LINK_WHAT_YOU_USE ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BASIC_STATIC_EXTERNAL_LIB "Enable static external lib" ON)
if(BASIC_STATIC_EXTERNAL_LIB)
    if(WIN32)
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    else()
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    endif()
endif()

if(NOT DEFINED BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS OFF)
endif()

if(BUILD_SHARED_LIBS)
    message(STATUS "Building shared libraries")
else()
    message(STATUS "Building static libraries")
endif()

option(BASIC_INSTALL_STATIC_LIB "Install static lib" OFF)

option(BASIC_STATIS_LIBCXX "Link static cpp lib" ON)

if(NOT WIN32)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif()

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

option(BASIC_ENABLE_SSE4 "Enable sse4.1 sse4.2" OFF)
option(BASIC_ENABLE_AVX "Enable avx" OFF)
option(BASIC_ENABLE_AVX2 "Enable avx2 fma" OFF)

option(BASIC_ENABLE_MOLD "Enable mold linker" OFF)

# lto
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
