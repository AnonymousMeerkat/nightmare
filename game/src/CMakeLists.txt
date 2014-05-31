add_custom_command(
    OUTPUT rscdata.c
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../rscdata.json
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/databuilder${CMAKE_EXECUTABLE_SUFFIX} ${CMAKE_CURRENT_SOURCE_DIR}/../rscdata.json -o rscdata.c
)

set(SOURCES
    rscdata.c
    main.c
)

include_directories(${INCLUDES})

add_library(game ${SOURCES})
