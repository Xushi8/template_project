add_library(test_lib "")

file(GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(test_lib
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories(test_lib
PUBLIC
./include
)

install(TARGETS test_lib)

install(DIRECTORY ./include/
        DESTINATION include)