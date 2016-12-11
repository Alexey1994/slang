#include <stdio.h>
#include "parser/keywords.h"
#include "parser/parser.h"


Byte* open_file(Character *name)
{
    return fopen(name, "rb");
}


int main()
{
    parse_Slang(open_file, fclose, fgetc, feof);

    return 0;
}
