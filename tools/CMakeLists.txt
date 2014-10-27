add_definitions(-DNCORE_BUILD)

add_subdirectory(vecmathbuilder)
add_subdirectory(ngloptbuilder)
add_subdirectory(fogbuilder)
add_subdirectory(niffconv)

set(SOURCES
    main.c
)

add_executable(nightmaretool ${SOURCES})
target_link_libraries(nightmaretool vecmathbuilder ngloptbuilder fogbuilder niffconv m NCore ${TOOLS_LIBRARIES})
