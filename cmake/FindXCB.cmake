# - Try to find libxcb
# Once done this will define
#
#  XCB_FOUND - system has libxcb
#  XCB_LIBRARIES - Link these to use libxcb
#  XCB_INCLUDE_DIR - the libxcb include dir
#  XCB_DEFINITIONS - compiler switches required for using libxcb

# Copyright (c) 2008 Helio Chissini de Castro, <helio@kde.org>
# Copyright (c) 2007, Matthias Kretz, <kretz@kde.org>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.


IF (NOT WIN32)
  IF (XCB_INCLUDE_DIR AND XCB_LIBRARIES)
    # in cache already
    SET(XCB_FIND_QUIETLY TRUE)
  ENDIF (XCB_INCLUDE_DIR AND XCB_LIBRARIES)

  # use pkg-config to get the directories and then use these values
  # in the FIND_PATH() and FIND_LIBRARY() calls
  FIND_PACKAGE(PkgConfig)
  PKG_CHECK_MODULES(PKG_XCB xcb)

  SET(LIBXCB_DEFINITIONS ${PKG_XCB_CFLAGS})

  FIND_PATH(XCB_INCLUDE_DIR xcb/xcb.h
    ${PKG_XCB_INCLUDE_DIRS}
    )

  FIND_LIBRARY(XCB_LIBRARIES NAMES xcb libxcb
    PATHS
    ${PKG_XCB_LIBRARY_DIRS}
    )

  include(FindPackageHandleStandardArgs)
  FIND_PACKAGE_HANDLE_STANDARD_ARGS(XCB DEFAULT_MSG XCB_INCLUDE_DIR XCB_LIBRARIES )


  MARK_AS_ADVANCED(XCB_INCLUDE_DIR XCB_LIBRARIES XCBPROC_EXECUTABLE)
ENDIF (NOT WIN32)
