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


        GMP::gmp
        MPFR::mpfr
        RE2::re2
        PostgreSQL::PostgreSQL

        ${AVCODEC_LIBRARIES}
        ${AVDEVICE_LIBRARIES}
        ${AVFORMAT_LIBRARIES}
        ${AVFILTER_LIBRARIES}
        ${AVUTIL_LIBRARIES}
        ${POSTPROC_LIBRARIES}
        ${SWSCALE_LIBRARIES}

        # external
    )

endforeach(name ${BASIC_TARGETS})

install(TARGETS ${BASIC_TARGETS})
