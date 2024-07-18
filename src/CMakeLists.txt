add_subdirectory(common)
add_subdirectory(util)
add_subdirectory(test_lib)

set(TARGETS
    template_project
    test
)

foreach(name ${TARGETS})
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name}
    PUBLIC
        # src
        common
        util
        test_lib

        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc

        # Boost::system
        # Boost::filesystem

        ${GMP_LIBRARIES}
        ${MPFR_LIBRARIES}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )

endforeach(name ${TARGETS})

