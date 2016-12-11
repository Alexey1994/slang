#ifndef RANDOM_ACCESS_STRUCTURE_H_INCLUDED
#define RANDOM_ACCESS_STRUCTURE_H_INCLUDED


#include "../extends.h"


typedef struct
{
    Byte *structure;

    Byte* (*get_element)(struct RandomAccessStructure *structure, int pos);
    int   (*get_length)(struct RandomAccessStructure *structure);
}
RandomAccessStructure;


RandomAccessStructure* create_random_access_structure(Byte *structure,
                                                      Byte* (*get_element)(RandomAccessStructure *structure, int pos),
                                                      int (*get_length)(RandomAccessStructure *structure));

void destroy_random_randoim_access_structure(RandomAccessStructure *structure);

#endif // RANDOM_ACCESS_STRUCTURE_H_INCLUDED
