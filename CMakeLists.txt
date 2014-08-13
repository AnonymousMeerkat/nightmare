# Settings

cmake_minimum_required(VERSION 2.6)
project(nme)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -Wall -Wextra -Wno-missing-braces -Wno-unknown-pragmas -Wno-override-init")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -O0 -g")

add_definitions(-D_BSD_SOURCE)

# Find libraries

set(LIBRARIES m ${LIBRARIES})
if(WIN32)
    set(CMAKE_LIBRARY_PATH "${CMAKE_LIBRARY_PATH};${PROJECT_SOURCE_DIR}/3rdparty/w32")
    set(CMAKE_INCLUDE_PATH "${CMAKE_INCLUDE_PATH};${PROJECT_SOURCE_DIR}/3rdparty/w32")
endif(WIN32)

if(UNIX)
    set(CMAKE_INCLUDE_PATH "${CMAKE_INCLUDE_PATH}:/usr/local/include")
endif(UNIX)

find_package(OpenGL REQUIRED) # No OpenGL? NO ENGINE! HAHAHAHAHA ... ha

set(WM_FOUND 0)

find_package(Wayland)

if(WAYLAND_FOUND)
    find_package(UDev REQUIRED)
    find_package(EGL REQUIRED)
    set(LIBRARIES ${LIBRARIES} ${WAYLAND_LIBRARIES} ${UDEV_LIBRARIES} ${EGL_LIBRARY})
    add_definitions(-DWL_FOUND -DUSE_EGL)
    set(WM_FOUND 1)
    set(WL_FOUND 1)
endif(WAYLAND_FOUND)

find_package(X11)

if(X11_FOUND)
    set(LIBRARIES ${LIBRARIES} ${X11_LIBRARIES})
    add_definitions(-DX11_FOUND)
    set(WM_FOUND 1)
endif(X11_FOUND)

find_package(SDL)

if(SDL_FOUND)
    set(LIBRARIES ${LIBRARIES} ${SDL_LIBRARY})
    add_definitions(-DSDL_FOUND)
    set(WM_FOUND 1)
endif(SDL_FOUND)

find_package(SDL2)

if(SDL2_FOUND)
    set(LIBRARIES ${LIBRARIES} ${SDL2_LIBRARY})
    add_definitions(-DSDL2_FOUND)
    set(WM_FOUND 1)
endif(SDL2_FOUND)

if(NOT WM_FOUND)
    message(FATAL_ERROR "Please install either SDL or SDL2!")
endif(NOT WM_FOUND)

# Include 3rd party libraries

include_directories(3rdparty)

if(WIN32)
    include_directories(3rdparty/w32)
endif(WIN32)

if(UNIX)
    if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
        include_directories(/usr/local/include)
        set(LIBRARIES ${LIBRARIES} c)
    else()
        set(LIBRARIES ${LIBRARIES} dl)
    endif()
endif(UNIX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Compile 3rd party libraries

add_subdirectory(3rdparty)
include_directories(3rdparty/jansson/include)
include_directories(3rdparty/gllg/out)
include_directories(3rdparty/lodepng)

set(LIBRARIES ${LIBRARIES} gllg GLKit lodepng ${OPENGL_LIBRARIES})

# Compile tools

add_subdirectory(tools)

# Compile

include_directories(include)
add_subdirectory(game)
add_subdirectory(src)
