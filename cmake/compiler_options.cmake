if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # add_compile_options(-march=native)

    # add_compile_options(-mavx)
    add_compile_options(-mavx2)
    add_compile_options(-mfma)
    # add_compile_options(-march=skylake)

    # warnings
    add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wcast-qual -Wfloat-equal -Wredundant-decls -Wundef -Wpointer-arith -Werror=return-type)
    add_compile_options(-Wconversion -Wsign-conversion)

    # optimize
    add_compile_options(-ffast-math -fno-semantic-interposition)
    add_compile_options(-flto=auto)
    # add_compile_options(-fno-rtti)
    
    # PGO
    # add_compile_options(-fprofile-generate=pgo_files)
    
    # add_compile_options(-fprofile-use=pgo_files)
    
    # add_compile_options(-fsanitize=undefined)
    # add_compile_options(-fsanitize=address)
    # add_compile_options(-fsanitize=thread)
    
    # add_compile_options(-fopt-info)

    # add_compile_options(-save-temps=obj)
    # add_compile_options(-masm=intel)
    # add_compile_options(-fverbose-asm)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # add_compile_options(-fgraphite-identity -fdevirtualize-at-ltrans -fipa-pta -fuse-linker-plugin)
    # add_compile_options(-floop-nest-optimize)
endif()


if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(BASIC_USE_MOLD)
        add_link_options(-fuse-ld=mold)
    endif()

    # add_link_options(-static-libstdc++)
    
    # add_link_options(-fsanitize=undefined)
    # add_link_options(-fsanitize=address)
    # add_link_options(-fsanitize=thread)
    
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

endif()