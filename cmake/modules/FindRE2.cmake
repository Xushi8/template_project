include(FindPackageHandleStandardArgs)

find_path(RE2_INCLUDE_DIR NAMES re2)
find_library(RE2_LIBRARIES NAMES re2 libre2)

if(NOT RE2_INCLUDE_DIR OR NOT RE2_LIBRARIES)
    find_package_handle_standard_args(RE2 REQUIRED_VARS RE2_INCLUDE_DIR RE2_LIBRARIES)
    mark_as_advanced(RE2_INCLUDE_DIR RE2_LIBRARIES)
    return()
endif()

set(RE2_FOUND TRUE)

add_library(RE2::re2 INTERFACE IMPORTED)
set_target_properties(RE2::re2 PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${RE2_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${RE2_LIBRARIES}"
)

find_package_handle_standard_args(RE2 DEFAULT_MSG RE2_INCLUDE_DIR RE2_LIBRARIES)

mark_as_advanced(RE2_INCLUDE_DIR RE2_LIBRARIES)
