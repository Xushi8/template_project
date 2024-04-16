add_executable (${PROJECT_NAME} main.cpp)

add_subdirectory (my_basic_library)

target_link_libraries (${PROJECT_NAME}
PUBLIC
    # src
    my_basic_library
    
    # package
    Threads::Threads
    OpenMP::OpenMP_CXX
    TBB::tbb
    # Boost::system

    # ${GMP_LIBRARIES}
    # ${GMPXX_LIBRARIES}
    # ${MARIADB_LIBRARIES}

    # external
)

target_include_directories (${PROJECT_NAME}
PUBLIC
    # ${GMP_INCLUDE_DIR}
)
