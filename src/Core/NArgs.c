#include "NArgs.h"

#include <NGlobals.h>
#include <NDynamic_t.h>
#include <string.h>

NArg* NArgs_parse() {
    NLIST_NEW(NArg, args);

    for (int i = 1; i < N_argc; i++) {
        NArg curr;

        char* c = strchr(N_argv[i], '=');

        if (c) {
            curr.type = NARG_STR;
            *c = 0;
            curr.name = N_argv[i];
            curr.str_val = c + 1;
            NLIST_PUSH(args, curr);
        } else {
            curr.type = NARG_BOOL;
            curr.name = N_argv[i];
            curr.bool_val = true;
            NLIST_PUSH(args, curr);
        }
    }

    return args.data;
}
