add_subdirectory(Core)
add_subdirectory(NOSAPI)
add_subdirectory(WMan)

set(SOURCES
    NPorting.c
    NOSAPI.c
    NWMan.c
    NRsc_misc.c
    NSplu.c
    NShader.c
    NSquare.c
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
target_link_libraries(nightmare NCore NOSAPI NWMan ${LIBRARIES} gllg ${OPENGL_LIBRARIES} game)
