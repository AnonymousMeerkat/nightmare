#ifndef _NME_COMPAT_H
#define _NME_COMPAT_H

#ifdef __cplusplus
#  define CPP
#  define START_HEAD extern "C" {
#  define END_HEAD }
#else
#  if (__STDC_VERSION__ < 201112L)
#    error("This game needs a C11-compliant compiler")
#  endif
#  define START_HEAD
#  define END_HEAD
#  include <stdbool.h>
#endif

// Idk where this is useful
#if 0
#  define inline __inline__
#endif

#endif
