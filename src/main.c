#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>

#include "class_parser.h"

struct class_file *parse(u1 *content);
void usage(void);
unsigned long get_file_size(const char *);
void read_file_content(int input_file_fd, unsigned char *target_buffer, int buffer_offset);
void print_class_file(struct class_file *p_class_file);

int is_big_endian()
{
    int a = 0xFEFF;
    if ((a & 0xFF) == 0xFF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_chars(u2 length, u1 *chars)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", chars[i]);
    }
}

void print_access_flags(u2 access_flags)
{
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_ABSTRACT)
    {
        printf("abstract, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_ANNOTATION)
    {
        printf("annotation, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_ENUM)
    {
        printf("enum, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_FINAL)
    {
        printf("final, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_INTERFACE)
    {
        printf("interface, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_PUBLIC)
    {
        printf("public, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_SUPER)
    {
        printf("super, ");
    }
    if (access_flags & CLASS_ACCESS_FLAGS_ACC_SYNTHETIC)
    {
        printf("synthetic, ");
    }
}

void print_class_name(struct constant_pool_entry **cp_entries, u2 cp_class_index)
{
    struct constant_pool_entry *p_cpe_class = cp_entries[cp_class_index];
    u2 class_name_cp_index = ((struct constant_pool_entry_class *)p_cpe_class)->name_index;
    struct constant_pool_entry *p_cpe_utf8 = cp_entries[class_name_cp_index];
    u2 class_name_bytes_length = ((struct constant_pool_entry_utf8 *)p_cpe_utf8)->length;
    u1 *class_name_bytes = ((struct constant_pool_entry_utf8 *)p_cpe_utf8)->bytes;
    printf("class_name_bytes_length=%d, ", class_name_bytes_length);
    print_chars(class_name_bytes_length, class_name_bytes);
}

void print_utf8(struct constant_pool_entry **cp_entries, u2 cp_index)
{
    struct constant_pool_entry *p_cp_entry = cp_entries[cp_index];
    struct constant_pool_entry_utf8 *p_cpe_utf8 = (struct constant_pool_entry_utf8 *)p_cp_entry;
    print_chars(p_cpe_utf8->length, p_cpe_utf8->bytes);
}

void print_attribute(struct attribute_info *p_attr_info, struct constant_pool_entry **p_entries)
{
    printf("\tattr name: ");
    print_utf8(p_entries, p_attr_info->attribute_name_index);
}

void print_field(struct field_info *p_field_info, struct constant_pool_entry **p_entries)
{
    printf("\taccess_flags: ");
    print_access_flags(p_field_info->access_flags);
    printf("\n");
    printf("\tname: ");
    print_utf8(p_entries, p_field_info->name_index);
    printf("\n");
    printf("\tdescriptor: ");
    print_utf8(p_entries, p_field_info->descriptor_index);
    printf("\n");
    printf("\tattributes count: %u", p_field_info->attributes_count);
    if (p_field_info->attributes_count > 1)
    {
        struct attribute_info **p_attributes = p_field_info->attributes;
        for (u2 i = 0; i < p_field_info->attributes_count; i++)
        {
            print_attribute(p_attributes[i], p_entries);
            printf("\n");
        }
    }
}

void print_method(struct method_info *p_method_info, struct constant_pool_entry **p_entries)
{
    printf("\taccess_flags: ");
    print_access_flags(p_method_info->access_flags);
    printf("\n");
    printf("\tname: ");
    print_utf8(p_entries, p_method_info->name_index);
    printf("\n");
    printf("\tdescriptor: ");
    print_utf8(p_entries, p_method_info->descriptor_index);
    printf("\n");
    printf("\tattributes count: %u", p_method_info->attributes_count);
    if (p_method_info->attributes_count > 1)
    {
        struct attribute_info **p_attributes = p_method_info->attributes;
        for (u2 i = 0; i < p_method_info->attributes_count; i++)
        {
            print_attribute(p_attributes[i], p_entries);
            printf("\n");
        }
    }
}



int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usage();
        exit(1);
    }

    char *class_file_path = argv[1];

    struct stat stat_buff;
    if (stat(class_file_path, &stat_buff) < 0)
    {
        perror("invalid class file, cannot access target file");
        exit(1);
    }

    if (!S_ISREG(stat_buff.st_mode))
    {
        perror("only load regular file");
        exit(1);
    }

    FILE *f = fopen(class_file_path, "rb");
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    if (file_size > INT_MAX)
    {
        perror("invalid class file, file too large");
        exit(1);
    }
    fseek(f, 0, SEEK_SET); //same as rewind(f);
    u1 *content = (u1 *)malloc(file_size + 1);
    fread(content, file_size, 1, f);

    struct class_file *p_class_file = parse(content);
    free(content);
    fclose(f);

    print_class_file(p_class_file);
}

void usage(void)
{
    perror("Please specify the class file path");
}

void print_class_file(struct class_file *p_class_file)
{
    struct constant_pool_entry **cp_entries = p_class_file->constant_pool_entries;
    printf("begin to print class file content<<<<<<<<\n");
    printf("magic number: %x\n", p_class_file->magic);
    printf("minor version: %d\n", p_class_file->minor_version);
    printf("major version: %d\n", p_class_file->major_version);
    printf("constant pool count: %d\n", p_class_file->constant_pool_count);
    if (p_class_file->constant_pool_count > 1)
    {
        for (int i = 1; i < p_class_file->constant_pool_count; i++)
        {
            struct constant_pool_entry *p_cp_entry = p_class_file->constant_pool_entries[i];
            if (!p_cp_entry)
            {
                continue;
            }
            u2 tag = p_cp_entry->tag;
            switch (tag)
            {
            case CONSTANT_POOL_TAGS_CLASS:
            {
                printf("\tindex=%d, tag = class, name_index=%d\n", i, ((struct constant_pool_entry_class *)p_cp_entry)->name_index);
                break;
            }
            case CONSTANT_POOL_TAGS_FIELD_REF:
            {
                printf("\tindex=%d, tag = field, class_index=%d, name_and_type_index=%d\n", i, ((struct constant_pool_entry_field_ref *)p_cp_entry)->class_index, ((struct constant_pool_entry_field_ref *)p_cp_entry)->name_and_type_index);
                break;
            }
            case CONSTANT_POOL_TAGS_METHOD_REF:
            {
                printf("\tindex=%d, tag = method, class_index=%d, name_and_type_index=%d\n", i, ((struct constant_pool_entry_method_ref *)p_cp_entry)->class_index, ((struct constant_pool_entry_method_ref *)p_cp_entry)->name_and_type_index);
                break;
            }
            case CONSTANT_POOL_TAGS_INTERFACE_METHOD_REF:
            {
                printf("\tindex=%d, tag = interface method, class_index=%d, name_and_type_index=%d\n", i, ((struct constant_pool_entry_interface_method_ref *)p_cp_entry)->class_index, ((struct constant_pool_entry_interface_method_ref *)p_cp_entry)->name_and_type_index);
                break;
            }
            case CONSTANT_POOL_TAGS_UTF8:
            {
                printf("\tindex=%d, tag = utf8, length=%d, ", i, ((struct constant_pool_entry_utf8 *)p_cp_entry)->length);
                print_chars(((struct constant_pool_entry_utf8 *)p_cp_entry)->length, ((struct constant_pool_entry_utf8 *)p_cp_entry)->bytes);
                printf("\n");
                break;
            }
            case CONSTANT_POOL_TAGS_STRING:
            {
                printf("\tindex=%d, tag = string, string_index=%d\n", i, ((struct constant_pool_entry_string *)p_cp_entry)->string_index);
                break;
            }
            case CONSTANT_POOL_TAGS_INTEGER:
            {
                printf("\tindex=%d, tag = integer, bytes=%d\n", i, ((struct constant_pool_entry_integer *)p_cp_entry)->bytes);
                break;
            }
            case CONSTANT_POOL_TAGS_FLOAT:
            {
                printf("\tindex=%d, tag = float, bytes=%f\n", i, (double)((struct constant_pool_entry_float *)p_cp_entry)->bytes);
                break;
            }
            case CONSTANT_POOL_TAGS_LONG:
            {
                printf("\tindex=%d, tag = long, bytes=%ld\n", i, ((long)((struct constant_pool_entry_long *)p_cp_entry)->high_bytes) << 32 | ((struct constant_pool_entry_long *)p_cp_entry)->low_bytes);
                break;
            }
            case CONSTANT_POOL_TAGS_DOUBLE:
            {
                printf("\tindex=%d, tag = long, bytes=%f\n", i, (double)(((long)((struct constant_pool_entry_double *)p_cp_entry)->high_bytes) << 32 | ((struct constant_pool_entry_double *)p_cp_entry)->low_bytes));
                break;
            }
            }
        }
    }

    printf("access flags: ");
    u2 access_flags = p_class_file->access_flags;
    print_access_flags(access_flags);
    printf("\n");

    printf("this class: ");
    u2 this_class_cp_index = p_class_file->this_class;
    print_class_name(cp_entries, this_class_cp_index);
    printf("\n");

    printf("super class: ");
    u2 super_class_cp_index = p_class_file->super_class;
    print_class_name(cp_entries, super_class_cp_index);
    printf("\n");

    printf("interfaces count: %u\n", p_class_file->interfaces_count);
    if (p_class_file->interfaces_count > 0)
    {
        u2 *interfaces = p_class_file->interfaces;
        for (u2 i = 0; i < p_class_file->interfaces_count; i++)
        {
            u2 interface_cp_index = interfaces[i];
            printf("\tcp_index=%u, ", interface_cp_index);
            print_class_name(cp_entries, interface_cp_index);
            printf("\n");
        }
    }

    printf("fields count: %u\n", p_class_file->fields_count);
    if (p_class_file->fields_count > 0)
    {
        struct field_info **field_infos = p_class_file->fields;
        for (u2 i = 0; i < p_class_file->fields_count; i++)
        {
            struct field_info *p_field_info = field_infos[i];
            print_field(p_field_info, p_class_file->constant_pool_entries);
            printf("\n");
        }
    }

    printf("methods count: %u\n", p_class_file->methods_count);
    if (p_class_file->methods_count > 0)
    {
        struct method_info **method_infos = p_class_file->methods;
        for (u2 i=0;i<p_class_file->methods_count;i++)
        {
            struct method_info *p_method_info = method_infos[i];
            print_method(p_method_info, p_class_file->constant_pool_entries);
        }
    }

    printf(">>>>>>>>end printing class file");
}