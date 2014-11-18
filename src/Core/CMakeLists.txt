set(SOURCES
    NArgs.c
    NLog.c
    NRsc.c
    NGlobals.c
    NIFF.c
    NDFF.c
)

add_definitions(-DNCORE_BUILD)
add_library(NCore STATIC ${SOURCES})
