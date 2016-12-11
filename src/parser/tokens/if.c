#include "if.h"
#include "../block.h"
#include "else.h"
#include "../condition.h"


Boolean parse_if(Parser *parser)
{
    Array       *condition     = parse_condition(parser);
    Block       *current_block = get_current_block(parser);
    If          *if_block      = new(If);

    print_block_indention(parser);
    printf("IF ");

    if(!condition)
        goto error;

    print_condition(condition);
    printf("\n");

    if(current_block->type == ELSE)// && !slang_parser->body->length)
        pop_block(parser);

    push_block(parser, if_block, IF);

    return 1;

error:
    printf("error in if\n");
    return 0;
}
