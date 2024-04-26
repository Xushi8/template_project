add_library(my_basic_library "")

file(GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(my_basic_library
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories(my_basic_library 
PUBLIC
./include
)
