#include "expression.h"

#include "../lib/expression parser.h"
#include "operand.h"


Operation* create_operation(Character *name, Byte number)
{
    Operation *operation = new(Operation);

    operation->name   = name;
    operation->number = number;

    return operation;
}


void destroy_operation(Operation *operation)
{
    free(operation);
}


static Character* get_operations_translator()
{
    static Character *codes = 0;

    if(codes)
        return codes;

    codes = malloc(256);

    codes[BINARY_PLUS] = '+';
    //codes[BINARY_MUL]  = '*';
    codes[UNARY_MINUS] = '-';

    return codes;
}


void print_expression(Array *expression)
{
    print_expression_in_postfix_notation(expression, get_operations_translator(), print_operand);
}


static Array* get_unary_operations()
{
    static Array *unary_operations = 0;

    if(unary_operations)
        return unary_operations;

    unary_operations = create_array(1, destroy_operation);

    push_in_array(unary_operations, create_operation("-", UNARY_MINUS));

    return unary_operations;
}


static Array* get_binary_operations()
{
    static Array *binary_operations = 0;

    if(binary_operations)
        return binary_operations;

    binary_operations = create_array(1, destroy_operation);

    push_in_array(binary_operations, create_operation("+", BINARY_PLUS));

    return binary_operations;
}


static int* get_binary_priorities()
{
    static int *binary_priorities = 0;

    if(binary_priorities)
        return binary_priorities;

    binary_priorities = new_array(int, 256);

    binary_priorities[OPEN_BRACE]  = 0;
    binary_priorities[BINARY_PLUS] = 3;

    return binary_priorities;
}


Array* parse_expression(Parser *parser)
{
    return parse_expression_in_infix_notation(parser->input_stream, get_unary_operations(), get_binary_operations(), get_binary_priorities(), parser, parse_expression_operand);
}
