find_package(Threads REQUIRED)
find_package(TBB CONFIG REQUIRED COMPONENTS tbb)
find_package(mimalloc CONFIG REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(SDL2 REQUIRED)

find_package(Boost 1.81.0 REQUIRED)
if(BASIC_PROJECT_STATIC_EXTERNAL_LIB)
    set(Boost_USE_STATIC_LIBS ON)
endif()

if(BASIC_PROJECT_ENABLE_GUI)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
endif()

find_package(GMP)
find_package(MPFR)
find_package(RE2)


# FFmpeg always dynamic link
set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll" ".so")

find_package(FFmpeg REQUIRED)

if(BASIC_PROJECT_STATIC_EXTERNAL_LIB)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".a")
endif()
