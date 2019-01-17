#pragma once

typedef unsigned long u8;
typedef unsigned int u4;
typedef unsigned short u2;
typedef unsigned char u1;

static const u4 MAGIC_NUMBER = 0xCAFEBABE;

static const char CLASS_FILE_ATTRIBUTE_NAME_SOURCE_FILE[] = "SourceFile";
static const char CLASS_FILE_ATTRIBUTE_NAME_INNER_CLASSES[] = "InnerClasses";
static const char CLASS_FILE_ATTRIBUTE_NAME_ENCLOSING_METHOD[] = "EnclosingMethod";
static const char CLASS_FILE_ATTRIBUTE_NAME_SOURCE_DEBUG_EXTENSION[] = "SourceDebugExtension";
static const char CLASS_FILE_ATTRIBUTE_NAME_BOOTSTRAP_METHODS[] = "BootstrapMethods";
static const char CLASS_FILE_ATTRIBUTE_NAME_CONSTANT_VALUE[] = "ConstantValue";
static const char CLASS_FILE_ATTRIBUTE_NAME_CODE[] = "Code";
static const char CLASS_FILE_ATTRIBUTE_NAME_EXCEPTIONS[] = "Exceptions";
static const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS[] = "RuntimeVisibleParameterAnnotations";
static const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS[] = "RuntimeInVisibleParameterAnnotations";
static const char CLASS_FILE_ATTRIBUTE_NAME_ANNOTATION_DEFAULT[] = "AnnotationDefault";
static const char CLASS_FILE_ATTRIBUTE_NAME_METHOD_PARAMETERS[] = "MethodParameters";
static const char CLASS_FILE_ATTRIBUTE_NAME_SYNTHETIC[] = "Synthetic";
static const char CLASS_FILE_ATTRIBUTE_NAME_DEPRECATED[] = "Deprecated";
static const char CLASS_FILE_ATTRIBUTE_NAME_SIGNATURE[] = "Signature";
static const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_VISIBLE_ANNOTATIONS[] = "RuntimeVisibleAnnotations";
static const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_INVISIBLE_ANNOTATIONS[] = "RuntimeInVisibleAnnotations";
static const char CLASS_FILE_ATTRIBUTE_NAME_LINE_NUMBER_TABLE[] = "LineNumberTable";
static const char CLASS_FILE_ATTRIBUTE_NAME_LOCAL_VARIABLE_TABLE[] = "LocalVariableTable";
static const char CLASS_FILE_ATTRIBUTE_NAME_LOCAL_VARIABLE_TYPE_TABLE[] = "LocalVariableTypeTable";
static const char CLASS_FILE_ATTRIBUTE_NAME_STACK_MAP_TABLE[] = "StackMapTable";
static const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_VISIBLE_TYPE_ANNOTATIONS[] = "RuntimeVisibleTypeAnnotations";
static const char CLASS_FILE_ATTRIBUTE_NAME_RUNTIME_INVISIBLE_TYPE_ANNOTATIONS[] = "RuntimeInvisibleTypeAnnotations";

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

struct FieldInfo
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    struct constant_pool_attribute **attributes;
};

struct MethodInfo
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    struct constant_pool_attribute **attributes;
};

struct ClassFile
{
    u4 magic;
    u2 minor_vertion;
    u2 major_vertion;
    u2 constant_pool_count;
    struct constant_pool_attribute **constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces;
    u2 fields_count;
    struct constant_pool_field_ref **fields;
    u2 methods_count;
    struct constant_pool_method_ref **methods;
    u2 attributes_count;
    struct constant_pool_attribute **attributes;
};
