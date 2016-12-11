#include "end.h"


Boolean parse_end(Parser *parser)
{
    if(!pop_block(parser))
        goto error;

    print_block_indention(parser);
    printf("END\n\n");

    return 1;

error:
    printf("error in end\n");
    return 0;
}
