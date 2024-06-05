add_library(common "")

file(GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(common
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_include_directories(common 
PUBLIC
./include
${PROJECT_SOURCE_DIR}/common/include
)
