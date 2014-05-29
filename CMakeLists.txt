# Settings

cmake_minimum_required(VERSION 2.6)
project(nme)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra -Wno-missing-braces -Wno-unknown-pragmas")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -O0 -g")

add_definitions(-D_BSD_SOURCE)

# Find libraries

find_package(OpenGL REQUIRED) # No OpenGL? NO ENGINE! HAHAHAHAHA ... ha
find_package(GLEW REQUIRED)
find_package(FreeImage REQUIRED)

set(LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${FreeImage_LIBRARIES})

find_package(SDL)

if(SDL_FOUND)
    set(LIBRARIES ${LIBRARIES} ${SDL_LIBRARY})
    add_definitions(-DSDL_FOUND)
endif(SDL_FOUND)

find_package(SDL2)

if(SDL2_FOUND)
    set(LIBRARIES ${LIBRARIES} ${SDL2_LIBRARY})
    add_definitions(-DSDL2_FOUND)
endif()

# Include 3rd party libraries

include_directories(3rdparty)

if(WIN32)
    include_directories(3rdparty/w32)
endif()

if(UNIX)
    set(LIBRARIES ${LIBRARIES} dl)
endif()

# Compile 3rd party libraries

add_subdirectory(3rdparty)

# Compile

include_directories(include)
add_subdirectory(game)
add_subdirectory(src)
