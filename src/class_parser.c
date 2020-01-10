#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "class_file_types.h"

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
        u1_array[i] = (content[*offset + i]);
    }
    *offset += length;
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

static struct constant_pool_entry *build_cp_entry(u1 tag, u1 *content)
{
    size_t cp_entry_size = sizeof(struct constant_pool_entry);
    struct constant_pool_entry *p_cp_entry = malloc_and_reset(cp_entry_size);
    p_cp_entry->tag = tag;
    p_cp_entry->content = content;
    return p_cp_entry;
}

static void fill_constant_pool(struct constant_pool_entry **p_cp_entries, u2 index, u1 tag, u1 *content)
{
    struct constant_pool_entry *p_cp_entry = build_cp_entry(tag, content);
    p_cp_entries[index] = p_cp_entry;
}

static void resolve_attribute_content(u2 name_index, u4 length, u1 *info)
{
}

static void read_attribute_info(u1 *content, u4 *offset)
{
    u2 attribute_name_index = read_u2(content, offset);
    u4 attribute_length = read_u4(content, offset);
    u1 *info = read_u1_array(content, offset, attribute_length);
    printf("attribute: name_index = %u, length = %u, info = %s\n", attribute_name_index, attribute_length, info);
    resolve_attribute_content(attribute_name_index, attribute_length, info);
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
    size_t cp_size = sizeof(struct constant_pool_entry *) * constant_pool_count;
    struct constant_pool_entry **p_cp_entries = malloc_and_reset(cp_size);
    size_t cp_entry_size = sizeof(struct constant_pool_entry);

    /** 
     * the real count of constant pool info is (constant_pool_count - 1)
     * with the two more slot, finding the target constant pool item can be
     * constant_pool[slot_number]
     */
    for (u2 i = 1; i <= constant_pool_count; i++)
    {
        u1 tag = read_u1(content, offset);
        u1 *p_content;
        switch (tag)
        {
        case CONSTANT_POOL_TAGS_CLASS:
        {
            struct constant_pool_entry_class *p_cpe_class = (struct constant_pool_entry_class *)malloc_and_reset(sizeof(struct constant_pool_entry_class));
            p_cpe_class->name_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_class;
            break;
        }

        case CONSTANT_POOL_TAGS_FIELD_REF:
        {
            struct constant_pool_entry_field_ref *p_cpe_field = malloc_and_reset(sizeof(struct constant_pool_entry_field_ref));
            p_cpe_field->class_index = read_u2(content, offset);
            p_cpe_field->name_and_type_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_field;
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_REF:
        {
            struct constant_pool_entry_method_ref *p_cpe_method = malloc_and_reset(sizeof(struct constant_pool_entry_method_ref));
            p_cpe_method->class_index = read_u2(content, offset);
            p_cpe_method->name_and_type_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_method;
            break;
        }

        case CONSTANT_POOL_TAGS_INTERFACE_METHOD_REF:
        {
            struct constant_pool_entry_interface_method_ref *p_cpe_interface_method = malloc_and_reset(sizeof(struct constant_pool_entry_interface_method_ref));
            p_cpe_interface_method->class_index = read_u2(content, offset);
            p_cpe_interface_method->name_and_type_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_interface_method;
            break;
        }

        case CONSTANT_POOL_TAGS_STRING:
        {
            struct constant_pool_entry_string *p_cpe_string = malloc_and_reset(sizeof(struct constant_pool_entry_string));
            p_cpe_string->string_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_string;
            break;
        }

        case CONSTANT_POOL_TAGS_INTEGER:
        {
            struct constant_pool_entry_integer *p_cpe_integer = malloc_and_reset(sizeof(struct constant_pool_entry_integer));
            p_cpe_integer->bytes = read_u4(content, offset);
            p_content = (u1*)p_cpe_integer;
            break;
        }

        case CONSTANT_POOL_TAGS_FLOAT:
        {
            struct constant_pool_entry_integer *p_cpe_float = malloc_and_reset(sizeof(struct constant_pool_entry_integer));
            p_cpe_float->bytes = read_u4(content, offset);
            p_content = (u1*)p_cpe_float;
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
            p_cpe_long->high_bytes = read_u4(content, offset);
            p_cpe_long->low_bytes = read_u4(content, offset);
            p_content = (u1*)p_cpe_long;
            // an extra slot in constant pool
            i++;
            break;
        }

        case CONSTANT_POOL_TAGS_DOUBLE:
        {
            struct constant_pool_entry_double *p_cpe_double = malloc_and_reset(sizeof(struct constant_pool_entry_double));
            p_cpe_double->high_bytes = read_u4(content, offset);
            p_cpe_double->low_bytes = read_u4(content, offset);
            p_content = (u1*)p_cpe_double;
            // an extra slot in constant pool
            i++;
            break;
        }

        case CONSTANT_POOL_TAGS_NAME_AND_TYPE:
        {
            struct constant_pool_entry_name_and_type *p_cpe_name_and_type = malloc_and_reset(sizeof(struct constant_pool_entry_name_and_type));
            p_cpe_name_and_type->name_index = read_u2(content, offset);
            p_cpe_name_and_type->descriptor_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_name_and_type;
            break;
        }

        case CONSTANT_POOL_TAGS_UTF8:
        {
            struct constant_pool_entry_utf8 *p_cpe_utf8 = malloc_and_reset(sizeof(struct constant_pool_entry_utf8));
            p_cpe_utf8->length = read_u2(content, offset);
            p_cpe_utf8->bytes = read_u1_array(content, offset, p_cpe_utf8->length);
            p_content = (u1*)p_cpe_utf8;
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_HANDLE:
        {
            struct constant_pool_entry_method_handle *p_cpe_mh = malloc_and_reset(sizeof(struct constant_pool_entry_method_handle));
            p_cpe_mh->reference_kind = read_u1(content, offset);
            p_cpe_mh->reference_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_mh;
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_TYPE:
        {
            struct constant_pool_entry_method_type *p_cpe_mt = malloc_and_reset(sizeof(struct constant_pool_entry_method_type));
            p_cpe_mt->descriptor_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_mt;
            break;
        }

        case CONSTANT_POOL_TAGS_INVOKE_DYNAMIC:
        {
            struct constant_pool_entry_invoke_dynamic *p_cpe_invokedynamic = malloc_and_reset(sizeof(struct constant_pool_entry_invoke_dynamic));
            p_cpe_invokedynamic->bootstrap_method_attr_index = read_u2(content, offset);
            p_cpe_invokedynamic->name_and_type_index = read_u2(content, offset);
            p_content = (u1*)p_cpe_invokedynamic;
            break;
        }

        default:
        {
            printf("unknown constant pool tag: %u\n", tag);
            break;
        }
        }

        fill_constant_pool(p_cp_entries, i, tag, p_content);
    }
    return p_cp_entries;
}

static struct field_info **read_field_info_array(u1 *content, u4 *offset, u2 fields_count)
{
    for (u2 i = 0; i < fields_count; i++)
    {
        u2 access_flags = read_u2(content, offset);
        u2 name_index = read_u2(content, offset);
        u2 descriptor_index = read_u2(content, offset);
        printf("field info: acc_flags = %u, name_index = %u, desc_index = %u\n", access_flags, name_index, descriptor_index);
        u2 attributes_count = read_u2(content, offset);
        for (u2 j = 0; j < attributes_count; j++)
        {
            read_attribute_info(content, offset);
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
        printf("field info: acc_flags = %u, name_index = %u, desc_index = %u\n", access_flags, name_index, descriptor_index);
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
    if (MAGIC_NUMBER == magic_number)
    {
        printf("magic number: %x\n", magic_number);
    }
    else
    {
        perror("invalid magic number");
        return NULL;
    }
    p_class_file->magic = magic_number;

    // read minor version
    u2 minor_version = read_u2(content, &offset);
    p_class_file->minor_version = minor_version;
    printf("minor_version: %u\n", minor_version);

    // read major version
    u2 major_version = read_u2(content, &offset);
    p_class_file->major_version = major_version;
    printf("minor_version: %u\n", major_version);

    // read constant pool items count
    u2 constant_pool_items_count = read_u2(content, &offset);
    p_class_file->constant_pool_count = constant_pool_items_count;
    printf("constant pool items count: %u\n", constant_pool_items_count);

    // read constant pool
    p_class_file->constant_pool_entries = read_constant_pool_info_array(content, &offset, constant_pool_items_count);

    // read access flags
    u2 access_flags = read_u2(content, &offset);
    p_class_file->access_flags = access_flags;
    printf("access flags: %u\n", access_flags);

    // read this class
    u2 this_class_constant_pool_index = read_u2(content, &offset);
    p_class_file->this_class = this_class_constant_pool_index;
    printf("this class constant pool index: %u\n", this_class_constant_pool_index);

    // read super class
    u2 super_class_constant_pool_index = read_u2(content, &offset);
    p_class_file->super_class = super_class_constant_pool_index;
    printf("super class constant pool index: %u\n", super_class_constant_pool_index);

    // read interfaces count
    u2 interfaces_count = read_u2(content, &offset);
    p_class_file->interfaces_count = interfaces_count;
    printf("interfaces count: %u\n", interfaces_count);

    // read interfaces
    u2 *interfaces = read_u2_array(content, &offset, interfaces_count);
    p_class_file->interfaces = interfaces;
    for (u2 i = 0; i < interfaces_count; i++)
    {
        printf("interface: %u\n", interfaces[i]);
    }

    // read fields count
    u2 fields_count = read_u2(content, &offset);
    p_class_file->fields_count = fields_count;
    printf("fields count: %u\n", fields_count);

    // read fields
    p_class_file->fields = read_field_info_array(content, &offset, fields_count);

    // read methods count
    u2 methods_count = read_u2(content, &offset);
    p_class_file->methods_count = methods_count;
    printf("methods count: %u\n", methods_count);

    // read methods
    p_class_file->methods = read_method_info_array(content, &offset, methods_count);

    // read attributes count
    u2 attributes_count = read_u2(content, &offset);
    p_class_file->attributes_count = attributes_count;
    printf("attributes count: %u\n", attributes_count);

    // read attributes
    p_class_file->attributes = read_attribute_info_array(content, &offset, attributes_count);

    return p_class_file;
}
