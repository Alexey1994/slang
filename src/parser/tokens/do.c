#include "do.h"


Boolean parse_do(Parser *parser)
{
    Do *do_block = new(Do);

    print_block_indention(parser);
    printf("DO\n");

    push_block(parser, do_block, DO);

    return 1;

error:
    printf("error in do\n");

    return 0;
}
