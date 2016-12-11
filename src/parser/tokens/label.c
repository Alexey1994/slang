#include "label.h"
#include "../block.h"


Boolean parse_label(Parser *parser)
{
    String *label = read_new_word(parser);

    print_block_indention(parser);
    printf("LABEL ");

    if(!label)
        goto error;

    print_string(label);
    printf("\n");

    return 1;

error:
    printf("error in label\n");

    return 0;
}
