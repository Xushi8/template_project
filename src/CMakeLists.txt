add_subdirectory(common)
add_subdirectory(util)

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
        
        # package
        Threads::Threads
        OpenMP::OpenMP_CXX
        TBB::tbb
        mimalloc
        
        # Boost::system

        pqxx

        # ${GMP_LIBRARIES}
        # ${GMPXX_LIBRARIES}
        # ${MARIADB_LIBRARIES}

        # ${PQ_LIB}
        # ${PQXX_LIB}

        # external
    )

    if(BASIC_USE_GUI)
        target_link_libraries(${name} 
        PUBLIC
            Qt6::Widgets
        )
    endif()

    target_include_directories(${name}
    PUBLIC
        # ${GMP_INCLUDE_DIR}
    )
endforeach(name ${TARGETS})

