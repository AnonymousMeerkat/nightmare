set(SOURCES
    main.c
)

add_executable(databuilder ${SOURCES})
target_link_libraries(databuilder jansson)
