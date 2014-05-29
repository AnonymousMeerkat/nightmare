#include "NLog.h"

#include "NGlobals.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int _printf(FILE* f, const char* prepend, short indent, const char* append, const char* fmt, va_list args) {
    // Get the total length of the message
    va_list copy;
    va_copy(copy, args);
    int len = vsnprintf(NULL, 0, fmt, copy);
    va_end(copy);
    len++; // NULL character

    // Copy the message to a temporary buffer ("basic")
    char* basic = (char*) malloc(len);
    vsnprintf(basic, len, fmt, args);
    basic[len - 1] = 0;

    // Create a new buffer which contains the complete message
    len += strlen(prepend);
    len += indent;
    len += strlen(append);
    char* buf = (char*) malloc(len);
    strcpy(buf, prepend);
    char* space = (char*) malloc(indent + 1);
    memset(space, ' ', indent);
    space[indent] = 0;
    strcat(buf, space);
    strcat(buf, basic);
    strcat(buf, append);
    buf[len - 1] = 0;

    // Show the new message
    int ret = fputs(buf, f);
    fflush(f);

    // We don't want no memory leaks, now do we?
    free(space);
    free(basic);
    free(buf);

    // And finally, return an output similar to what printf would give
    return (ret > 0) ? len : ret;
}

#define func(name, stream, prepend, append) \
    int name(const char* fmt, ...) {\
        va_list args;\
        va_start(args, fmt);\
\
        int ret = _printf(stream, prepend, N_indent * 2, append, fmt, args);\
\
        va_end(args);\
\
        return ret;\
    }

func(Ninfo, stdout, "[INFO] ", "\n");
func(Ndebug, stdout, "[DEBUG] ", "\n");
func(Nerror, stderr, "[ERROR] ", "\n");

void Nnewline() {
    printf("\n");
    fflush(stdout);
}
