if(BASIC_PROJECT_ENABLE_STRICT_STL_CHECKS)
    add_definitions(-D_GLIBCXX_DEBUG)
    add_definitions(-D_GLIBCXX_DEBUG_PEDANTIC)
    add_definitions(-D_FORTIFY_SOURCE=2)

    add_definitions(-D_LIBCPP_DEBUG=2)
endif()

add_definitions(-DFMT_HEADER_ONLY)
add_definitions(-DSPDLOG_FMT_EXTERNAL)

# asio::io_context default construct CONCURRENCY is -1, which means to use the number of your cpu's logical threads, change it to 1 so it can do some optimizations.
# in later, this macro will be defined in module, not spread
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
