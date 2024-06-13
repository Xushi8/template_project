add_library(util "")

file(GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(util
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories(util 
PUBLIC
./include
)
