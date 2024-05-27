if(WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_definitions(-D_GLIBCXX_DEBUG)
        add_definitions(-D_GLIBCXX_DEBUG_PEDANTIC)
    endif()
endif()

if(!BASIC_USE_SYSTEM_FMT)
    add_definitions(-DFMT_HEADER_ONLY)
endif()
