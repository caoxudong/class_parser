#include <iostream>

#include "class_file_types.h"

using namespace std;

namespace jvm
{
    // reference:    https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html
    namespace class_file_types
    {
        void printClassFile(ClassFile *pClassFile)
        {
            std::cout << "magic number: " << std::hex << pClassFile->magic << std::endl;
            std::cout << std::dec;
            std::cout << "major version: " << pClassFile->major_vertion << std::endl;
            std::cout << "minor version: " << pClassFile->minor_vertion << std::endl;
            std::cout << "constant pool count: " << pClassFile->constant_pool_count << std::endl;
        }
    }
}