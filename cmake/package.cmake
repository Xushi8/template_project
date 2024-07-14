find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)
find_package(TBB CONFIG REQUIRED COMPONENTS tbb)
find_package(mimalloc CONFIG REQUIRED)

find_library(PQXX_LIB NAMES pqxx)
find_library(PQ_LIB NAMES pq)

if(BASIC_USE_GUI)
    find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets)
endif()

# set(Boost_USE_STATIC_LIBS ON)
# find_package(Boost 1.81.0 REQUIRED COMPONENTS system filesystem)

find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARIES NAMES gmp libgmp)
include_directories(${GMP_INCLUDE_DIR})

find_path(MPFR_INCLUDE_DIR NAMES mpfr.h)
find_library(MPFR_LIBRARIES NAMES mpfr libmpfr)
include_directories(${MPFR_INCLUDE_DIR})

find_package(OpenCL REQUIRED)