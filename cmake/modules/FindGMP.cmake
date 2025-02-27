include(FindPackageHandleStandardArgs)

find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARIES NAMES gmp libgmp)
find_library(GMPXX_LIBRARIES NAMES gmpxx libgmpxx)

if(NOT GMP_INCLUDE_DIR OR NOT GMP_LIBRARIES)
    find_package_handle_standard_args(GMP REQUIRED_VARS GMP_INCLUDE_DIR GMP_LIBRARIES)
    mark_as_advanced(GMP_INCLUDE_DIR GMP_LIBRARIES)
    return()
endif()

set(GMP_FOUND TRUE)

add_library(GMP::gmp INTERFACE IMPORTED)
add_library(GMP::gmpxx INTERFACE IMPORTED)
set_target_properties(GMP::gmp PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${GMP_LIBRARIES}"
)
set_target_properties(GMP::gmpxx PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${GMPXX_LIBRARIES}"
)

find_package_handle_standard_args(GMP DEFAULT_MSG GMP_INCLUDE_DIR GMP_LIBRARIES GMPXX_LIBRARIES)

mark_as_advanced(GMP_INCLUDE_DIR GMP_LIBRARIES GMPXX_LIBRARIES)
