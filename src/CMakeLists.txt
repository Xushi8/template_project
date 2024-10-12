add_subdirectory(common)

# target_link_libraries(common PUBLIC test_lib)


set(BASIC_PROJECT_TARGETS
    test
    gen
    template_project
)

foreach(name ${BASIC_PROJECT_TARGETS})
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

    if(BASIC_PROJECT_STATIC_EXTERNAL_LIB)
        target_link_libraries(${name} PUBLIC SDL2::SDL2-static)
    else()
        target_link_libraries(${name} PUBLIC SDL2::SDL2)
    endif()

endforeach(name ${BASIC_PROJECT_TARGETS})

install(TARGETS ${BASIC_PROJECT_TARGETS})
