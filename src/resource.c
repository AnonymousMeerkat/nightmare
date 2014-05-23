#include "resource.h"

#include "globals.h"
#include "log.h"

#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "wrap/limits.h"
#include <string.h>
#include "yasl/yutil.h"
#include <dirent.h>

#ifdef WIN32
#  include <windows.h>
#endif

bool rsc_init() {
    char exepath[PATH_MAX + 1];
#ifdef WIN32
    GetModuleFileName(GetModuleHandle(NULL), exepath, PATH_MAX);
#else
    char* result = realpath("/proc/self/exe", exepath);
    if (!result) {
        error("Can't figure out self path!");
        return false;
    }
#endif
    char* toppath = dirname(dirname(exepath));
    rsc_path = malloc(strlen(toppath) + 5);
    strcpy(rsc_path, toppath);
    strcat(rsc_path, SLASH "rsc");
    debug(rsc_path);
    return true;
}

void rsc_destroy() {
    free(rsc_path);
}

// FREE
char* rsc_join_paths(char* path1, char* path2) {
    char* newpath = malloc(strlen(path1) + strlen(path2) + 2);
    strcpy(newpath, path1);
    strcat(newpath, SLASH);
    strcat(newpath, path2);
    return newpath;
}

// FREE
char* rsc_remove_ext(char* path) {
    char* dot = strrchr(path, '.');
    size_t dot_pos;
    if (dot == NULL) {
        dot_pos = strlen(path);
    } else {
        dot_pos = dot - path;
    }
    char* ret = malloc(dot_pos + 1);
    strncpy(ret, path, dot_pos);
    ret[dot_pos] = 0;
    return ret;
}

// FREE
char* rsc_get_path(char* simplepath) {
    char* newpath = malloc(strlen(rsc_path) + strlen(simplepath) + 2);
    strcpy(newpath, rsc_path);
    strcat(newpath, SLASH);
    strcat(newpath, simplepath);
    return newpath;
}

char** rsc_ls(char* simplepath) {
    ylist_new(char*, ret);

    char* path = rsc_get_path(simplepath);
    DIR* dir = opendir(path);
    free(path);

    struct dirent* entry;
    char* curname;
    while ((entry = readdir(dir)) != NULL) {
        // Checks if it's "." or ".."
        if (entry->d_name[0] == '.' && (entry->d_name[1] == 0 || (entry->d_name[1] == '.' && entry->d_name[2] == 0))) {
            continue;
        }
        curname = malloc(strlen(entry->d_name) + 1);
        strcpy(curname, entry->d_name);
        ylist_push(ret, curname);
    }
    closedir(dir);
    return ret.data;
}

#if 0
// One liner, because boredom XD
// Warns about ignoring the value of realloc (harmless), so that's why I'm using the longer version instead
void rsc_ls_free(char**a){for(long j,i=0;!(((!(j=(long)a[i]))||(((long)realloc((char*)j,0))&0))&&(!(((long)realloc(a,0))&0)));i++);}
#else
void rsc_ls_free(char** lsd) {
    char* file;
    for (int i = 0; (file = lsd[i]); i++) {
        free(file);
    }
    free(lsd);
}
#endif

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
    memset(ret, 0, file_size);
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
