#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED


#include "random access structure.h"


typedef struct
{
    char **data;
    int    length;
    int    buffer_length;
    int    reserve;
    void (*destroy_node)(char *node);
}
Array;

Array* create_array(int reserve, void (*destroy_node)(char *node));
void destroy_array(Array *array);

void push_in_array(Array *array, char *data);
char* pop_from_array(Array *array);
char* get_array_top(Array *array);
void crawl_array(Array *array, void(*crawl_func)(char *array_node));

RandomAccessStructure* create_array_structure(Array *array);
void destroy_array_structure(RandomAccessStructure *structure);

#endif // ARRAY_H_INCLUDED
