#ifndef PARSER_EXPRESSION_H_INCLUDED
#define PARSER_EXPRESSION_H_INCLUDED

#include "../lib/array.h"
#include "parser.h"


#define UNARY_MINUS 2

#define BINARY_PLUS 0


Array* parse_expression(Parser *parser);
void print_expression(Array *expression);


#endif // PARSER_EXPRESSION_H_INCLUDED
