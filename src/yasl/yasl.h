#ifndef _YASL_H
#define _YASL_H

#ifdef __cplusplus
#  define YASL_BOOL bool
extern "C" {
#  define YASLEND }
#  define YASL_TRUE true
#  define YASL_FALSE false
#else
#  define YASL_BOOL _Bool
#  define YASL_TRUE 1
#  define YASL_FALSE 0
#  define YASLEND
#endif

#ifdef YASL_DOUBLE
#  define YASL_FLOAT double
#else
#  define YASL_FLOAT float
#endif

#define YASL_STRING char*

#define YASL_SIZE unsigned long // Just because I'm sick of writing it

#define yts(x) typedef struct x x

yts(YASLvar);
yts(YASLlist);
yts(YASLvarpair);
yts(YASLtable);
yts(YASLcommand);
yts(YASLscope);

#undef yts

struct YASLlist {
    YASL_SIZE size; // Does anyone care how big this is? No? Good XD
    YASLvar** data;
};

struct YASLvarpair {
    YASL_STRING name;
    YASLvar* var;
};

struct YASLtable {
    YASL_SIZE size;
    YASLvarpair** data;
};

enum YASLcommand_type {
    YASLcommand_type_assign = 0,
    YASLcommand_type_run = 1
};

struct YASLcommand {
    enum YASLcommand_type type;

    YASLvarpair* lhs;
    YASLvarpair* rhs;
};

struct YASLscope {
    YASLtable table;

    YASL_SIZE commands_size;
    YASLcommand** commands;
};

enum YASLvar_type {
    YASLvar_type_bool = 0,
    YASLvar_type_float = 1,
    YASLvar_type_string  = 2,
    YASLvar_type_list = 3,
    YASLvar_type_scope = 4
};

struct YASLvar {
    enum YASLvar_type type;

    union {
        YASL_BOOL v_bool;
        YASL_FLOAT v_float;
        YASL_STRING v_string;
        YASLlist v_list;
        YASLscope v_scope;
    };

    unsigned int references;
};

YASLEND

#endif
