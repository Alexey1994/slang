#include "goto.h"
#include "../block.h"


Boolean parse_goto(Parser *parser)
{
    String *label = read_new_word(parser);

    print_block_indention(parser);
    printf("GOTO ");

    if(!label)
        goto error;

    print_string(label);
    printf("\n");

    return 1;

error:
    printf("error in goto\n");

    return 0;
}
