add_library(template_project_test_lib "")

file(GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(template_project_test_lib
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories(template_project_test_lib
PUBLIC
./include
)

if(BUILD_SHARED_LIBS OR BASIC_INSTALL_STATIC_LIB)
    install(TARGETS template_project_test_lib)
endif()

install(DIRECTORY ./include/
        DESTINATION include)
