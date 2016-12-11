#ifndef EXPRESSION_PARSER_H_INCLUDED
#define EXPRESSION_PARSER_H_INCLUDED


#include "character.h"
#include "array.h"
#include "Stream.h"


#define OPEN_BRACE  0xff


typedef struct
{
    Character *name;
    Byte       number;
}
Operation;


enum ExpressionNodeType
{
    BINARY_OPERATION = 1,
    UNARY_OPERATION  = 2,
    OPERAND          = 3
};


Array* parse_expression_in_infix_notation(Stream *input_stream,
                                          Array  *unary_operations,
                                          Array  *binary_operations,
                                          int    *binary_priorities,
                                          Byte   *language_parser,
                                          Byte* (*get_operand)(Byte *language_parser));

void print_expression_in_postfix_notation(Array *expression,
                                          Character *operations_translator,
                                          void(*print_operand)(Byte *operand));

#endif // EXPRESSION_PARSER_H_INCLUDED
