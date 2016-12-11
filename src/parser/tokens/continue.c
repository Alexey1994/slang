#include "continue.h"
#include "../block.h"


Boolean parse_continue(Parser *parser)
{
    Block *block = get_outer_cycle(parser);

    if(!block)
    {
        printf("continue not in cycle\n");
        goto error;
    }

    print_block_indention(parser);
    printf("CONTINUE\n");

    return 1;

error:
    printf("error in continue\n");

    return 0;
}
