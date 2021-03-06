#pragma once

#include "jvm/basic_types.h"

const u4 MAGIC_NUMBER = 0xCAFEBABE;

const char CLASS_FILE_ATTRIBUTE_NAME_SOURCE_FILE[] = "SourceFile";
const char CLASS_FILE_ATTRIBUTE_NAME_INNER_CLASSES[] = "InnerClasses";
const char CLASS_FILE_ATTRIBUTE_NAME_ENCLOSING_METHOD[] = "EnclosingMethod";
const char CLASS_FILE_ATTRIBUTE_NAME_SOURCE_DEBUG_EXTENSION[] = "SourceDebugExtension";
const char CLASS_FILE_ATTRIBUTE_NAME_BOOTSTRAP_METHODS[] = "BootstrapMethods";
const char CLASS_FILE_ATTRIBUTE_NAME_CONSTANT_VALUE[] = "ConstantValue";
const char CLASS_FILE_ATTRIBUTE_NAME_CODE[] = "Code";
const char CLASS_FILE_ATTRIBUTE_NAME_EXCEPTIONS[] = "Exceptions";
const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS[] = "RuntimeVisibleParameterAnnotations";
const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS[] = "RuntimeInVisibleParameterAnnotations";
const char CLASS_FILE_ATTRIBUTE_NAME_ANNOTATION_DEFAULT[] = "AnnotationDefault";
const char CLASS_FILE_ATTRIBUTE_NAME_METHOD_PARAMETERS[] = "MethodParameters";
const char CLASS_FILE_ATTRIBUTE_NAME_SYNTHETIC[] = "Synthetic";
const char CLASS_FILE_ATTRIBUTE_NAME_DEPRECATED[] = "Deprecated";
const char CLASS_FILE_ATTRIBUTE_NAME_SIGNATURE[] = "Signature";
const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_VISIBLE_ANNOTATIONS[] = "RuntimeVisibleAnnotations";
const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_INVISIBLE_ANNOTATIONS[] = "RuntimeInVisibleAnnotations";
const char CLASS_FILE_ATTRIBUTE_NAME_LINE_NUMBER_TABLE[] = "LineNumberTable";
const char CLASS_FILE_ATTRIBUTE_NAME_LOCAL_VARIABLE_TABLE[] = "LocalVariableTable";
const char CLASS_FILE_ATTRIBUTE_NAME_LOCAL_VARIABLE_TYPE_TABLE[] = "LocalVariableTypeTable";
const char CLASS_FILE_ATTRIBUTE_NAME_STACK_MAP_TABLE[] = "StackMapTable";
const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_VISIBLE_TYPE_ANNOTATIONS[] = "RuntimeVisibleTypeAnnotations";
const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_INVISIBLE_TYPE_ANNOTATIONS[] = "RuntimeInvisibleTypeAnnotations";

// class access flags
enum class_access_flags
{
    CLASS_ACCESS_FLAGS_ACC_PUBLIC = 0x0001,
    CLASS_ACCESS_FLAGS_ACC_FINAL = 0x0010,
    CLASS_ACCESS_FLAGS_ACC_SUPER = 0x0020,
    CLASS_ACCESS_FLAGS_ACC_INTERFACE = 0x0200,
    CLASS_ACCESS_FLAGS_ACC_ABSTRACT = 0x0400,
    CLASS_ACCESS_FLAGS_ACC_SYNTHETIC = 0x1000,
    CLASS_ACCESS_FLAGS_ACC_ANNOTATION = 0x2000,
    CLASS_ACCESS_FLAGS_ACC_ENUM = 0x4000
};

// field access flags
enum field_access_flags
{
    FIELD_ACCESS_FLAGS_ACC_PUBLIC = 0x0001,
    FIELD_ACCESS_FLAGS_ACC_PRIVATE = 0x0002,
    FIELD_ACCESS_FLAGS_ACC_PROTECTED = 0x0004,
    FIELD_ACCESS_FLAGS_ACC_STATIC = 0x0008,
    FIELD_ACCESS_FLAGS_ACC_FINAL = 0x0010,
    FIELD_ACCESS_FLAGS_ACC_VOLATILE = 0x0040,
    FIELD_ACCESS_FLAGS_ACC_TRANSIENT = 0x0080,
    FIELD_ACCESS_FLAGS_ACC_SYNTHETIC = 0x1000,
    FIELD_ACCESS_FLAGS_ACC_ENUM = 0x4000
};

