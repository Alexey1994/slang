#include "loop.h"
#include "../block.h"


Boolean parse_loop(Parser *parser)
{
    Loop *loop_block = new(Loop);

    print_block_indention(parser);
    printf("LOOP\n");

    push_block(parser, loop_block, LOOP);

    return 1;
}
