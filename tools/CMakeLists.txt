add_definitions(-DNCORE_BUILD)

add_subdirectory(vecmathbuilder)
add_subdirectory(fogbuilder)
add_subdirectory(niffconv)
add_subdirectory(niffflip)

set(SOURCES
    main.c
)

add_executable(nightmaretool ${SOURCES})
target_link_libraries(nightmaretool vecmathbuilder fogbuilder niffconv niffflip m NCore ${TOOLS_LIBRARIES})
