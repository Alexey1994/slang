#include "while.h"
#include "../block.h"
#include "do.h"


Boolean parse_while(Parser *parser)
{
    Array *condition     = parse_condition(parser);
    Block *current_block = get_current_block(parser);
    While *while_block;

    if(!condition)
        goto error;

    if(current_block->type == DO)
        pop_block(parser);

    print_block_indention(parser);
    printf("WHILE ");

    print_condition(condition);
    printf("\n");

    push_block(parser, while_block, WHILE);

    while_block = new(While);

    return 1;

error:
    printf("error in while\n");

    return 0;
}
