#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>

#include "class_parser.h"

void usage(void);
unsigned long get_file_size(const char *);
void read_file_content(int input_file_fd, unsigned char *target_buffer, int buffer_offset);

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

    parse(content);

    free(content);
    fclose(f);
}

void usage(void)
{
    perror("Please specify the class file path");
}