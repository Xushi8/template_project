if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDBUG")
    # set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDBUG")
    
    # add_compile_options(-march=native)

    # add_compile_options(-mavx)
    # add_compile_options(-mavx2)

    # warnings
    add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wcast-qual -Wfloat-equal -Wredundant-decls -Wundef -Wpointer-arith)
    # add_compile_options(-Wsign-conversion)

    # werrors
    
    add_compile_options(-ffast-math)

    add_compile_options(-fdiagnostics-color=always)
    
    
    add_compile_options(-fno-semantic-interposition -flto=auto -fuse-linker-plugin -pipe)
    add_link_options(-fno-semantic-interposition -flto=auto -fuse-linker-plugin -pipe)

    add_link_options(-fuse-ld=mold)
    
    # PGO
    # add_compile_options(-fprofile-generate=pgo_files)
    
    # add_compile_options(-fprofile-use=pgo_files)
    
    
    # add_compile_options(-fno-omit-frame-pointer -fsanitize=undefined)
    # add_compile_options(-fsanitize=address)
    # add_compile_options(-fsanitize=thread)
    
    # add_compile_options(-fopt-info)

    # add_compile_options(-save-temps=obj)
    # add_compile_options(-masm=intel)
    # add_link_options(-fverbose-asm)
endif()
    
    
    
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # add_compile_options(-fgraphite-identity -fdevirtualize-at-ltrans -fipa-pta)
    # add_compile_options(-floop-nest-optimize)
endif()