add_subdirectory(common)
add_subdirectory(test_lib)

# target_link_libraries(common PUBLIC test_lib)


set(BASIC_TARGETS
    test
    gen
    template_project
)

foreach(name ${BASIC_TARGETS})
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name}
    PUBLIC
        # src
        template_project_common
        template_project_test_lib

        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc

        # Boost::filesystem

        ${RE2_LIB}
        ${ABSL_BASE_LIB}

        ${GMP_LIB}
        ${MPFR_LIB}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )

endforeach(name ${BASIC_TARGETS})

install(TARGETS ${BASIC_TARGETS})
