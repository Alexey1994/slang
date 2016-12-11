#include "else.h"
#include "if.h"
#include "../block.h"


Boolean parse_else(Parser *parser)
{
    SlangParser *slang_parser = parser->language_parser;
    Block       *block        = slang_parser->blocks->data[ slang_parser->blocks->length-1 ];
    If          *if_block;

    if(block->type != IF)
    {
        printf("else not in if\n");
        goto error;
    }

    skip_spaces(parser);

    //if_block = block->block_element;

    //if_block->if_body =

    pop_block(parser);

    print_block_indention(parser);
    printf("ELSE\n");

    push_block(parser, if_block, ELSE);

    return 1;

error:
    printf("error in else\n");
    return 0;
}
