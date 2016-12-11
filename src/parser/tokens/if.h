#ifndef IF_H_INCLUDED
#define IF_H_INCLUDED

#include "../parser.h"


#define IF 1


typedef struct
{
    Array *condition;
    Array *if_body;
    Array *else_body;
}
If;


Boolean parse_if(Parser *parser);

#endif // IF_H_INCLUDED
