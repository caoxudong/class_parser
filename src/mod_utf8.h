/**
 * jvm use modified UTF-8, https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.4.7
 */

#pragma once

#include "jvm/basic_types.h"

struct utf8_string
{
    u4 bytes_count;
    u4 chars_count;
    u1 *content;
};

int read_mod_utf8_char(u4 bytes_count, u4 start_pos, u1 *bytes_content);
int read_mod_utf8_string(u4 bytes_count, u4 start_offset, u1 *bytes_content, struct utf8_string *string);