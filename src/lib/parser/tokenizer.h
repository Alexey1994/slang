#ifndef TOKENIZER_H_INCLUDED
#define TOKENIZER_H_INCLUDED


#include "../lib/String.h"
#include "parser.h"


String* read_new_word(Parser *parser);
String* read_word(Parser *parser, String *word);
void skip_spaces(Parser *parser);


#endif // TOKENIZER_H_INCLUDED
