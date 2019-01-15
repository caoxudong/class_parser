#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "class_parser.h"
#include "class_file_types.h"
#include "exception.h"

using namespace std;
using namespace jvm::class_loader;
using namespace jvm::exception;
using namespace jvm::class_file_types;

void usage(void);
void usage(int);
unsigned long get_file_size(const char *);
void read_file_content(int input_file_fd, unsigned char* target_buffer, int buffer_offset);
void print_class_file_info(ClassFile*);

int main(int argc, char* argv[])
{
    char *class_file_path = argv[1];
    std::ifstream class_file_stream(class_file_path, std::ifstream::binary);
    if(!class_file_stream.is_open())
    {   
        std::cerr << "open class file failed:" << std::endl;
        exit(1);
    }
    
    // compute file size
    streampos begin_pos = class_file_stream.tellg();
    class_file_stream.seekg(0, ios::end);
    streampos end_pos = class_file_stream.tellg();
    int class_file_size = end_pos - begin_pos;
    class_file_stream.seekg (0, ios::beg);

    // create buffer
    char* buffer = new char[class_file_size];

    // read file content
    class_file_stream.read(buffer, class_file_size);

    // close file
    class_file_stream.close();

    // parse class file
    ClassPaser class_parser;
    ClassFile *p_class_file = NULL;
    try 
    {
        p_class_file = class_parser.parse(buffer);
    }
    catch (Exception& exception) 
    {
        cerr << "Parsing class file failed, error code = " << exception.get_error_code() << endl;
        exit(1);
    }

    // 打印class文件信息
    print_class_file_info(p_class_file);

    delete[] buffer;
    delete p_class_file;
}

void usage(void)
{
    std::cerr << "Please specify the class file path." << std::endl;
    exit(1);
}

void usage(int errorCode)
{
    std::cerr << "error code:" << errorCode << std::endl;
    exit(1);
}

void print_class_file_info(ClassFile* p_class_file)
{
    jvm::class_file_types::printClassFile(p_class_file);
}