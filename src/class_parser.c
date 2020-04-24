#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "class_file_types.h"

static const char *ATTR_NAME_CONSTANT_VALUE = "ConstantValue";
static const char *ATTR_NAME_CODE = "Code";
static const char *ATTR_NAME_EXCEPTIONS = "Exceptions";
static const char *ATTR_NAME_SOURCE_FILE = "SourceFile";
static const char *ATTR_NAME_LINE_NUMBER_TABLE = "LineNumberTable";
static const char *ATTR_NAME_LOCAL_VARIABLE_TABLE = "LocalVariableTable";
static const char *ATTR_NAME_INNER_CLASSES = "InnerClasses";
static const char *ATTR_NAME_SYNTHETIC = "Synthetic";
static const char *ATTR_NAME_DEPRECATED = "Deprecated";
static const char *ATTR_NAME_ENCLOSING_METHOD = "EnclosingMethod";
static const char *ATTR_NAME_SIGNATURE = "Signature";
static const char *ATTR_NAME_SOURCE_DEBUG_EXTENSION = "SourceDebugExtension";
static const char *ATTR_NAME_LOCAL_VARIABLE_TYPE_TABLE = "LocalVariableTypeTable";
static const char *ATTR_NAME_RUNTIME_VISIBLE_ANNOTATIONS = "RuntimeVisibleAnnotations";
static const char *ATTR_NAME_RUNTIME_INVISIBLE_ANNOTATIONS = "RuntimeInvisibleAnnotations";
static const char *ATTR_NAME_RUNTIME_VISIABLE_PARAMETER_ANNOTATIONS = "RuntimeVisibleParameterAnnotations";
static const char *ATTR_NAME_RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS = "RuntimeInvisibleParameterAnnotations";
static const char *ATTR_NAME_ANNOTATION_DEFAULT = "AnnotationDefault";
static const char *ATTR_NAME_STACK_MAP_TABLE = "StackMapTable";
static const char *ATTR_NAME_BOOTSTRAP_METHODS = "BootstrapMethods";
static const char *ATTR_NAME_RUNTIME_VISIBLE_TYPE_ANNOTATIONS = "RuntimeVisibleTypeAnnotations";
static const char *ATTR_NAME_RUNTIME_INVISIBLE_TYPE_ANNOTATIONS = "RuntimeInvisibleTypeAnnotations";
static const char *ATTR_NAME_METHOD_PARAMETERS = "MethodParameters";

extern u4 MAGIC_NUMBER;

static u1 read_u1(u1 *content, u4 *offset)
{
    return (content[(*offset)++] & 0xFF);
}

static u2 read_u2(u1 *content, u4 *offset)
{
    u2 result = 0;
    for (unsigned int i = 0; i < 2; i++)
    {
        result = result << 8 | (content[(*offset)++] & 0xFF);
    }
    return result;
}

static u4 read_u4(u1 *content, u4 *offset)
{
    u4 number = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        u1 temp_u1 = content[(*offset)++];
        number = (number << 8) | (temp_u1 & 0xFF);
    }
    return number;
}

static u1 *read_u1_array(u1 *content, u4 *offset, u4 length)
{
    u1 *u1_array = (u1 *)malloc(length);
    for (unsigned int i = 0; i < length; i++)
    {
        u1_array[i] = (content[(*offset)++]);
    }
    return u1_array;
}

static u2 *read_u2_array(u1 *content, u4 *offset, u4 length)
{
    u2 *u2_array = (u2 *)malloc(length << 1);
    for (unsigned int i = 0; i < length; i++)
    {
        u2_array[i] = read_u2(content, offset);
    }
    return u2_array;
}

static void *malloc_and_reset(size_t size)
{
    void *p = malloc(size);
    memset(p, 0, size);
    return p;
}

static enum attribute_type compare_attr_name(struct constant_pool_entry **p_cp_entries, u2 attr_name_index)
{
    struct constant_pool_entry *p_cpe = p_cp_entries[attr_name_index];
    struct constant_pool_entry_utf8 *p_cpe_utf8 = (struct constant_pool_entry_utf8 *)p_cpe;
    u2 name_length = p_cpe_utf8->length;
    u1 *name_bytes = p_cpe_utf8->bytes;
    return NULL;
}

static struct attribute_element **resolve_attribute_content(u2 name_index, u4 length, u1 *info)
{
    return NULL;
}

static struct attribute_info *read_attribute_info(u1 *content, u4 *offset)
{
    struct attribute_info *p_attr = malloc_and_reset(sizeof(struct attribute_info));
    p_attr->attribute_name_index = read_u2(content, offset);
    p_attr->attribute_length = read_u4(content, offset);
    u1 *info = read_u1_array(content, offset, p_attr->attribute_length);
    p_attr->info = resolve_attribute_content(p_attr->attribute_name_index, p_attr->attribute_length, info);
    return p_attr;
}

static struct attribute_info **read_attribute_info_array(u1 *content, u4 *offset, u2 attributes_count)
{
    for (u2 i = 0; i < attributes_count; i++)
    {
        read_attribute_info(content, offset);
    }
    return NULL;
}

