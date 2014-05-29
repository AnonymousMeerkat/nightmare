set(SOURCES
    main.c
)

include_directories(${INCLUDES})

add_library(game ${SOURCES})
