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

if(NOT CMAKE_LINK_WHAT_YOU_USE)
    set(CMAKE_LINK_WHAT_YOU_USE ON)
endif()

# set(BUILD_SHARED_LIBS ON)

# set(CMAKE_UNITY_BUILD ON)

option(BASIC_USE_MOLD "Use mold linker" OFF)

if(NOT CMAKE_COLOR_DIAGNOSTICS)
    set(CMAKE_COLOR_DIAGNOSTICS ON)
endif()
