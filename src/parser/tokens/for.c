#include "for.h"
#include "../block.h"


static Boolean parse_for_begin(Parser *parser)
{
    Array *operand;

    read_word(parser, parser->word);

    operand = parse_operand(parser);

    if(!operand)
        goto error;

    if(!read_if_on_stream_head(parser->input_stream, "="))
    {
        printf("expected =\n");
        goto error;
    }

    return parse_Slang_assignment(parser, operand);

error:
    printf("error in for assignment\n");

    return 0;
}


Boolean parse_for(Parser *parser)
{
    For   *for_block      = new(For);
    Array *condition;
    Array *iterator_expression;

    print_block_indention(parser);
    printf("FOR ");

    if(!parse_for_begin(parser))
        goto error;

    if(parser->input_stream->head != ',')
    {
        printf("expected ,\n");
        goto error;
    }

    get_stream_byte(parser->input_stream);
    printf(",");

    condition = parse_condition(parser);

    if(!condition)
        goto error;

    print_condition(condition);

    if(parser->input_stream->head != ',')
    {
        printf("expected ,\n");
        goto error;
    }

    get_stream_byte(parser->input_stream);
    printf(",");

    iterator_expression = parse_expression(parser);

    if(!iterator_expression)
        goto error;

    print_expression(iterator_expression);
    printf("\n");

    push_block(parser, for_block, FOR);

    return 1;

error:
    printf("error in for\n");

    return 0;
}
