/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _NME_PORTING_H
#define _NME_PORTING_H

// This entire file is mostly an implementation of the macros defined at http://sourceforge.net/p/predef/wiki/Home/

#if (defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
#  define NPORTING_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
#  define NPORTING_MACOSX
#elif defined(__linux__) || defined(__linux)
#  define NPORTING_LINUX
#elif defined(__FreeBSD__)
#  define NPORTING_FREEBSD
#elif defined(__NetBSD__)
#  define NPORTING_NETBSD
#elif defined(__OpenBSD__)
#  define NPORTING_OPENBSD
#elif defined(__DragonFly__)
#  define NPORTING_DRAGONFLY
#elif defined(__gnu_hurd__)
#  define NPORTING_HURD
#elif defined(sun) || defined(__sun)
#  if defined(__SVR4) || defined(__svr4__)
#    define NPORTING_SOLARIS
#  else
#    define NPORTING_SUNOS
#  endif
#endif


#if defined(__amd64__) || defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
#  define NPORTING_AMD64
#elif defined(__arm__) || defined(_ARM) || defined(_M_ARM)
#  define NPORTING_ARM
#  if defined(__thumb__) || defined(_M_ARMT)
#    define NPORTING_ARM_THUMB
#  endif
#elif defined(__aarch64__)
#  define NPORTING_ARM64
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(__IA32__) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL) || defined(__I86__) || defined(__INTEL__)
#  define NPORTING_IA32
#elif defined(__ia64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#  define NPORTING_IA64
#elif defined(__powerpc) || defined(_M_PPC) || defined(_ARCH_PPC) || defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || defined(_XENON)
#  define NPORTING_PPC
#elif defined(__sparc__) || defined(__sparc)
#  define NPORTING_SPARC
#endif

#if (__BYTE_ORDER == __BIG_ENDIAN) || defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__)
#  define NPORTING_BIG_ENDIAN
#else // Is this a good idea?
#  define NPORTING_LITTLE_ENDIAN
#endif

#ifdef NPORTING_WINDOWS
#  define NPORTING_SLASH "\\"
#else
#  define NPORTING_SLASH "/"
#endif

#if defined(NPORTING_WINDOWS) && !defined(NCORE_BUILD)
#  define main _main
#  define Nwin_main WinMain
int main(int argc, char** argv);
#endif

#endif
