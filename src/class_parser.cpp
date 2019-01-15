#include <iostream>
#include "class_parser.h"
#include "class_file_types.h"
#include "load_class_exception.h"
#include "error_code.h"

using namespace std;
using namespace jvm::class_file_types;
using namespace jvm::exception;

namespace jvm
{
    namespace class_loader
    {
        ClassPaser::ClassPaser()
        {
        }

        ClassFile * ClassPaser::parse(char* content)
        {
            u4 offset = 0;

            // check magic number
            ClassFile *p_class_file = new ClassFile();
            u4 magic_number = read_u4(content, &offset);
            if (MAGIC_NUMBER == magic_number)
            {
                p_class_file->magic = magic_number;
            }            
            else
            {
                throw LoadClassException(INVALID_MAGIC_NUMBER);
            }
            
            // read minor version
            p_class_file->minor_vertion = read_u2(content, &offset);

            // read major version
            p_class_file->major_vertion = read_u2(content, &offset);

            // read constant pool count
            p_class_file->constant_pool_count = read_u2(content, &offset);

            // read constant pool
            p_class_file->constant_pool = 
                read_constant_pool_info_array(
                    content, &offset, p_class_file->constant_pool_count);

            // read access flags
            p_class_file->access_flags = read_u2(content, &offset);

            // read this class
            p_class_file->this_class = read_u2(content, &offset);

            // read super class
            p_class_file->super_class = read_u2(content, &offset);

            // read interfaces count
            p_class_file->interfaces_count = read_u2(content, &offset);

            // read interfaces
            p_class_file->interfaces = 
                read_u2_array(content, &offset, p_class_file->interfaces_count);

            // read fields count
            p_class_file->fields_count = read_u2(content, &offset);

            // read fields
            p_class_file->fields = 
                read_field_info_array(content, &offset, p_class_file->fields_count);

            // read methods count
            p_class_file->methods_count = read_u2(content, &offset);

            // read methods
            p_class_file->methods = 
                read_method_info_array(content, &offset, p_class_file->methods_count);

            // read attributes count
            p_class_file->attributes_count = read_u2(content, &offset);

            // read attributes
            p_class_file->attributes = 
                read_attribute_info_array(
                    content, &offset, p_class_file->attributes_count);

            return p_class_file;
        }

        ClassPaser::~ClassPaser()
        {
        }
    }
}


u1 read_u1(char* content, u4 *offset)
{
    return (content[(*offset)++] | 0xFF);
}

u2 read_u2(char* content, u4 *offset)
{
    u2 result = 0;
    for (unsigned int i = 0; i < 2; i++)
    {
        result = result << 8 | (content[(*offset)++] & 0xFF);
    }
    return result;
}

u4 read_u4(char* content, u4 *offset)
{
    std::cout << std::hex;
    
    u4 magic_number = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        char temp_char = content[(*offset)++];
        magic_number = (magic_number << 8) | (temp_char & 0xFF);
    }
    return magic_number;
}

u1 * read_u1_array(char* content, u4 *offset, u4 length)
{
    u1 *u1_array = new u1[length];
    for (unsigned int i = 0; i < length; i++)
    {
        u1_array[i] = (content[*offset + i] | 0xFF);
    }
    *offset += length;
    return u1_array;
}

u2 *read_u2_array(
    char* content, u4 *offset, u4 length)
{
    u2 *u2_array = new u2[length];
    for (unsigned int i = 0; i < length; i++)
    {
        u2_array[i] = read_u2(content, offset);
    }
    return u2_array;
}

AttributeInfo * read_attribute_info(
    char* content, u4 *offset)
{
    AttributeInfo *result = new AttributeInfo;
    u2 attribute_name_index = read_u2(content, offset);
    u4 attribute_length = read_u4(content, offset);
    u1 *info = read_u1_array(content, offset, attribute_length);
    result->attribute_name_index = attribute_name_index;
    result->attribute_length = attribute_length;
    result->info = info;
    return result;
}

AttributeInfo **read_attribute_info_array(
    char* content, u4 *offset, u2 attributes_count)
{
    AttributeInfo **p_attributes = new AttributeInfo*[attributes_count];

    for (u2 i = 0; i < attributes_count; i++)
    {
        AttributeInfo *p_attribute = read_attribute_info(content, offset);
        p_attributes[i] = p_attribute;
    }

    return p_attributes;
}

