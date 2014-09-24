add_definitions(-DNCORE_BUILD)

add_subdirectory(ngloptbuilder)
add_subdirectory(fogbuilder)

set(SOURCES
    main.c
)

add_executable(nightmaretool ${SOURCES})
target_link_libraries(nightmaretool ngloptbuilder fogbuilder m NCore)
