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

#include <NDFF.h>

#include <NUtil.h>
#include <NDynamic_t.h>
#include <string.h>
#include <stdlib.h>

NDFFEntry_t* NDFFEntry_new(char type, char* name, uint32_t size, void* contents) {
    NDFFEntry_t* entry = malloc(sizeof(NDFFEntry_t));
    entry->type = type;
    entry->name = name;
    entry->size = size;
    entry->contents = (char*)contents;

    return entry;
}

bool NDFFEntry_destroy(NDFFEntry_t* entry) {
    bool collective_okayishness = true;
    if (entry->type == NDFF_DIR) {
        for (uint32_t i = 0; i < entry->size; i++) {
            if (!NDFFEntry_destroy(entry->entries[i])) {
                collective_okayishness = false;
            }
        }
        free(entry->entries);
    } else {
        free(entry->contents);
    }

    free(entry);

    return collective_okayishness;
}


NDFFEntry_t* NDFFEntry_get(NDFFEntry_t* entry, char* name) {
    if (entry->type != NDFF_DIR) {
        return NULL;
    }

    for (uint32_t i = 0; i < entry->size; i++) {
        if (NSTREQ(name, entry->entries[i]->name)) {
            return entry->entries[i];
        }
    }

    return NULL;
}

bool NDFFEntry_add(NDFFEntry_t* parent, NDFFEntry_t* child) {
    if (parent->type != NDFF_DIR) {
        return false;
    }

    NRLIST_PUSH(parent->entries, sizeof(NDFFEntry_t), parent->size, child);

    return true;
}

bool NDFFEntry_remove(NDFFEntry_t* parent, char* name) {
    if (parent->type != NDFF_DIR) {
        return false;
    }

    for (uint32_t i = 0; i < parent->size; i++) {
        if (NSTREQ(parent->entries[i]->name, name)) {
            NRLIST_REMOVE(parent->entries, sizeof(NDFFEntry_t), parent->size, i);
            return true;
        }
    }

    return false;
}


NDFFEntry_t* _NDFF_read_entry(NDFFREntry_t* entry) {
    NDFFEntry_t* ret = malloc(sizeof(NDFFEntry_t));

    ret->type = entry->type;
    ret->size = entry->size;
    ret->name = strdup(entry->contents);

    if (entry->type == NDFF_FILE) {
        ret->contents = malloc(ret->size);
        memcpy(ret->contents, entry->contents + entry->namesize + 1, entry->size);
    } else {
        NDFFEntry_t** entries = ret->contents = malloc(ret->size * sizeof(NDFFEntry_t*));
        for (uint32_t i = 0; i < ret->size; i++) {
            entries[i] = _NDFF_read_entry(((NDFFREntry_t*)entry->contents) + i);
        }
    }

    return ret;
}

NDFFEntry_t* NDFF_read(NDFFR_t* ndff) {
    if (ndff->magic != NDFF_MAGIC) {
        return NULL;
    }

    return _NDFF_read_entry((NDFFREntry_t*)ndff->contents);
}

// TODO: FINISH
void _NDFF_write_entry(NDFFEntry_t* entry, NDFFREntry_t** ret, size_t entries) {
    size_t namesize = strlen(entry->name);
    size_t entrysize = entry->size;
    if (entry->type == NDFF_DIR) {
        entrysize *= sizeof(NDFFREntry_t*);
    }
    NDFFREntry_t* our_entry = malloc(sizeof(NDFFREntry_t) + namesize + 1 + entrysize);

    our_entry->type = entry->type;
    our_entry->size = entry->size;
    our_entry->namesize = namesize;
    strcpy(our_entry->contents, entry->name);
    if (entry->type == NDFF_DIR) {

    }
    memcpy(our_entry->contents + namesize + 1, entry->contents, entry->size);
}

// TODO: FINISH
NDFFR_t* NDFF_write(NDFFEntry_t* entry) {
    NDFFREntry_t** entries = NULL;

    _NDFF_write_entry(entry, entries, 0);
}
