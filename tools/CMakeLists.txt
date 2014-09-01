add_definitions(-DNCORE_BUILD)

add_subdirectory(ngloptbuilder)
add_subdirectory(databuilder)
add_subdirectory(fogbuilder)

set(SOURCES
    main.c
)

add_executable(nightmaretool ${SOURCES})
target_link_libraries(nightmaretool ngloptbuilder databuilder jansson fogbuilder m NCore)
