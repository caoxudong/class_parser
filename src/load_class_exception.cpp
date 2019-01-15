#include "load_class_exception.h"

jvm::exception::LoadClassException::LoadClassException(unsigned int error_code) 
  : Exception(error_code)
{
}

jvm::exception::LoadClassException::~LoadClassException()
{
}
