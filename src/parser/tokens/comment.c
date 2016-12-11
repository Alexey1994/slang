#include "comment.h"


Boolean parse_Slang_comment(Parser *parser)
{
    Stream *input_stream = parser->input_stream;

    while(!end_stream(input_stream) && input_stream->head != '\n')
        get_stream_byte(input_stream);

    skip_spaces(parser);

    return 1;
}
