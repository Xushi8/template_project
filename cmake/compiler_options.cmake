if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDBUG")
    # set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDBUG")
    
    # add_compile_options (-march=native)
    # add_link_options (-march=native)

    # add_compile_options (-mavx)
    # add_link_options (-mavx)
    # add_compile_options (-mavx2)
    # add_link_options (-mavx2)

    # warnings
    add_compile_options (-Wall -Wextra -pedantic -Wshadow -Wcast-qual -Wfloat-equal -Wredundant-decls -Wundef -Wpointer-arith)
    add_link_options (-Wall -Wextra -pedantic -Wshadow -Wcast-qual -Wfloat-equal -Wredundant-decls -Wundef -Wpointer-arith)


    # werrors
    
    add_compile_options (-ffast-math)
    add_link_options (-ffast-math)

    add_compile_options (-fdiagnostics-color=always)
    add_link_options (-fdiagnostics-color=always)
    
    
    add_compile_options (-fno-semantic-interposition -flto=auto -fuse-linker-plugin -pipe)
    add_link_options (-fno-semantic-interposition -flto=auto -fuse-linker-plugin -pipe)
    
    # PGO
    # add_compile_options (-fprofile-generate=pgo_files)
    # add_link_options (-fprofile-generate=pgo_files)
    
    # add_compile_options (-fprofile-use=pgo_files)
    # add_link_options (-fprofile-use=pgo_files)
    
    
    # add_compile_options (-fno-omit-frame-pointer -fsanitize=undefined)
    # add_link_options (-fno-omit-frame-pointer -fsanitize=undefined)
    # add_compile_options (-fsanitize=address)
    # add_link_options (-fsanitize=address)
    # add_compile_options (-fsanitize=thread)
    # add_link_options (-fsanitize=thread)
    
    # add_compile_options (-fopt-info)
    # add_link_options (-fopt-info)

    # add_compile_options (-save-temps=obj)
    # add_compile_options (-fverbose-asm)
    # add_compile_options (-masm=intel)
    # add_link_options (-save-temps=obj)
    # add_link_options (-fverbose-asm)
    # add_link_options (-masm=intel)
endif ()
    
    
    
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # add_compile_options (-fgraphite-identity -fdevirtualize-at-ltrans -fipa-pta)
    # add_link_options (-fgraphite-identity -fdevirtualize-at-ltrans -fipa-pta)
    # add_compile_options (-floop-nest-optimize)
    # add_link_options (-floop-nest-optimize)
endif()