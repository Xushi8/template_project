add_subdirectory(common)
add_subdirectory(util)

set(TARGETS
    template_project
)

foreach(name ${TARGETS})
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name}
    PUBLIC
        # src
        common
        util
        
        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc
        
        # Boost::system

        # ${GMP_LIBRARIES}
        # ${GMPXX_LIBRARIES}
        # ${MARIADB_LIBRARIES}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )

    target_include_directories(${name}
    PUBLIC
        # ${GMP_INCLUDE_DIR}
    )
endforeach(name ${TARGETS})

