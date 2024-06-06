if(WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D_GLIBCXX_DEBUG)
    add_definitions(-D_GLIBCXX_DEBUG_PEDANTIC)
endif()

add_definitions(-DFMT_HEADER_ONLY)
