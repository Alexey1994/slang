#include "block.h"
#include "tokens/while.h"
#include "tokens/do.h"
#include "tokens/loop.h"
#include "tokens/for.h"


void print_block_indention(Parser *parser)
{
    SlangParser *slang_parser = parser->language_parser;
    int          i;

    for(i=0; i<slang_parser->blocks->length; ++i)
        printf("    ");
}


Block* create_block(Array *body, Byte *block_element, Byte type)
{
    Block *block = new(Block);

    block->body          = body;
    block->type          = type;
    block->block_element = block_element;

    return block;
}


void destroy_block(Block *block)
{
    free(block);
}


void push_block(Parser *parser, Byte *block_element, Byte block_type)
{
    SlangParser *slang_parser = parser->language_parser;
    Block       *block        = create_block(slang_parser->body, block_element, block_type);

    push_in_array(slang_parser->blocks, block);
    slang_parser->body = create_array(2, destroy_body_element);
}


Block* get_current_block(Parser *parser)
{
    SlangParser *slang_parser = parser->language_parser;

    return slang_parser->blocks->data[ slang_parser->blocks->length-1 ];
}


Boolean pop_block(Parser *parser)
{
    SlangParser *slang_parser = parser->language_parser;
    Block       *block;

    if(slang_parser->blocks->length == 1)
        goto error;

    block = pop_from_array(slang_parser->blocks);
    slang_parser->body = block->body;

    return 1;

error:
    printf("error in pop block\n");
    return 0;
}


Block* get_outer_cycle(Parser *parser)
{
    SlangParser           *slang_parser     = parser->language_parser;
    Array                 *blocks           = slang_parser->blocks;
    RandomAccessStructure *blocks_structure = create_array_structure(blocks);
    int                    length           = blocks_structure->get_length(blocks_structure);
    Block                 *block;
    int                    i;

    for(i=0; i<length; ++i)
    {
        block = blocks_structure->get_element(blocks_structure, i);

        if(block->type == WHILE)
            return block;

        if(block->type == DO)
            return block;

        if(block->type == LOOP)
            return block;

        if(block->type == FOR)
            return block;
    }

    return 0;
}
