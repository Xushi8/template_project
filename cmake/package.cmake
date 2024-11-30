find_package(Threads REQUIRED)
find_package(TBB CONFIG REQUIRED COMPONENTS tbb)
find_package(mimalloc CONFIG REQUIRED)
find_package(PostgreSQL REQUIRED)

find_package(Boost 1.81.0 REQUIRED COMPONENTS headers)
if(BASIC_PROJECT_STATIC_EXTERNAL_LIB)
    set(Boost_USE_STATIC_LIBS ON)
endif()

find_package(RE2)

# Some package always dynamic link
# dynamic link begin
set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll" ".so")

find_package(GMP)
find_package(MPFR)

if(BASIC_PROJECT_ENABLE_GUI)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
endif()

find_package(SDL2 REQUIRED)

find_package(FFmpeg REQUIRED)

find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics audio)

if(BASIC_PROJECT_STATIC_EXTERNAL_LIB)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".a")
endif()
# dynamic link end
