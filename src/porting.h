#ifndef _SP_PORTING_H
#define _SP_PORTING_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#  define WIN32
#elif defined(__APPLE__) || defined(__MACH__)
#  define MACOSX
#elif defined(__linux__) || defined(__linux)
#  define LINUX
#elif defined(__FreeBSD__)
#  define FREEBSD
#endif

#endif
