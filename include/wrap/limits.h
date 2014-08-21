#ifndef _NME_WRAP_LIMITS_H
#define _NME_WRAP_LIMITS_H

#ifdef __linux
#  include <linux/limits.h>
#else
#  define PATH_MAX 4096 // Running 'cat /usr/include/linux/limits.h | grep PATH' gives me this...
#endif

#endif
