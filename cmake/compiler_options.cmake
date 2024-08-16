if (MSVC)
    add_compile_options(/Zc:preprocessor /utf-8 /DNOMINMAX /D_USE_MATH_DEFINES /EHsc /bigobj)
else()
    if (WIN32)
        add_compile_options(-finput-charset=utf-8 -fexec-charset=utf-8)
    endif()
endif()



if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

    add_compile_options(-mavx2)
    add_compile_options(-mfma)

    # warnings
    add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wcast-qual -Wfloat-equal -Wredundant-decls -Wundef -Wpointer-arith -Werror=return-type -Wimplicit-fallthrough)
    # add_compile_options(-Wconversion -Wsign-conversion)

    # optimize
    add_compile_options(-ffast-math -fno-semantic-interposition)
    add_compile_options(-flto=auto)
    # add_compile_options(-fno-rtti)

    # PGO
    # add_compile_options(-fprofile-generate=pgo_files)

    # add_compile_options(-fprofile-use=pgo_files)

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-fsanitize=undefined)
        # add_compile_options(-fsanitize=address)
        # add_compile_options(-fsanitize=thread)
    endif()

endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # add_compile_options(-fgraphite-identity -fdevirtualize-at-ltrans -fipa-pta -fuse-linker-plugin)
    # add_compile_options(-floop-nest-optimize)
endif()


if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(BASIC_USE_MOLD)
        add_link_options(-fuse-ld=mold)
    endif()

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_link_options(-fsanitize=undefined)
        # add_link_options(-fsanitize=address)
        # add_link_options(-fsanitize=thread)
    endif()

endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

endif()