#ifndef DO_H_INCLUDED
#define DO_H_INCLUDED

#include "../parser.h"

#define DO 5


typedef struct
{
    Array *body;
    Array *condition;
}
Do;


Boolean parse_do(Parser *parser);

#endif // DO_H_INCLUDED
