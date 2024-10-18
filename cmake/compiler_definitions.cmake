if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D_GLIBCXX_DEBUG)
    add_definitions(-D_GLIBCXX_DEBUG_PEDANTIC)
    add_definitions(-D_FORTIFY_SOURCE=3)
endif()

add_definitions(-DFMT_HEADER_ONLY)
add_definitions(-DSPDLOG_FMT_EXTERNAL)
add_definitions(-DVCL_NAMESPACE=vectorclass)

# asio::io_context default construct CONCURRENCY is -1, which means to use the number of your cpu's logical threads, change it to 1 so it can do some optimizations.
add_definitions(-DASIO_CONCURRENCY_HINT_DEFAULT=1)

if(WIN32)
    add_definitions(-DNOMINMAX)
    add_definitions(-D_USE_MATH_DEFINES)
endif()

if(BUILD_SHARED_LIBS)
    add_definitions(-DBASIC_PROJECT_LIBRARY_SHARED)
else()
    add_definitions(-DBASIC_PROJECT_LIBRARY_STATIC)
endif()
