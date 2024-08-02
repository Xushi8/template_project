add_library(gui "")

file(GLOB sources CONFIGURE_DEPENDS src/*.c src/*.cpp)
file(GLOB header CONFIGURE_DEPENDS include/*.h include/*.hpp)

target_sources(gui
PRIVATE
    ${sources}
PUBLIC
    ${header}
)

target_link_libraries(gui PUBLIC Qt6::Widgets)

target_include_directories(gui
PUBLIC
./include
)
