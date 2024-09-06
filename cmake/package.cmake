find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)
find_package(TBB CONFIG REQUIRED COMPONENTS tbb)
find_package(mimalloc CONFIG REQUIRED)

find_library(PQXX_LIB NAMES pqxx)
find_library(PQ_LIB NAMES pq)

if(BASIC_USE_GUI)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
endif()

if(BASIC_STATIC_EXTERNAL_LIB)
    set(Boost_USE_STATIC_LIBS ON)
endif()
find_package(Boost 1.81.0 REQUIRED COMPONENTS filesystem)

find_path(RE2_INCLUDE_DIR NAMES re2/re2.h)
find_library(RE2_LIB NAMES re2 libre2)
include_directories(${RE2_INCLUDE_DIR})

find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIB NAMES gmp libgmp)
include_directories(${GMP_INCLUDE_DIR})

find_path(MPFR_INCLUDE_DIR NAMES mpfr.h)
find_library(MPFR_LIB NAMES mpfr libmpfr)
include_directories(${MPFR_INCLUDE_DIR})
