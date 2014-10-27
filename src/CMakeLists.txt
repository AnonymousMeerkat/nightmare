add_subdirectory(Core)
add_subdirectory(WMan)

set(SOURCES
    NPorting.c
    NWMan.c
    NRsc_misc.c
    NSplu.c
    NShader.c
    NSquare.c
    NIFF.c
    NImage.c
    NSprite.c
    NSpritesheet.c
    NEntity.c
    NShadow.c
    NLevel.c
    NEngine.c
    main.c
)

include_directories(${INCLUDES})

add_executable(nightmare ${SOURCES})
target_link_libraries(nightmare NCore NWMan ${LIBRARIES} gllg GLKit lodepng ${OPENGL_LIBRARIES} game)
