#include "variable.h"
#include "../lib/string.h"


Variable* create_variable(String *name, Parser *parser)
{
    String    *new_variable_name = create_string(2);
    Variable  *variable          = new(Variable);

    copy_string_to_string(new_variable_name, name);
    variable->name = convert_string_to_char_array(new_variable_name);

    //add_data_in_prefix_tree(parser->current_scope, variable->name, variable);

    return variable;
}


static Variable* find_local_variable(String *name)
{

}


Function* create_function(String *name, Parser *parser)
{
    Variable *function_variable;
    Function *function;

    if(find_local_variable(name))
    {
        print_error("name '");
        print_string(name);
        printf("' is busy\n");
    }

    function_variable = create_variable(name, parser);
    function          = new(Function);



    return function;
}
