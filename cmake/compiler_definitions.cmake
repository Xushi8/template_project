if(WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_definitions(-D_GLIBCXX_DEBUG)
    endif()
endif()

add_definitions(-DFMT_HEADER_ONLY)
