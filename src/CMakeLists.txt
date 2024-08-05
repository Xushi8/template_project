add_subdirectory(common)
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
        test_lib

        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc


        # Boost::filesystem

        ${RE2_LIBRARIES}

        ${GMP_LIBRARIES}
        ${MPFR_LIBRARIES}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )

endforeach(name ${TARGETS})

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

        ${RE2_LIBRARIES}

        ${GMP_LIBRARIES}
        ${MPFR_LIBRARIES}

        ${PQ_LIB}
        ${PQXX_LIB}

        # external
    )
endif()