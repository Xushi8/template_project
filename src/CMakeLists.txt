add_subdirectory(common)

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

        # package
        Threads::Threads
        TBB::tbb
        mimalloc


        ${RE2_LIB}

        ${GMP_LIB}
        ${MPFR_LIB}

        ${PQ_LIB}

        # external
    )

endforeach(name ${BASIC_TARGETS})

install(TARGETS ${BASIC_TARGETS})
