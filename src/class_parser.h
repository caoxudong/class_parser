#pragma once

#include "jvm/basic_types.h"
#include "class_file_types.h"

// parse class file content
struct class_file * parse(u1* content);