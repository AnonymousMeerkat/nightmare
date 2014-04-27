#include "yasl.h"

#include <stdlib.h>
#include "yutil.h"

YASLvar* YASLvar_new(enum YASLvar_type type) {
    YASLvar* var = (YASLvar*) malloc(sizeof(YASLvar));
    var->type = type;
    var->references = 1;

    return var;
}

void YASLvar_destroy(YASLvar* var) {
    // XXX: What if it's a list? Or a scope?
    free(var);
}

void YASLvar_inc(YASLvar* var) {
     var->references++;
}

void YASLvar_dec(YASLvar* var) {
    if (var->references == 0) { // This should never happen, but just in case...
        goto dead;
    }

    var->references--;

    if (var->references == 0) {
dead:
        YASLvar_destroy(var);
    }
}

#define set_x(type_, name) \
YASL_BOOL YASLvar_set_##name(YASLvar* var, type_ v_##name) {\
    if (var->type == YASLvar_##name) {\
        var->v_##name = v_##name;\
        return YASL_TRUE;\
    }\
    return YASL_FALSE;\
}

set_x(YASL_BOOL, bool);
set_x(YASL_FLOAT, float);
set_x(YASL_STRING, string);
set_x(YASLlist, list);
set_x(YASLscope, scope);

YASL_BOOL YASLvar_set(YASLvar* var, YASLvar* other) {
#define ycase(type)\
    case YASLvar_##type:\
        return YASLvar_set_##type(var, other->v_##type);\

    switch(other->type) {
        ycase(bool);
        ycase(float);
        ycase(string);
        ycase(list);
        ycase(scope);
        default:
            return YASL_FALSE;
    }

    return YASL_FALSE; // This should never run

#undef ycase
}


YASLlist* YASLlist_new() {
    YASLlist* list = (YASLlist*) malloc(sizeof(YASLlist));
    list->data = yrlist_new(sizeof(YASLvar*));
    yrlist_init(list->data, sizeof(YASLvar*), list->size);

    return list;
}

void YASLlist_destroy(YASLlist* list) {
    YASLlist_clear(list);
    yrlist_destroy(list->data);
    free(list);
}

void YASLlist_clear(YASLlist* list) {
    for (YASL_SIZE i = 0; i < list->size; i++) {
        YASLvar_dec(list->data[i]);
    }
}

void YASLlist_push(YASLlist* list, YASLvar* item) {
    YASLvar_inc(item);
    yrlist_push(list->data, sizeof(YASLvar*), list->size, item);
}

void YASLlist_pop(YASLlist* list) {
    YASLvar_dec(list->data[list->size - 1]);
    yrlist_pop(list->data, sizeof(YASLvar*), list->size);
}


YASLvarpair* YASLvarpair_new(YASL_STRING name, YASLvar* var) {
    YASLvarpair* pair = (YASLvarpair*) malloc(sizeof(YASLvarpair));
    pair->name = name;
    pair->var = var;

    return pair;
}

void YASLvarpair_destroy(YASLvarpair* pair) {
    YASLvar_dec(pair->var);
    free(pair);
}


YASLtable* YASLtable_new() {
    YASLtable* table  = (YASLtable*) malloc(sizeof(YASLtable));
    table->data = yrlist_new(sizeof(YASLvarpair*));
    yrlist_init(table->data, sizeof(YASLvarpair*), table->size);

    return table;
}

void YASLtable_destroy(YASLtable* table) {
    for (YASL_SIZE i = 0; i < table->size; i++) {
        YASLvarpair_destroy(table->data[i]);
    }
    yrlist_destroy(table->data);
    free(table);
}

YASLvarpair* YASLtable_get_pair(YASLtable* table, char* name) {
    // XXX: We need an optimized hash function, working more or less upon this principle(ish):
    //
    // int fullhash = hash(name);
    // char cuthash = (char) fullhash;
    // YASLtable_hash* hash = table->data[cuthash];
    // ylist_new(YASLtable_hashdata*, temphash);
    // for (YASL_size i = 0; i < hash->size; i++) {
    //     if (fullhash == hash->data[i]->fullhash && hash->data[i]->data->name[0] == name[0]) {
    //         ylist_push(temphash, hash->data[i]);
    //     }
    // }
    // for (YASL_size i = 0; i < temphash->size; i++) {
    //     if (ystreq(ylist_get(temphash, i), name)) {
    //         return ylist_get(temphash, i);
    //     }
    // }
    for (YASL_SIZE i = 0; i < table->size; i++) {
        if (ystreq(table->data[i]->name, name)) {
            return table->data[i];
        }
    }
    return NULL;
}

YASLvar* YASLtable_get(YASLtable* table, char* name) {
    YASLvarpair* pair = YASLtable_get_pair(table, name);
    if (pair) {
        return pair->var;
    }
    return NULL;
}

void YASLtable_set(YASLtable* table, char* name, YASLvar* var) {
    YASLvarpair* pair = YASLtable_get_pair(table, name);
    if (!pair) {
        YASLvar_inc(var);
        yrlist_push(table->data, sizeof(YASLvarpair*), table->size, YASLvarpair_new(name, var));
    } else {
        YASLvar_dec(pair->var);
        YASLvar_inc(var);
        pair->var = var;
    }
}


YASLcommand* YASLcommand_new(enum YASLcommand_type type, YASLvarpair* lhs, YASLvarpair* rhs) {
    YASLcommand* command = (YASLcommand*) malloc(sizeof(YASLcommand));
    command->type = type;
    command->lhs = lhs;
    command->rhs = rhs;

    // I'm tired right now, but I _think_ we don't need to increase the variable references
    // for lhs and rhs

    return command;
}

void YASLcommand_destroy(YASLcommand* command) {
    free(command);
}

void YASLcommand_run(YASLcommand* command) {
    if (command->type == YASLcommand_assign) {
        if (!YASLvar_set(command->lhs->var, command->rhs->var)) {
            YASLvarpair_set(command->lhs->var, command->rhs->var); // TODO: IMPLEMENT THIS!
        }
    }
}
