include(FindPackageHandleStandardArgs)

find_path(URING_INCLUDE_DIR NAMES liburing)
find_library(URING_LIBRARIES NAMES uring liburing)

if(NOT URING_INCLUDE_DIR OR NOT URING_LIBRARIES)
    find_package_handle_standard_args(URING REQUIRED_VARS URING_INCLUDE_DIR URING_LIBRARIES)
    mark_as_advanced(URING_INCLUDE_DIR URING_LIBRARIES)
    return()
endif()

set(URING_FOUND TRUE)

add_library(URING::uring INTERFACE IMPORTED)
set_target_properties(URING::uring PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${URING_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${URING_LIBRARIES}"
)

find_package_handle_standard_args(URING DEFAULT_MSG URING_INCLUDE_DIR URING_LIBRARIES)

mark_as_advanced(URING_INCLUDE_DIR URING_LIBRARIES)
