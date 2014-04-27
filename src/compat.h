#ifndef _SP_COMPAT_H
#define _SP_COMPAT_H

#ifdef __cplusplus
#  define CPP
#  define START_HEAD extern "C" {
#  define END_HEAD }
#else
#  define START_HEAD
#  define END_HEAD
#endif

#endif
