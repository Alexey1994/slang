#include "function_definition.h"
#include "../block.h"
#include "../variable.h"


static Variable* parse_argument(Parser *parser)
{
    String   *type     = read_new_word(parser);
    String   *variable = 0;//read_new_word(parser);
    Variable *argument;

    if(!variable)
    {
        variable = type;
        type = 0;
    }

    if(!variable)
        goto error;

    argument = create_variable(variable, parser);

    print_string(variable);
    printf(" ");

    return argument;

error:
    printf("error parsing argument\n");

    return 0;
}


Boolean parse_Slang_function_definition(Parser *parser)
{
    Stream   *input_stream = parser->input_stream;
    Function *function;
    Variable *argument;

    print_block_indention(parser);
    printf("FUNCTION ");
    print_string(parser->word);
    printf(": ");

    skip_spaces(parser);

    argument = parse_argument(parser);

    if(!argument)
        goto error;

    skip_spaces(parser);

    while(input_stream->head == ',')
    {
        get_stream_byte(input_stream);
        argument = parse_argument(parser);

        if(!argument)
            goto error;

        skip_spaces(parser);
    }

    if(read_if_on_stream_head(input_stream, "->"))
    {
        printf("-> ");

        argument = parse_argument(parser);

        if(!argument)
            goto error;
    }

    printf("\n");

    push_block(parser, function, FUNCTION);

    return 1;

error:
    printf("error parsing function definition\n");

    return 0;
}
