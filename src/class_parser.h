#pragma once

#include "class_file_types.h"

using namespace jvm::class_file_types;

namespace jvm
{
  namespace class_loader
  {
    class ClassPaser
    {
    public:
      ClassPaser();
      ~ClassPaser();

      // resolve class file, returning a pointer to struct class_file
      // caller needs free the memory
      ClassFile *parse(char* content);
    };
  }
}

// read u1/u2/u4 numbers
static u4 read_u4(char* content, u4 *offset);
static u2 read_u2(char* content, u4 *offset);
static u1 read_u1(char* content, u4 *offset);

// read u1/u2 array, caller must free the memory
// note: thr returned value is a pointer to an array created dynamically.
static u1 *read_u1_array(
  char* content, u4 *offset, u4 length);
static u2 *read_u2_array(
  char* content, u4 *offset, u4 length);

// resolve attribute info of method/interface/field...
// caller needs free the memory
static AttributeInfo *read_attribute_info(
  char* content, u4 *offset);

// resolve attributes array
// caller needs free the memory
static AttributeInfo **read_attribute_info_array(
  char* content, u4 *offset, u2 attributes_count);

// resolve constant pool info array
// caller needs free the memory
static ConstantPoolInfoBase **read_constant_pool_info_array(
  char* content, u4 *offset, u2 constant_pool_count);

// resolve fields array
// caller needs free the memory
static FieldInfo **read_field_info_array(
  char* content, u4 *offset, u2 fields_count);

// resolve methods array
// caller needs free the memory
static MethodInfo **read_method_info_array(
  char* content, u4 *offset, u2 methods_count);