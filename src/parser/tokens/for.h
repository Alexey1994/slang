#ifndef FOR_H_INCLUDED
#define FOR_H_INCLUDED

#include "../parser.h"


#define FOR 6


typedef struct
{
    Array *condition_body;
    Array *iterator_expression;
}
For;


Boolean parse_for(Parser *parser);

#endif // FOR_H_INCLUDED
