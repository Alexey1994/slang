#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED


#include "parser.h"


typedef struct
{
    Byte  type;
    Byte *body;
    Byte *block_element;
}
Block;


Block* create_block(Array *body, Byte *block_element, Byte type);
void destroy_block(Block *block);


void push_block(Parser *parser, Byte *block_element, Byte block_type);
Boolean pop_block(Parser *parser);
Block* get_current_block(Parser *parser);
Block* get_outer_cycle(Parser *parser);
void print_block_indention(Parser *parser);


#endif // BLOCK_H_INCLUDED
