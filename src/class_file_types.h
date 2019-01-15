#pragma once

namespace jvm
{
    // reference:    https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html
    namespace class_file_types
    {
        const int MAGIC_NUMBER = 0xCAFEBABE;

        typedef unsigned int u4;
        typedef unsigned short u2;
        typedef unsigned char u1;

        // class access flags
        const int CLASS_ACCESS_FLAGS_ACC_PUBLIC     = 0x0001;
        const int CLASS_ACCESS_FLAGS_ACC_FINAL      = 0x0010;
        const int CLASS_ACCESS_FLAGS_ACC_SUPER      = 0x0020;
        const int CLASS_ACCESS_FLAGS_ACC_INTERFACE  = 0x0200;
        const int CLASS_ACCESS_FLAGS_ACC_ABSTRACT   = 0x0400;
        const int CLASS_ACCESS_FLAGS_ACC_SYNTHETIC  = 0x1000;
        const int CLASS_ACCESS_FLAGS_ACC_ANNOTATION = 0x2000;
        const int CLASS_ACCESS_FLAGS_ACC_ENUM       = 0x4000;

        // field access flags
        const int FIELD_ACCESS_FLAGS_ACC_PUBLIC    = 0x0001;
        const int FIELD_ACCESS_FLAGS_ACC_PRIVATE   = 0x0002;
        const int FIELD_ACCESS_FLAGS_ACC_PROTECTED = 0x0004;
        const int FIELD_ACCESS_FLAGS_ACC_STATIC    = 0x0008;
        const int FIELD_ACCESS_FLAGS_ACC_FINAL     = 0x0010;
        const int FIELD_ACCESS_FLAGS_ACC_VOLATILE  = 0x0040;
        const int FIELD_ACCESS_FLAGS_ACC_TRANSIENT = 0x0080;
        const int FIELD_ACCESS_FLAGS_ACC_SYNTHETIC = 0x1000;
        const int FIELD_ACCESS_FLAGS_ACC_ENUM      = 0x4000;

        // method access flags
        const int METHOD_ACCESS_FLAGS_ACC_PUBLIC       = 0x0001;
        const int METHOD_ACCESS_FLAGS_ACC_PRIVATE      = 0x0002;
        const int METHOD_ACCESS_FLAGS_ACC_PROTECTED    = 0x0004;
        const int METHOD_ACCESS_FLAGS_ACC_STATIC       = 0x0008;
        const int METHOD_ACCESS_FLAGS_ACC_FINAL        = 0x0010;
        const int METHOD_ACCESS_FLAGS_ACC_SYNCHRONIZED = 0x0020;
        const int METHOD_ACCESS_FLAGS_ACC_BRIDGE       = 0x0040;
        const int METHOD_ACCESS_FLAGS_ACC_VARARGS      = 0x0080;
        const int METHOD_ACCESS_FLAGS_ACC_NATIVE       = 0x0100;
        const int METHOD_ACCESS_FLAGS_ACC_ABSTRACT     = 0x0400;
        const int METHOD_ACCESS_FLAGS_ACC_STRICT       = 0x0800;
        const int METHOD_ACCESS_FLAGS_ACC_SYNTHETIC    = 0x1000;
        
        enum ConstantPoolTags
        {
            CONSTANT_Class              = 7,
            CONSTANT_FieldRef           = 9,
            CONSTANT_MethodRef          = 10,
            CONSTANT_InterfaceMethodRef = 11,
            CONSTANT_String             = 8,
            CONSTANT_Integer            = 3,
            CONSTANT_Float              = 4,
            CONSTANT_Long               = 5,
            CONSTANT_Double             = 6,
            CONSTANT_NameAndType        = 12,
            CONSTANT_Utf8               = 1,
            CONSTANT_MethodHandle       = 15,
            CONSTANT_MethodType         = 16,
            CONSTANT_InvokeDynamic      = 18,
        };

        struct ConstantPoolInfoBase
        {
            u1 tag;

            virtual ~ConstantPoolInfoBase()
            {

            }
        };

        struct ConstantClassInfo : public ConstantPoolInfoBase
        {
            u2 name_index;
        };

        struct ConstantFieldRefInfo : public ConstantPoolInfoBase
        {
            u2 class_index;
            u2 name_and_type_index;
        };

        struct ConstantMethodRefInfo : public ConstantPoolInfoBase
        {
            u2 class_index;
            u2 name_and_type_index;
        };

        struct ConstantInterfaceMethodRefInfo : public ConstantPoolInfoBase
        {
            u2 class_index;
            u2 name_and_type_index;
        };

        struct ConstantStringInfo : public ConstantPoolInfoBase
        {
            u2 string_index;
        };

        struct ConstantIntegerInfo : public ConstantPoolInfoBase
        {
            u4 bytes;
        };

        struct ConstantFloatInfo : public ConstantPoolInfoBase
        {
            u4 bytes;
        };

        struct ConstantLongInfo : public ConstantPoolInfoBase
        {
            u4 high_bytes;
            u4 low_bytes;
        };

        struct ConstantDoubleInfo : public ConstantPoolInfoBase
        {
            u4 high_bytes;
            u4 low_bytes;
        };

        struct ConstantNameAndTypeInfo : public ConstantPoolInfoBase
        {
            u2 name_index;
            u2 descriptor_index;
        };

        struct ConstantUtf8Info : public ConstantPoolInfoBase
        {
            u2 length;
            u1 *bytes;
        };

        struct ConstantMethodHandleInfo : public ConstantPoolInfoBase
        {
            u1 reference_kind;
            u2 reference_index;
        };

        struct ConstantMethodTypeInfo : public ConstantPoolInfoBase
        {
            u2 descriptor_index;
        };

        struct ConstantInvokeDynamicInfo : public ConstantPoolInfoBase
        {
            u2 bootstrap_method_attr_index;
            u2 name_and_type_index;
        };

        struct AttributeInfo
        {
            u2 attribute_name_index;
            u4 attribute_length;
            u1 *info;

            ~AttributeInfo()
            {
                delete[] info;
            }
        };

        struct FieldInfo
        {
            u2            access_flags;
            u2            name_index;
            u2            descriptor_index;
            u2            attributes_count;
            AttributeInfo **attributes;

            ~FieldInfo()
            {
                delete[] attributes;
            }
        };

        struct MethodInfo
        {
            u2            access_flags;
            u2            name_index;
            u2            descriptor_index;
            u2            attributes_count;
            AttributeInfo **attributes;

            ~MethodInfo()
            {
                delete[] attributes;
            }
        };

        struct ClassFile
        {
            u4                   magic;
            u2                   minor_vertion;
            u2                   major_vertion;
            u2                   constant_pool_count;
            ConstantPoolInfoBase **constant_pool;
            u2                   access_flags;
            u2                   this_class;
            u2                   super_class;
            u2                   interfaces_count;
            u2                   *interfaces;
            u2                   fields_count;
            FieldInfo            **fields;
            u2                   methods_count;
            MethodInfo           **methods;
            u2                   attributes_count;
            AttributeInfo        **attributes;

            ~ClassFile()
            {
                delete[] constant_pool;
                delete[] fields;
                delete[] methods;
                delete[] attributes;
            }
        };

        void printClassFile(ClassFile*);
    }
}