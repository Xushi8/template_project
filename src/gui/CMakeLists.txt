add_library(template_project_gui "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB_RECURSE header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(template_project_gui
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_link_libraries(template_project_gui PRIVATE Qt6::Core Qt6::Widgets)

target_include_directories(template_project_gui 
PUBLIC
./include
)

# 使用这个链接参数可以保证全局变量也被导出到静态库
# if(NOT BUILD_SHARED_LIBS)
#     target_compile_options(template_project_gui PRIVATE -Wl,--whole-archive)
#     target_link_options(template_project_gui PRIVATE -Wl,--whole-archive)
# endif()

if(BUILD_SHARED_LIBS OR BASIC_PROJECT_INSTALL_STATIC_LIB)
    install(TARGETS template_project_gui)
endif()

install(DIRECTORY ./include/
        DESTINATION include)
