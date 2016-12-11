#ifndef PARSER_OPERAND_H_INCLUDED
#define PARSER_OPERAND_H_INCLUDED


#include "parser.h"


#define OPERAND_VARIABLE      0x01
#define OPERAND_STRUCTURE     0x02

#define FUNCTION_CALL '('
#define ARRAY_INDEX   '['
#define MAP_KEY       '.'


Array* parse_operand(Parser *parser);
Array* parse_expression_operand(Parser *parser);
void print_operand(Array *operand);


#endif // OPERAND_H_INCLUDED
