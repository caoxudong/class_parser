#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

static struct attribute_info ** read_attribute_info_array(u1 *content, u4 *offset, u2 attributes_count)
{
    for (u2 i = 0; i < attributes_count; i++)
    {
        read_attribute_info(content, offset);
    }
}

static struct constant_pool_attribute **read_constant_pool_info_array(u1 *content, u4 *offset, u2 constant_pool_count)
{
    /** 
     * the real count of constant pool info is (constant_pool_count - 1)
     * with the two more slot, finding the target constant pool item can be
     * constant_pool[slot_number]
     */
    for (u2 i = 1; i <= constant_pool_count - 1; i++)
    {
        u1 tag = read_u1(content, offset);
        switch (tag)
        {
        case CONSTANT_POOL_TAGS_CLASS:
        {
            u2 name_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_CLASS, name_index = %u\n", i, name_index);
            break;
        }

        case CONSTANT_POOL_TAGS_FIELD_REF:
        {
            u2 class_index = read_u2(content, offset);
            u2 name_and_type_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_FIELD_REF, class_index = %u, name_and_type_index = %u\n", i, class_index, name_and_type_index);
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_REF:
        {
            u2 class_index = read_u2(content, offset);
            u2 name_and_type_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_METHOD_REF, class_index = %u, name_and_type_index = %u\n", i, class_index, name_and_type_index);
            break;
        }

        case CONSTANT_POOL_TAGS_INTERFACE_METHOD_REF:
        {
            u2 class_index = read_u2(content, offset);
            u2 name_and_type_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_INTERFACE_METHOD_REF, class_index = %u, name_and_type_index = %u\n", i, class_index, name_and_type_index);
            break;
        }

        case CONSTANT_POOL_TAGS_STRING:
        {
            u2 string_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_STRING, string_index = %u\n", i, string_index);
            break;
        }

        case CONSTANT_POOL_TAGS_INTEGER:
        {
            u4 integer_value = read_u4(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_INTEGER, integer_value = %u\n", i, integer_value);
            break;
        }

        case CONSTANT_POOL_TAGS_FLOAT:
        {
            u4 float_value = read_u4(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_FLOAT, float_value = %u\n", i, float_value);
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
            u4 high_bytes = read_u4(content, offset);
            u4 low_bytes = read_u4(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_LONG, long_value = %u\n", i, (0xFFFFFFFF & high_bytes << 31) | low_bytes);
            // an extra slot in constant pool
            i++;
            break;
        }

        case CONSTANT_POOL_TAGS_DOUBLE:
        {
            u4 high_bytes = read_u4(content, offset);
            u4 low_bytes = read_u4(content, offset);
            u8 hex_value = (0xFFFFFFFF & high_bytes << 31) | low_bytes;
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_DOUBLE, double_value = %f\n", i, *(double *)&hex_value);
            // an extra slot in constant pool
            i++;
            break;
        }

        case CONSTANT_POOL_TAGS_NAME_AND_TYPE:
        {
            u2 name_index = read_u2(content, offset);
            u2 descriptor_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_NAME_AND_TYPE, name_index = %u, descriptor_index = %u\n", i, name_index, descriptor_index);
            break;
        }

        case CONSTANT_POOL_TAGS_UTF8:
        {
            u2 length = read_u2(content, offset);
            u1 *utf8_content = read_u1_array(content, offset, length);
            setlocale(LC_ALL, "");
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_UTF8, length = %u, content = ", i, length);
            for (u2 utf8_content_index = 0; utf8_content_index < length; utf8_content_index++)
            {
                printf("%lc", utf8_content[utf8_content_index]);
            }
            printf("\n");
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_HANDLE:
        {
            u1 reference_kind = read_u1(content, offset);
            u2 reference_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_METHOD_HANDLE, ref_kind = %u, ref_index = %u\n", i, reference_kind, reference_index);
            break;
        }

        case CONSTANT_POOL_TAGS_METHOD_TYPE:
        {
            u2 descriptor_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_METHOD_TYPE, desc_index = %u\n", i, descriptor_index);
            break;
        }

        case CONSTANT_POOL_TAGS_INVOKE_DYNAMIC:
        {
            u2 bootstrap_method_attr_index = read_u2(content, offset);
            u2 name_and_type_index = read_u2(content, offset);
            printf("constant pool item %u, tag = CONSTANT_POOL_TAGS_METHOD_TYPE, bootstrap_method_attr_index = %u, name_and_type_index = %u\n", i, bootstrap_method_attr_index, name_and_type_index);
            break;
        }

        default:
        {
            printf("unknown constant pool tag: %u\n", tag);
            break;
        }
        }
    }
}

static struct field_info ** read_field_info_array(u1 *content, u4 *offset, u2 fields_count)
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
}

static struct method_info ** read_method_info_array(u1 *content, u4 *offset, u2 methods_count)
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
}

struct class_file *parse(u1 *content)
{
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
    struct class_file *p_class_file = (struct class_file *)malloc(sizeof(struct class_file));
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
    p_class_file->constant_pool = read_constant_pool_info_array(content, &offset, constant_pool_items_count);

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