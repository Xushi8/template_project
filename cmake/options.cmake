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

option(BASIC_STATIC_EXTERNAL_LIB "Use static external lib" ON)
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

option(BASIC_USE_MOLD "Use mold linker" OFF)

option(BASIC_USE_GUI "Use qt for gui" OFF)
if(BASIC_USE_GUI)
    # Turn on automatic invocation of the MOC, UIC & RCC
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTORCC ON)
endif()

set(CMAKE_COLOR_DIAGNOSTICS ON)

# lto
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
