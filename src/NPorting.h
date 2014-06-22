#ifndef _NME_PORTING_H
#define _NME_PORTING_H

#if (defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)) && !defined(WIN32)
#  define WIN32
#elif defined(__APPLE__) || defined(__MACH__)
#  define MACOSX
#elif defined(__linux__) || defined(__linux)
#  define LINUX
#elif defined(__FreeBSD__)
#  define FREEBSD
#endif

#ifdef WIN32
#  define N_SLASH "\\"
#else
#  define N_SLASH "/"
#endif

#ifdef WIN32
#  define main _main
#  define Nwin_main WinMain
#endif

int main(int argc, char** argv);

#endif
