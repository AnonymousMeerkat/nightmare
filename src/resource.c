#include "resource.h"

#include "globals.h"
#include "log.h"

#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "wrap/limits.h"
#include <string.h>

bool rsc_init() {
    char exepath[PATH_MAX + 1];
    char* result = realpath("/proc/self/exe", exepath);
    if (!result) {
        error("Can't figure out self path!");
        return false;
    }
    char* toppath = dirname(dirname(exepath));
    rsc_path = malloc(strlen(toppath) + 5);
    strcpy(rsc_path, toppath);
    strcat(rsc_path, "/rsc");
    debug(rsc_path);
    return true;
}

void rsc_destroy() {
    free(rsc_path);
}

// free() this path after its used!!
char* rsc_get_path(char* simplepath) {
    char* newpath = malloc(strlen(rsc_path) + strlen(simplepath) + 2);
    strcpy(newpath, rsc_path);
    strcat(newpath, "/");
    strcat(newpath, simplepath);
    return newpath;
}

char* rsc_read_file(char* simplepath) {
    char* path = rsc_get_path(simplepath);
    FILE* file = fopen(path, "r");
    free(path);
    if (file == NULL) {
        error("Error loading file!");
        return NULL;
    }

    fseek (file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind (file);

    char* ret = malloc(file_size + 1);
    size_t n_read = fread(ret, 1, file_size, file);
    if (n_read != file_size) {
        error("Error reading file!");
        return NULL;
    }
    ret[file_size] = 0;
    debug(ret);
    fclose(file);
    ret = realloc(ret, strlen(ret)); // Save memory
    return ret;
}