ConstantPoolInfoBase ** read_constant_pool_info_array(
    char* content, u4 *offset, u2 constant_pool_count)
{
    /** the real count of constant pool info is (constant_pool_count - 1)
     *    with the two more slot, find the target constant pool item can be
     *    constant_pool[slot_number]
     */
    ConstantPoolInfoBase **constant_pool_info_array = 
        new ConstantPoolInfoBase*[constant_pool_count];
    for (u2 i = 1; i < constant_pool_count; i++)
    {
        u1 tag = read_u1(content, offset);
        switch (tag)
        {
            case CONSTANT_Class:
            {
                ConstantClassInfo * p_constant_pool_info =
                    new ConstantClassInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->name_index = read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_FieldRef:
            {
                ConstantFieldRefInfo * p_constant_pool_info =
                    new ConstantFieldRefInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->class_index = read_u2(content, offset);
                p_constant_pool_info->name_and_type_index =
                    read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_MethodRef:
            {
                ConstantMethodRefInfo * p_constant_pool_info =
                    new ConstantMethodRefInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->class_index = read_u2(content, offset);
                p_constant_pool_info->name_and_type_index =
                    read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_InterfaceMethodRef:
            {
                ConstantMethodRefInfo * p_constant_pool_info =
                    new ConstantMethodRefInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->class_index = read_u2(content, offset);
                p_constant_pool_info->name_and_type_index =
                    read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_String:
            {
                ConstantStringInfo * p_constant_pool_info =
                    new ConstantStringInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->string_index = read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_Integer:
            {
                ConstantIntegerInfo * p_constant_pool_info =
                    new ConstantIntegerInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->bytes = read_u4(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_Float:
            {
                ConstantFloatInfo * p_constant_pool_info =
                    new ConstantFloatInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->bytes = read_u4(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
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
            case CONSTANT_Long:
            {
                ConstantLongInfo * p_constant_pool_info =
                    new ConstantLongInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->high_bytes = read_u4(content, offset);
                p_constant_pool_info->low_bytes = read_u4(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                // an extra slot in constant pool
                i++;
                break;
            }

            case CONSTANT_Double:
            {
                ConstantDoubleInfo * p_constant_pool_info =
                    new ConstantDoubleInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->high_bytes = read_u4(content, offset);
                p_constant_pool_info->low_bytes = read_u4(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                // an extra slot in constant pool
                i++;
                break;
            }

            case CONSTANT_NameAndType:
            {
                ConstantNameAndTypeInfo * p_constant_pool_info =
                    new ConstantNameAndTypeInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->name_index = read_u2(content, offset);
                p_constant_pool_info->descriptor_index = read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_Utf8:
            {
                ConstantUtf8Info * p_constant_pool_info = new ConstantUtf8Info;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->length = read_u2(content, offset);
                p_constant_pool_info->bytes =
                    read_u1_array(content, offset, p_constant_pool_info->length);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_MethodHandle:
            {
                ConstantMethodHandleInfo * p_constant_pool_info = 
                    new ConstantMethodHandleInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->reference_kind = read_u1(content, offset);
                p_constant_pool_info->reference_index = read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_MethodType:
            {
                ConstantMethodTypeInfo * p_constant_pool_info = 
                    new ConstantMethodTypeInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->descriptor_index = read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            case CONSTANT_InvokeDynamic:
            {
                ConstantInvokeDynamicInfo * p_constant_pool_info = 
                    new ConstantInvokeDynamicInfo;
                p_constant_pool_info->tag = tag;
                p_constant_pool_info->bootstrap_method_attr_index = 
                    read_u2(content, offset);
                p_constant_pool_info->name_and_type_index = read_u2(content, offset);
                constant_pool_info_array[i] = p_constant_pool_info;
                break;
            }

            default: 
            {
                break;
            }
        }
    }

    return constant_pool_info_array;
}

FieldInfo **read_field_info_array(
    char* content, u4 *offset, u2 fields_count)
{
    FieldInfo **p_fields = new FieldInfo*[fields_count];
    for (u2 i = 0; i < fields_count; i++)
    {
        u2 access_flags = read_u2(content, offset);
        u2 name_index = read_u2(content, offset);
        u2 descriptor_index = read_u2(content, offset);
        u2 attributes_count = read_u2(content, offset);
        AttributeInfo **p_attributes = new AttributeInfo*[attributes_count];
        for (u2 j = 0; j < attributes_count; j++)
        {
            AttributeInfo *p_attribute = read_attribute_info(content, offset);
            p_attributes[j] = p_attribute;
        }

        FieldInfo *p_field = new FieldInfo;
        p_field->access_flags = access_flags;
        p_field->name_index = name_index;
        p_field->descriptor_index = descriptor_index;
        p_field->attributes_count = attributes_count;
        p_field->attributes = p_attributes;

        p_fields[i] = p_field;
    }

    return p_fields;
}

MethodInfo **read_method_info_array(
    char* content, u4 *offset, u2 methods_count)
{
    MethodInfo **p_methods = new MethodInfo*[methods_count];
    for (u2 i = 0; i < methods_count; i++)
    {
        u2 access_flags = read_u2(content, offset);
        u2 name_index = read_u2(content, offset);
        u2 descriptor_index = read_u2(content, offset);
        u2 attributes_count = read_u2(content, offset);
        AttributeInfo **p_attributes = new AttributeInfo*[attributes_count];
        for (u2 j = 0; j < attributes_count; j++)
        {
            AttributeInfo *p_attribute = read_attribute_info(content, offset);
            p_attributes[j] = p_attribute;
        }

        MethodInfo *p_method = new MethodInfo;
        p_method->access_flags = access_flags;
        p_method->name_index = name_index;
        p_method->descriptor_index = descriptor_index;
        p_method->attributes_count = attributes_count;
        p_method->attributes = p_attributes;

        p_methods[i] = p_method;
    }
    return p_methods;
}