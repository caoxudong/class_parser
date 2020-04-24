#pragma once

typedef unsigned long u8;
typedef unsigned int u4;
typedef unsigned short u2;
typedef unsigned char u1;

enum attribute_type
{
    ATTR_CONSTANT_VALUE = 1,
    ATTR_CODE,
    ATTR_EXCEPTIONS,
    ATTR_SOURCE_FILE,
    ATTR_LINE_NUMBER_TABLE,
    ATTR_LOCAL_VARIABLE_TABLE,
    ATTR_INNER_CLASSES,
    ATTR_SYNTHETIC,
    ATTR_DEPRECATED,
    ATTR_ENCLOSING_METHOD,
    ATTR_SIGNATURE,
    ATTR_SOURCE_DEBUG_EXTENSION,
    ATTR_LOCAL_VARIABLE_TYPE_TABLE,
    ATTR_RUNTIME_VISIBLE_ANNOTATIONS,
    ATTR_RUNTIME_INVISIBLE_ANNOTATIONS,
    ATTR_RUNTIME_VISIABLE_PARAMETER_ANNOTATIONS,
    ATTR_RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS,
    ATTR_ANNOTATION_DEFAULT,
    ATTR_STACK_MAP_TABLE,
    ATTR_BOOTSTRAP_METHODS,
    ATTR_RUNTIME_VISIBLE_TYPE_ANNOTATIONS,
    ATTR_RUNTIME_INVISIBLE_TYPE_ANNOTATIONS,
    ATTR_METHOD_PARAMETERS
};

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

// constant pool entry
struct constant_pool_entry
{
    u1 tag;
    u1 *content;
};

struct constant_pool_entry_class
{
    u1 tag;
    u2 name_index;
};

struct constant_pool_entry_field_ref
{
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
};

struct constant_pool_entry_method_ref
{
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
};

struct constant_pool_entry_interface_method_ref
{
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
};

struct constant_pool_entry_string
{
    u1 tag;
    u2 string_index;
};

struct constant_pool_entry_integer
{
    u1 tag;
    u4 bytes;
};

struct constant_pool_entry_float
{
    u1 tag;
    u4 bytes;
};

struct constant_pool_entry_long
{
    u1 tag;
    u4 high_bytes;
    u4 low_bytes;
};

struct constant_pool_entry_double
{
    u1 tag;
    u4 high_bytes;
    u4 low_bytes;
};

struct constant_pool_entry_name_and_type
{
    u1 tag;
    u2 name_index;
    u2 descriptor_index;
};

struct constant_pool_entry_utf8
{
    u1 tag;
    u2 length;
    u1 *bytes;
};

struct constant_pool_entry_method_handle
{
    u1 tag;
    u1 reference_kind;
    u2 reference_index;
};

struct constant_pool_entry_method_type
{
    u1 tag;
    u2 descriptor_index;
};

struct constant_pool_entry_invoke_dynamic
{
    u1 tag;
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};

struct field_info
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    struct attribute_info **attributes;
};

struct method_info
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    struct attribute_info **attributes;
};

struct attribute_body_constant_value
{
    u2 cp_index;
};

struct attribute_body_code
{
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1 *code;
    u2 exception_table_length;
    struct attribute_body_code_exception_table **exception_table;
    u2 attributes_count;
    struct attribute_info **attributes;
};

struct attribute_body_code_exception_table
{
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
};

struct attribute_body_stack_map_table
{
    u2 number_of_entries;
    struct attribute_body_stack_map_table_frame **entries;
};

struct attribute_body_stack_map_table_frame
{
};

struct attribute_body_exception
{
    u2 number_of_exceptions;
    u2 *exception_index_table;
};

struct attribute_body_inner_class
{
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    struct attribute_body_inner_class_classes_entry **classes;
};

struct attribute_body_inner_class_classes_entry
{
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;
};

struct attribute_body_enclosing_method
{
    u2 class_index;
    u2 method_index;
};

struct attribute_body_synthetic
{
};

struct attribute_body_signature
{
    u2 signature_index;
};

struct attribute_body_source_file
{
    u2 sourcefile_index;
};

struct attribute_body_source_debug_extension
{
    u1 *debug_extension;
};

struct attribute_body_line_number_table
{
    u2 line_number_table_length;
    struct attribute_body_line_number_table_entry **line_number_table;
};

struct attribute_body_line_number_table_entry
{
    u2 start_pc;
    u2 line_number;
};

struct attribute_body_local_variable_table
{
    u2 local_variable_table_length;
    struct attribute_body_local_variable_table_entry **local_variable_table;
};

struct attribute_body_local_variable_table_entry
{
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
};

struct attribute_body_local_variable_type_table
{
    u2 local_variable_table_length;
    struct attribute_body_local_variable_type_table_entry **local_variable_table;
};

struct attribute_body_local_variable_type_table_entry
{
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
};

struct attribute_body_deprecated
{
};

struct attribute_body_runtime_visible_annotations
{
    u2 num_annotations;
    struct attribute_body_runtime_visible_annotations_annotation **annotations;
};

