set(SOURCES
    main.c
)

add_executable(fogbuilder ${SOURCES})
target_link_libraries(fogbuilder m)
