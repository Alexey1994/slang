#ifndef WHILE_H_INCLUDED
#define WHILE_H_INCLUDED

#include "../parser.h"
#include "../condition.h"


#define WHILE 4


typedef struct
{
    Array *condition;
    Array *body;
}
While;


Boolean parse_while(Parser *parser);

#endif // WHILE_H_INCLUDED
