add_subdirectory(common)
add_subdirectory(test_lib)

# target_link_libraries(common PUBLIC test_lib)


set(MY_TARGETS
    template_project
    test
    gen
)

foreach(name ${MY_TARGETS})
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name}
    PUBLIC
        # src
        common
        test_lib

        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc


        # Boost::filesystem

        ${RE2_LIB}

        ${GMP_LIB}
        ${MPFR_LIB}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )

endforeach(name ${MY_TARGETS})

install(TARGETS ${MY_TARGETS})

if(BASIC_USE_GUI)
    add_subdirectory(gui)

    add_executable(template_project_gui template_project_gui.cpp)
    target_link_libraries(template_project_gui
    PUBLIC
        # src
        common
        test_lib
        gui

        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc

        Qt6::Widgets

        # Boost::filesystem

        ${RE2_LIB}

        ${GMP_LIB}
        ${MPFR_LIB}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )

    install(TARGETS template_project_gui)
endif()