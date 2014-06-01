Nightmare Engine
================

## About ##

Nightmare was created by Anonymous Meerkat for Ule's Silent Ponyville. Because of this, this is not a generic game engine, and is specialized for making games similar to Silent Ponyville.

## Prerequisites ##

You'll need these following tools/libraries:

  * CMake (and a build system that cmake can generate to)
  * SDL 1 or 2
  * OpenGL
  * FreeImage
  * Jansson (for the "databuilder" tool)

## Compiling ##

Put a Nightmare game source (e.g. https://github.com/Anonymous Meerkat/silentponyville ) in the "game" directory, then run:

    mkdir build && cd build
    cmake ..
    make

## Running ##

Executable is in bin/nightmare