static struct constant_pool_entry **read_constant_pool_info_array(u1 *content, u4 *offset, u2 constant_pool_count)
{
    size_t cp_size = sizeof(struct constant_pool_entry *) * (constant_pool_count);
    struct constant_pool_entry **p_cp_entries = malloc_and_reset(cp_size);

    /** 
     * the index of constant pool started from 1
     */
    for (u2 i = 1; i < constant_pool_count; i++)
    {
        u1 tag = read_u1(content, offset);
        switch (tag)
        {
        case CONSTANT_POOL_TAGS_CLASS:
        {
            struct constant_pool_entry_class *p_cpe_class = (struct constant_pool_entry_class *)malloc_and_reset(sizeof(struct constant_pool_entry_class));
            p_cpe_class->tag = tag;
            p_cpe_class->name_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_class;
            break;
        }

        case CONSTANT_POOL_TAGS_FIELD_REF:
        {
            struct constant_pool_entry_field_ref *p_cpe_field = malloc_and_reset(sizeof(struct constant_pool_entry_field_ref));
            p_cpe_field->tag = tag;
            p_cpe_field->class_index = read_u2(content, offset);
            p_cpe_field->name_and_type_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_field;
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_REF:
        {
            struct constant_pool_entry_method_ref *p_cpe_method = malloc_and_reset(sizeof(struct constant_pool_entry_method_ref));
            p_cpe_method->tag = tag;
            p_cpe_method->class_index = read_u2(content, offset);
            p_cpe_method->name_and_type_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_method;
            break;
        }

        case CONSTANT_POOL_TAGS_INTERFACE_METHOD_REF:
        {
            struct constant_pool_entry_interface_method_ref *p_cpe_interface_method = malloc_and_reset(sizeof(struct constant_pool_entry_interface_method_ref));
            p_cpe_interface_method->tag = tag;
            p_cpe_interface_method->class_index = read_u2(content, offset);
            p_cpe_interface_method->name_and_type_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_interface_method;
            break;
        }

        case CONSTANT_POOL_TAGS_STRING:
        {
            struct constant_pool_entry_string *p_cpe_string = malloc_and_reset(sizeof(struct constant_pool_entry_string));
            p_cpe_string->tag = tag;
            p_cpe_string->string_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_string;
            break;
        }

        case CONSTANT_POOL_TAGS_INTEGER:
        {
            struct constant_pool_entry_integer *p_cpe_integer = malloc_and_reset(sizeof(struct constant_pool_entry_integer));
            p_cpe_integer->tag = tag;
            p_cpe_integer->bytes = read_u4(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_integer;
            break;
        }

        case CONSTANT_POOL_TAGS_FLOAT:
        {
            struct constant_pool_entry_integer *p_cpe_float = malloc_and_reset(sizeof(struct constant_pool_entry_integer));
            p_cpe_float->tag = tag;
            p_cpe_float->bytes = read_u4(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_float;
            break;
        }

        /**
            * https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.4.5
            * 
            * All 8-byte constants take up two entries in the constant_pool table 
            * of the class file. If a CONSTANT_Long_info or CONSTANT_Double_info 
            * structure is the item in the constant_pool table at index n, 
            * then the next usable item in the pool is located at index n+2. 
            * The constant_pool index n+1 must be valid but is considered unusable.
            */
        case CONSTANT_POOL_TAGS_LONG:
        {
            struct constant_pool_entry_long *p_cpe_long = malloc_and_reset(sizeof(struct constant_pool_entry_long));
            p_cpe_long->tag = tag;
            p_cpe_long->high_bytes = read_u4(content, offset);
            p_cpe_long->low_bytes = read_u4(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_long;
            // an extra slot in constant pool
            i++;
            break;
        }

        case CONSTANT_POOL_TAGS_DOUBLE:
        {
            struct constant_pool_entry_double *p_cpe_double = malloc_and_reset(sizeof(struct constant_pool_entry_double));
            p_cpe_double->tag = tag;
            p_cpe_double->high_bytes = read_u4(content, offset);
            p_cpe_double->low_bytes = read_u4(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_double;
            // an extra slot in constant pool
            i++;
            break;
        }

        case CONSTANT_POOL_TAGS_NAME_AND_TYPE:
        {
            struct constant_pool_entry_name_and_type *p_cpe_name_and_type = malloc_and_reset(sizeof(struct constant_pool_entry_name_and_type));
            p_cpe_name_and_type->tag = tag;
            p_cpe_name_and_type->name_index = read_u2(content, offset);
            p_cpe_name_and_type->descriptor_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_name_and_type;
            break;
        }

        case CONSTANT_POOL_TAGS_UTF8:
        {
            struct constant_pool_entry_utf8 *p_cpe_utf8 = malloc_and_reset(sizeof(struct constant_pool_entry_utf8));
            p_cpe_utf8->tag = tag;
            p_cpe_utf8->length = read_u2(content, offset);
            p_cpe_utf8->bytes = read_u1_array(content, offset, p_cpe_utf8->length);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_utf8;
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_HANDLE:
        {
            struct constant_pool_entry_method_handle *p_cpe_mh = malloc_and_reset(sizeof(struct constant_pool_entry_method_handle));
            p_cpe_mh->tag = tag;
            p_cpe_mh->reference_kind = read_u1(content, offset);
            p_cpe_mh->reference_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_mh;
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_TYPE:
        {
            struct constant_pool_entry_method_type *p_cpe_mt = malloc_and_reset(sizeof(struct constant_pool_entry_method_type));
            p_cpe_mt->tag = tag;
            p_cpe_mt->descriptor_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_mt;
            break;
        }

        case CONSTANT_POOL_TAGS_INVOKE_DYNAMIC:
        {
            struct constant_pool_entry_invoke_dynamic *p_cpe_invokedynamic = malloc_and_reset(sizeof(struct constant_pool_entry_invoke_dynamic));
            p_cpe_invokedynamic->tag = tag;
            p_cpe_invokedynamic->bootstrap_method_attr_index = read_u2(content, offset);
            p_cpe_invokedynamic->name_and_type_index = read_u2(content, offset);
            p_cp_entries[i] = (struct constant_pool_entry *)p_cpe_invokedynamic;
            break;
        }

        default:
        {
            printf("unknown constant pool tag: %u\n", tag);
            break;
        }
        }
    }
    return p_cp_entries;
}

static struct field_info **read_field_info_array(u1 *content, u4 *offset, u2 fields_count)
{
    struct field_info **fields = malloc_and_reset(sizeof(struct field_info *) * fields_count);
    for (u2 i = 0; i < fields_count; i++)
    {
        struct field_info *p_field = malloc_and_reset(sizeof(struct field_info));
        p_field->access_flags = read_u2(content, offset);
        p_field->name_index = read_u2(content, offset);
        p_field->descriptor_index = read_u2(content, offset);
        p_field->attributes_count = read_u2(content, offset);
        struct attribute_info **p_attrs = malloc_and_reset(sizeof(struct attribute_info *) * p_field->attributes_count);
        for (u2 j = 0; j < p_field->attributes_count; j++)
        {
            p_attrs[i] = read_attribute_info(content, offset);
        }
    }
    return NULL;
}

static struct method_info **read_method_info_array(u1 *content, u4 *offset, u2 methods_count)
{
    for (u2 i = 0; i < methods_count; i++)
    {
        u2 access_flags = read_u2(content, offset);
        u2 name_index = read_u2(content, offset);
        u2 descriptor_index = read_u2(content, offset);
        u2 attributes_count = read_u2(content, offset);
        for (u2 j = 0; j < attributes_count; j++)
        {
            read_attribute_info(content, offset);
        }
    }
    return NULL;
}

struct class_file *parse(u1 *content)
{
    struct class_file *p_class_file = malloc(sizeof(struct class_file));
    u4 offset = 0;

    // check magic number
    u4 magic_number = read_u4(content, &offset);
    if (MAGIC_NUMBER != magic_number)
    {
        perror("invalid magic number");
        return NULL;
    }
    p_class_file->magic = magic_number;

    // read minor version
    u2 minor_version = read_u2(content, &offset);
    p_class_file->minor_version = minor_version;

    // read major version
    u2 major_version = read_u2(content, &offset);
    p_class_file->major_version = major_version;

    // read constant pool items count
    u2 constant_pool_items_count = read_u2(content, &offset);
    p_class_file->constant_pool_count = constant_pool_items_count;

    // read constant pool
    p_class_file->constant_pool_entries = read_constant_pool_info_array(content, &offset, constant_pool_items_count);

    // read access flags
    u2 access_flags = read_u2(content, &offset);
    p_class_file->access_flags = access_flags;

    // read this class
    u2 this_class_constant_pool_index = read_u2(content, &offset);
    p_class_file->this_class = this_class_constant_pool_index;

    // read super class
    u2 super_class_constant_pool_index = read_u2(content, &offset);
    p_class_file->super_class = super_class_constant_pool_index;

    // read interfaces count
    u2 interfaces_count = read_u2(content, &offset);
    p_class_file->interfaces_count = interfaces_count;

    // read interfaces
    u2 *interfaces = read_u2_array(content, &offset, interfaces_count);
    p_class_file->interfaces = interfaces;

    // read fields count
    u2 fields_count = read_u2(content, &offset);
    p_class_file->fields_count = fields_count;

    // read fields
    p_class_file->fields = read_field_info_array(content, &offset, fields_count);

    // read methods count
    u2 methods_count = read_u2(content, &offset);
    p_class_file->methods_count = methods_count;

    // read methods
    p_class_file->methods = read_method_info_array(content, &offset, methods_count);

    // read attributes count
    u2 attributes_count = read_u2(content, &offset);
    p_class_file->attributes_count = attributes_count;

    // read attributes
    p_class_file->attributes = read_attribute_info_array(content, &offset, attributes_count);

    return p_class_file;
}
