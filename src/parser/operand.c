#include "operand.h"


static void print_operand_node(DynamicData *operand_node)
{
    switch(operand_node->type)
    {
        case OPERAND_VARIABLE:
            print_string(operand_node->data);
            break;

        case OPERAND_STRUCTURE:
            printf("%c", operand_node->data);
            break;
    }
}


void print_operand(Array *operand)
{
    printf(" ");
    crawl_array(operand, print_operand_node);
    printf(" ");
}


static void destroy_operand_node(DynamicData *operand_node)
{

}


static void add_operand_variable(Array *operand, String *variable_name)
{
    String *copy_variable_name = create_string(2);

    copy_string_to_string(copy_variable_name, variable_name);
    push_in_array(operand, create_dynamic_data(copy_variable_name, OPERAND_VARIABLE));
}


Array* parse_operand(Parser *parser)
{
    Array  *operand       = create_array(4, destroy_operand_node);
    Stream *input_stream  = parser->input_stream;

    if(!parser->word->length)
    {
        printf("not operand\n");
        goto error;
    }

    add_operand_variable(operand, parser->word);

    loop
    {
        skip_spaces(parser);

        switch(input_stream->head)
        {
            case '.':
                push_in_array(operand, create_dynamic_data(MAP_KEY, OPERAND_STRUCTURE));
                get_stream_byte(input_stream);
                break;

            case '[':
                break;

            case '(':
                break;

            default:
                return operand;
        }

        if(end_stream(input_stream))
            break;

        if(!read_word(parser, parser->word))
            break;

        add_operand_variable(operand, parser->word);
    }

    return operand;

error:
    printf("error in operand\n");

    destroy_array(operand);
    return 0;
}


Array* parse_expression_operand(Parser *parser)
{
    Array *operand;

    read_word(parser, parser->word);

    /*
    if(!read_word(parser, parser->word))
        goto error;
    */

    operand = parse_operand(parser);

    if(!operand)
        goto error;

    return operand;

error:

    printf("error in parse expression operand\n");
    return 0;
}
