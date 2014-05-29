#ifndef _NME_LOG_H
#define _NME_LOG_H

#include "NCompat.h"

START_HEAD

int Ninfo(const char* fmt, ...);
int Ndebug(const char* fmt, ...);
int Nerror(const char* fmt, ...);
void Nnewline();

#ifndef NMEX
#  include "NGlobals.h"
#  define NINDENT(...) {\
      N_indent++;\
      __VA_ARGS__;\
      N_indent--;\
  }
#else
#  define NINDENT(...) {\
      NGlobals_indent_inc();\
      __VA_ARGS__;\
      NGlobals_indent_dec();\
  }
#endif

END_HEAD

#endif
