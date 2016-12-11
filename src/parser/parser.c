#include "parser.h"
#include "operand.h"

#include "block.h"

#include "tokens/function_definition.h"
#include "tokens/comment.h"
#include "tokens/assignment.h"

#include "variable.h"


Boolean parse_Slang_expression(Parser *parser)
{
    Array       *operand;
    DynamicData *operand_data;

    if(read_if_on_stream_head(parser->input_stream, "#"))
        return parse_Slang_comment(parser);

    skip_spaces(parser);

    if(read_if_on_stream_head(parser->input_stream, ":"))
        return parse_Slang_function_definition(parser);

    operand = parse_operand(parser);

    if(!operand)
        goto error;
/*
    operand_data = operand->data[operand->length-1];

    if(operand_data->type == FUNCTION_CALL)
        return parse_Slang_function_call(parser, operand);
*/
    if(read_if_on_stream_head(parser->input_stream, "="))
        return parse_Slang_assignment(parser, operand), printf("\n");

    return 1;

error:
    printf("error parsing\n");
    return 0;
}


Boolean is_Slang_letter(Character c)
{
    if(is_letter(c) || is_number(c))
        return 1;

    return 0;
}


static void destroy_Slang_parser(SlangParser *slang_parser)
{

}


Boolean parse_class(Parser *parser, char *name_class)
{
    SlangParser *slang_parser = parser->language_parser;
    Byte        *source       = slang_parser->open_source(name_class);

    if(!source)
    {
        print_error("class ");
        print_error(name_class);
        print_error(" not found\n");
        goto error;
    }

    Stream      *input_stream = create_stream(source, parser->input_stream->get_byte, parser->input_stream->end_of_data);
    Parser      *class_parser = create_parser(input_stream, get_Slang_keywords(),  parse_Slang_expression, is_Slang_letter, slang_parser, destroy_Slang_parser);

    push_block(class_parser, 0, FUNCTION);

    parse(class_parser);

    return 1;

error:
    return 0;
}


void destroy_body_element(Byte *body)
{
    printf("body destroyer not init\n");
}


Boolean parse_Slang(Byte* (*open_source)(Character *name),
                    void (*close_source)(Byte *source),
                    Byte* (*get_byte)(Byte *source),
                    Boolean (*end_of_data)(Byte *source))
{
    Stream      *input_stream = create_stream(0, get_byte, end_of_data);
    SlangParser *slang_parser = new(SlangParser);
    Parser      *parser       = create_parser(input_stream, get_Slang_keywords(),  parse_Slang_expression, is_Slang_letter, slang_parser, destroy_Slang_parser);

    slang_parser->open_source  = open_source;
    slang_parser->close_source = close_source;
    slang_parser->blocks       = create_array(2, destroy_block);
    slang_parser->body         = create_array(2, destroy_body_element);

    parser->language_parser = slang_parser;

    parse_class(parser, "Main");
    //parse_class(parser, "Pain");

    return 1;

error:
    return 0;
}
