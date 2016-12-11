#include "keywords.h"

#include "tokens/if.h"
#include "tokens/end.h"
#include "tokens/else.h"
#include "tokens/while.h"
#include "tokens/do.h"
#include "tokens/for.h"
#include "tokens/loop.h"
#include "tokens/goto.h"
#include "tokens/label.h"
#include "tokens/break.h"
#include "tokens/continue.h"


PrefixTree* get_Slang_keywords()
{
    static PrefixTree *keywords = 0;

    if(keywords)
        return keywords;

    keywords = create_prefix_tree();

    add_data_in_prefix_tree(keywords, "if",       parse_if);
    add_data_in_prefix_tree(keywords, "end",      parse_end);
    add_data_in_prefix_tree(keywords, "else",     parse_else);
    add_data_in_prefix_tree(keywords, "while",    parse_while);
    add_data_in_prefix_tree(keywords, "do",       parse_do);
    add_data_in_prefix_tree(keywords, "for",      parse_for);
    add_data_in_prefix_tree(keywords, "loop",     parse_loop);
    add_data_in_prefix_tree(keywords, "goto",     parse_goto);
    add_data_in_prefix_tree(keywords, "label",    parse_label);
    add_data_in_prefix_tree(keywords, "break",    parse_break);
    add_data_in_prefix_tree(keywords, "continue", parse_continue);

/*
    add_data_in_prefix_tree(keywords, "if",       1);
    add_data_in_prefix_tree(keywords, "else",     1);
    add_data_in_prefix_tree(keywords, "while",    1);
    add_data_in_prefix_tree(keywords, "function", 1);
    add_data_in_prefix_tree(keywords, "end",      1);*/

    return keywords;
}
