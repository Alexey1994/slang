#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

#include "../parser.h"

#define LOOP 7


typedef struct
{
    Array *body;
}
Loop;


Boolean parse_loop(Parser *parser);

#endif // LOOP_H_INCLUDED
