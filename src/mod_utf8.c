#include <assert.h>
#include <stdlib.h>
#include "mod_utf8.h"


/**
 * implementation reference: https://www.cprogramming.com/tutorial/unicode.html
 */

int read_mod_utf8_char(u4 bytes_count, u4 start_offset, u1 *bytes_content)
{

}

int read_mod_utf8_string(u4 bytes_count, u4 start_offset, u1 *bytes_content, struct utf8_string *string)
{
    assert(bytes_count > 0);
    assert(bytes_content != NULL);

    u1 *start = bytes_content;
    u4 index = 0;
    u4 bytes_count_read = 0;
    u4 chars_count_read = 0;
    do
    {
        u1 byte = bytes_content[index];
        u1 bytes_count_for_char = compute_utf8_string_bytes_count(byte);
        bytes_count_read += bytes_count_for_char;
        assert(bytes_count_read <= bytes_count);
    } while (index < bytes_count);
}