struct attribute_body_runtime_visible_annotations_annotation
{
    u2 type_index;
    u2 num_element_value_pairs;
    struct attribute_body_runtime_visible_annotations_annotation_kv **element_value_pairs;
};

struct attribute_body_runtime_visible_annotations_annotation_kv
{
    u2 element_name_index;
    struct attribute_body_runtime_visible_annotations_annotation_kv_v *value;
};

struct attribute_body_runtime_visible_annotations_annotation_kv_v
{
    u1 tag;
    union {
        u2 const_value_index;
        struct attribute_body_runtime_visible_annotations_annotation_kv_v_enum_const_value *enum_const_value;
        u2 class_info_index;
        struct attribute_body_runtime_visible_annotations *annotation_value;
        struct attribute_body_runtime_visible_annotations_annotation_kv_v_array_value *array_value;
    } value;
};

struct attribute_body_runtime_visible_annotations_annotation_kv_v_enum_const_value
{
    u2 type_name_index;
    u2 const_name_index;
};

struct attribute_body_runtime_visible_annotations_annotation_kv_v_array_value
{
    u2 num_values;
    struct attribute_body_runtime_visible_annotations_annotation_kv_v *values;
};

struct attribute_body_runtime_invisible_annotations
{
    u2 num_annotations;
    struct attribute_body_runtime_visible_annotations_annotation **annotations;
};

struct attribute_body_runtime_visible_parameter_annotations
{
    u1 num_parameters;
    struct attribute_body_runtime_visible_parameter_annotations_parameter_annotations **
        parameter_annotations;
};

struct attribute_body_runtime_visible_parameter_annotations_parameter_annotations
{
    u2 num_annotations;
    struct attribute_body_runtime_visible_parameter_annotations **annotation;
};

struct attribute_body_runtime_invisible_parameter_annotations
{
    u1 num_parameters;
    struct attribute_body_runtime_invisible_parameter_annotations_parameter_annotations **
        parameter_annotations;
};

struct attribute_body_runtime_invisible_parameter_annotations_parameter_annotations
{
    u2 num_annotations;
    struct attribute_body_runtime_visible_parameter_annotations **annotation;
};

struct attribute_body_runtime_visible_type_annotations
{
    u2 num_annotations;
    struct attribute_body_runtime_visible_type_annotations_type_annotation **annotations;
};

struct attribute_body_runtime_visible_type_annotations_type_annotation
{
    u1 target_type;
    union {
        type_parameter_target;
        supertype_target;
        type_parameter_bound_target;
        empty_target;
        method_formal_parameter_target;
        throws_target;
        localvar_target;
        catch_target;
        offset_target;
        type_argument_target;
    } target_info;
    struct attribute_body_runtime_visible_type_annotations_type_annotation_type_path *target_path;
    u2 type_index;
    u2 num_element_value_pairs;
    struct attribute_body_runtime_visible_annotations **element_value_pairs;
};

struct attribute_body_runtime_visible_type_annotations_type_annotation_type_path
{
    u1 path_length;
    struct attribute_body_runtime_visible_type_annotations_type_annotation_type_path_path **path;
};

struct attribute_body_runtime_visible_type_annotations_type_annotation_type_path_path
{
    u1 type_path_kind;
    u1 type_argument_index;
};

struct attribute_body_runtime_invisible_type_annotations
{
    u2 num_annotations;
    struct attribute_body_runtime_visible_type_annotations_type_annotation **annotations;
};

struct attribute_body_annotation_default
{
    
};

struct attribute_info
{
    enum attribute_type attr_type;
    u4 attribute_length;
    union {
        struct attribute_body_constant_value *constant_value;
        struct attribute_body_code *code;
        struct attribute_body_stack_map_table *stack_map_table;
        struct attribute_body_exception *exception;
        struct attribute_body_inner_class *inner_class;
        struct attribute_body_enclosing_method *enclosing_method;
        struct attribute_body_synthetic *synthetic;
        struct attribute_body_signature *signature;
        struct attribute_body_source_file *source_file;
        struct attribute_body_source_debug_extension *source_debug_extension;
        struct attribute_body_line_number_table *line_number_table;
        struct attribute_body_local_variable_table *local_variable_table;
        struct attribute_body_local_variable_type_table *local_variable_type_table;
        struct attribute_body_deprecated *deprecated;
        struct attribute_body_runtime_visible_annotations *runtime_visible_annotations;
        struct attribute_body_runtime_invisible_annotations *runtime_invisible_annotations;
        struct attribute_body_runtime_visible_parameter_annotations *runtime_visible_parameter_annotations;
        struct attribute_body_runtime_invisible_parameter_annotations *runtime_invisible_parameter_annotations;
        struct attribute_body_runtime_visible_type_annotations *runtime_visible_type_annotation;
        struct attribute_body_runtime_invisible_type_annotations *runtime_invisble_type_annotation;
        struct attribute_body_annotation_default *annotation_default;
    };
};

struct class_file
{
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    struct constant_pool_entry **constant_pool_entries;
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
