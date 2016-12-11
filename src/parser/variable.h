#ifndef PARSER_VARIABLE_H_INCLUDED
#define PARSER_VARIABLE_H_INCLUDED


 #include "parser.h"


typedef struct
{
    Array *body;
}
Function;


typedef struct
{
    char    *name;
    Pointer  shift;
}
Variable;


Variable* create_variable(String *name, Parser *parser);
Function* create_function(String *name, Parser *parser);


#endif // PARSER_VARIABLE_H_INCLUDED
