/*
    Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
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

#include "NRsc.h"

#include "NGlobals.h"
#include "NLog.h"

#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "NDynamic_t.h"
#include <dirent.h>

#if defined(NPORTING_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#elif defined(NPORTING_MACOSX)
#  include <mach-o/dyld.h>
#elif defined(NPORTING_FREEBSD)
#  include <sys/types.h>
#  include <sys/sysctl.h>
#endif

#ifndef PATH_MAX
#  define PATH_MAX 4096
#endif

bool NRsc_init() {
    char exepath[PATH_MAX];

#if defined(NPORTING_WINDOWS)
    GetModuleFileName(GetModuleHandle(NULL), exepath, PATH_MAX);
#elif defined(NPORTING_LINUX)
    char* result = realpath("/proc/self/exe", exepath);
    if (!result) {
        Nerror("Can't figure out self path!");
        return false;
    }
#elif defined(NPORTING_MACOSX)
    int size = PATH_MAX;
    if (_NSGetExecutablePath(exepath, &size)) {
        Nerror("Path buffer of size %i too small!", PATH_MAX);
    }
#elif defined(NPORTING_FREEBSD)
    int mib[4];
    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PATHNAME;
    mib[3] = -1;
    size_t size = PATH_MAX;
    sysctl(mib, 4, exepath, &size, NULL, 0);
#endif

    char* toppath = dirname(dirname(exepath));
    N_rsc_path = malloc(strlen(toppath) + 7);
    strcpy(N_rsc_path, toppath);
    strcat(N_rsc_path, NPORTING_SLASH "game");
    Ndebug("Game data directory: %s", N_rsc_path);
    return true;
}

void NRsc_destroy() {
    free(N_rsc_path);
}

// FREE
char* NRsc_join_paths(char* path1, char* path2) {
    char* newpath = malloc(strlen(path1) + strlen(path2) + 2);
    strcpy(newpath, path1);
    strcat(newpath, NPORTING_SLASH);
    strcat(newpath, path2);
    return newpath;
}

// FREE
char* NRsc_remove_ext(char* path) {
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

char* NRsc_get_ext(char* path) {
    return strrchr(path, '.') + 1;
}

// FREE
char* NRsc_get_path(char* simplepath) {
    char* newpath = malloc(strlen(N_rsc_path) + strlen(simplepath) + 2);
    strcpy(newpath, N_rsc_path);
    strcat(newpath, NPORTING_SLASH);
    strcat(newpath, simplepath);
    return newpath;
}

char** NRsc_ls(char* simplepath) {
    NLIST_NEW(char*, ret);

    char* path = NRsc_get_path(simplepath);
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
        NLIST_PUSH(ret, curname);
    }
    closedir(dir);
    return ret.data;
}

#if 0
// One liner, because boredom XD
// Warns about ignoring the value of realloc (harmless), so that's why I'm using the longer version instead
void NRsc_ls_free(char**a){for(long j,i=0;!(((!(j=(long)a[i]))||(((long)realloc((char*)j,0))&0))&&(!(((long)realloc(a,0))&0)));i++);}
#else
void NRsc_ls_free(char** lsd) {
    char* file;
    for (int i = 0; (file = lsd[i]); i++) {
        free(file);
    }
    free(lsd);
}
#endif

char* NRsc_read_file_rp(char* path) {
    Ndebug("Loading file '%s'", path);
    N_indent++;

    char* ret = NULL;

    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        Nerror("Error opening file!");
        goto end;
    }

    fseek (file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind (file);

    ret = malloc(file_size + 1);
    memset(ret, 0, file_size + 1);
    size_t n_read = fread(ret, 1, file_size, file);
    if (n_read != file_size) {
        Nerror("Error reading file!");
        free(ret);
        ret = NULL;
        goto closefile;
    }

closefile:
    fclose(file);
end:
    N_indent--;
    return ret;
}

char* NRsc_read_file(char* simplepath) {
    char* path = NRsc_get_path(simplepath);
    char* ret = NRsc_read_file_rp(path);
    free(path);

    return ret;
}
