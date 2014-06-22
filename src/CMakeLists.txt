add_subdirectory(WMan)

set(SOURCES
    NGlobals.c
    NLog.c
    NPorting.c
    NWMan.c
    NRsc.c
    NRsc_misc.c
    NSplu.c
    NShader.c
    NSquare.c
    NImage.c
    NSprite.c
    NSpritesheet.c
    NEntity.c
    NEngine.c
    main.c
)

include_directories(${INCLUDES})

add_executable(nightmare ${SOURCES})
target_link_libraries(nightmare NWMan ${LIBRARIES} game)
