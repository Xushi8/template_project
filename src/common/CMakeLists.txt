add_library(template_project_common "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB_RECURSE header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(template_project_common
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories(template_project_common 
PUBLIC
./include
)

# 使用这个链接参数可以保证全局变量也被导出到静态库
# if(NOT BUILD_SHARED_LIBS)
#     target_compile_options(template_project_common PRIVATE -Wl,--whole-archive)
#     target_link_options(template_project_common PRIVATE -Wl,--whole-archive)
# endif()

if(BUILD_SHARED_LIBS OR BASIC_PROJECT_INSTALL_STATIC_LIB)
    install(TARGETS template_project_common)
endif()

install(DIRECTORY ./include/
        DESTINATION include)
