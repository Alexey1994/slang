#ifndef SLANG_PARSER_H_INCLUDED
#define SLANG_PARSER_H_INCLUDED


#include "../lib/parser/parser.h"


typedef struct
{
    Byte* (*open_source)(Character *name);
    void (*close_source)(Byte *source);

    Array        *blocks;
    Array        *body;
    struct Block *current_block;
}
SlangParser;


Boolean parse_Slang(Byte* (*open_source)(Character *name),
                    void (*close_source)(Byte *source),
                    Byte* (*get_byte)(Byte *source),
                    Boolean (*end_of_data)(Byte *source));

void destroy_body_element(Byte *body);


#endif // SLANG_PARSER_H_INCLUDED
