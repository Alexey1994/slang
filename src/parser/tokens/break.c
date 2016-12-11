#include "break.h"
#include "../block.h"


Boolean parse_break(Parser *parser)
{
    Block *cycle = get_outer_cycle(parser);

    if(!cycle)
    {
        printf("break not in cycle\n");
        goto error;
    }

    print_block_indention(parser);
    printf("BREAK\n");

    return 1;

error:
    printf("error in break\n");

    return 0;
}
