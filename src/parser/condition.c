#include "condition.h"


#include "expression.h"
#include "../lib/expression parser.h"
#include "operand.h"


static Operation* create_operation(Character *name, Byte number)
{
    Operation *operation = new(Operation);

    operation->name   = name;
    operation->number = number;

    return operation;
}


static void destroy_operation(Operation *operation)
{
    free(operation);
}


static Character* get_operations_translator()
{
    static Character *codes = 0;

    if(codes)
        return codes;

    codes = malloc(256);

    codes[CONDITION_AND] = '&';
    codes[CONDITION_OR] = '|';

    return codes;
}


void print_condition(Array *condition)
{
    print_expression_in_postfix_notation(condition, get_operations_translator(), print_expression);
}


static Array* get_unary_operations()
{
    static Array *unary_operations = 0;

    if(unary_operations)
        return unary_operations;

    unary_operations = create_array(1, destroy_operation);

    push_in_array(unary_operations, create_operation("not", CONDITION_NOT));

    return unary_operations;
}


static Array* get_binary_operations()
{
    static Array *binary_operations = 0;

    if(binary_operations)
        return binary_operations;

    binary_operations = create_array(2, destroy_operation);

    push_in_array(binary_operations, create_operation("and", CONDITION_AND));
    push_in_array(binary_operations, create_operation("or", CONDITION_OR));

    return binary_operations;
}


static int* get_binary_priorities()
{
    static int *binary_priorities = 0;

    if(binary_priorities)
        return binary_priorities;

    binary_priorities = new_array(int, 256);

    binary_priorities[OPEN_BRACE]  = 0;
    binary_priorities[CONDITION_OR] = 3;
    binary_priorities[CONDITION_AND] = 4;

    return binary_priorities;
}


static Array* get_condition_operand(Parser *parser)
{
    return parse_expression(parser);
}


Array* parse_condition(Parser *parser)
{
    return parse_expression_in_infix_notation(parser->input_stream, get_unary_operations(), get_binary_operations(), get_binary_priorities(), parser, get_condition_operand);
}
