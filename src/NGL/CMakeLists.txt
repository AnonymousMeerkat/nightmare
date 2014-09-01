add_custom_command(
    OUTPUT params.h
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/NGL.h
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/nightmaretool${CMAKE_EXECUTABLE_SUFFIX} ngloptbuilder ${CMAKE_CURRENT_SOURCE_DIR}/../../include/NGL.h params.h
)

set(SOURCES
    params.h
    common.c
)

add_library(NGL ${SOURCES})
