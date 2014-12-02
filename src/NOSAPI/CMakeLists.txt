if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SOURCES linux.c)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(SOURCES windows.c)
endif()

add_library(NOSAPI STATIC ${SOURCES})