// method access flags
enum method_access_flags
{
    METHOD_ACCESS_FLAGS_ACC_PUBLIC = 0x0001,
    METHOD_ACCESS_FLAGS_ACC_PRIVATE = 0x0002,
    METHOD_ACCESS_FLAGS_ACC_PROTECTED = 0x0004,
    METHOD_ACCESS_FLAGS_ACC_STATIC = 0x0008,
    METHOD_ACCESS_FLAGS_ACC_FINAL = 0x0010,
    METHOD_ACCESS_FLAGS_ACC_SYNCHRONIZED = 0x0020,
    METHOD_ACCESS_FLAGS_ACC_BRIDGE = 0x0040,
    METHOD_ACCESS_FLAGS_ACC_VARARGS = 0x0080,
    METHOD_ACCESS_FLAGS_ACC_NATIVE = 0x0100,
    METHOD_ACCESS_FLAGS_ACC_ABSTRACT = 0x0400,
    METHOD_ACCESS_FLAGS_ACC_STRICT = 0x0800,
    METHOD_ACCESS_FLAGS_ACC_SYNTHETIC = 0x1000
};

// constant pool tags
enum constant_pool_tags
{
    CONSTANT_POOL_TAGS_UTF8 = 1,
    CONSTANT_POOL_TAGS_INTEGER = 3,
    CONSTANT_POOL_TAGS_FLOAT = 4,
    CONSTANT_POOL_TAGS_LONG = 5,
    CONSTANT_POOL_TAGS_DOUBLE = 6,
    CONSTANT_POOL_TAGS_CLASS = 7,
    CONSTANT_POOL_TAGS_STRING = 8,
    CONSTANT_POOL_TAGS_FIELD_REF = 9,
    CONSTANT_POOL_TAGS_METHOD_REF = 10,
    CONSTANT_POOL_TAGS_INTERFACE_METHOD_REF = 11,
    CONSTANT_POOL_TAGS_NAME_AND_TYPE = 12,
    CONSTANT_POOL_TAGS_METHOD_HANDLE = 15,
    CONSTANT_POOL_TAGS_METHOD_TYPE = 16,
    CONSTANT_POOL_TAGS_INVOKE_DYNAMIC = 18
};

struct constant_pool_base
{
    u1 tag;
};

struct constant_pool_class
{
    struct constant_pool_base base;
    u2 name_index;
};

struct constant_pool_field_ref
{
    struct constant_pool_base base;
    u2 class_index;
    u2 name_and_type_index;
};

struct constant_pool_method_ref
{
    struct constant_pool_base base;
    u2 class_index;
    u2 name_and_type_index;
};

struct constant_pool_interface_method_ref
{
    struct constant_pool_base base;
    u2 class_index;
    u2 name_and_type_index;
};

struct constant_pool_string
{
    struct constant_pool_base base;
    u2 string_index;
};

struct constant_pool_integer
{
    struct constant_pool_base base;
    u4 bytes;
};

struct constant_pool_float
{
    struct constant_pool_base base;
    u4 bytes;
};

struct constant_pool_long
{
    struct constant_pool_base base;
    u4 high_bytes;
    u4 low_bytes;
};

struct constant_pool_double
{
    struct constant_pool_base base;
    u4 high_bytes;
    u4 low_bytes;
};

struct constant_pool_name_and_type
{
    struct constant_pool_base base;
    u2 name_index;
    u2 descriptor_index;
};

struct constant_pool_utf8
{
    struct constant_pool_base base;
    u2 length;
    u1 *bytes;
};

struct constant_pool_method_handle
{
    struct constant_pool_base base;
    u1 reference_kind;
    u2 reference_index;
};

struct constant_pool_method_type
{
    struct constant_pool_base base;
    u2 descriptor_index;
};

struct constant_pool_intoke_dynamic
{
    struct constant_pool_base base;

    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};

struct constant_pool_attribute
{
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *info;
};

struct field_info
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    struct constant_pool_attribute **attributes;
};

struct method_info
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    struct constant_pool_attribute **attributes;
};

struct class_file
{
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    struct constant_pool_attribute **constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces;
    u2 fields_count;
    struct field_info **fields;
    u2 methods_count;
    struct method_info **methods;
    u2 attributes_count;
    struct attribute_info **attributes;
};
