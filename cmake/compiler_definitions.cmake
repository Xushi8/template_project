if(WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" )
        add_definitions(-D_GLIBCXX_DEBUG)
    endif()
endif()

message(${CMAKE_BUILD_TYPE})

message(${CMAKE_CXX_COMPILER_ID})

add_definitions(-DFMT_HEADER_ONLY)
