find_path(MPFR_INCLUDE_DIR NAMES mpfr.h)
find_library(MPFR_LIBRARIES NAMES mpfr libmpfr)

if(NOT MPFR_INCLUDE_DIR OR NOT MPFR_LIBRARIES)
    find_package_handle_standard_args(GMP REQUIRED_VARS MPFR_INCLUDE_DIR MPFR_LIBRARIES)
    mark_as_advanced(MPFR_INCLUDE_DIR MPFR_LIBRARIES)
    return()
endif()

set(MPFR_FOUND TRUE)

add_library(MPFR::mpfr INTERFACE IMPORTED)
set_target_properties(MPFR::mpfr PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${MPFR_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${MPFR_LIBRARIES}"
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MPFR DEFAULT_MSG MPFR_INCLUDE_DIR MPFR_LIBRARIES)

mark_as_advanced(MPFR_INCLUDE_DIR MPFR_LIBRARIES)
