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
        # Boost::filesystem

        ${GMP_LIBRARIES}
        ${MPFR_LIBRARIES}        

        ${PQ_LIB}
        ${PQXX_LIB}

        OpenCL::OpenCL

        # external
    )

    if(BASIC_USE_GUI)
        target_link_libraries(${name} 
        PUBLIC
            Qt6::Widgets
        )
    endif()

endforeach(name ${TARGETS})

