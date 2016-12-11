#include "assignment.h"
#include "../expression.h"


Boolean parse_Slang_assignment(Parser *parser, Array *operand)
{
    Array *expression;

    print_operand(operand);
    printf("=");

    get_stream_byte(parser->input_stream);

    expression = parse_expression(parser);

    if(!expression)
        goto error;

    print_expression(expression);

    return 1;

error:
    //printf("Err");
    return 0;
}
