#include "exception.h"

using namespace jvm::exception;


Exception::Exception(unsigned int error_code) : error_code(error_code)
{
}


Exception::~Exception()
{
}


unsigned int Exception::get_error_code()
{
  return error_code;
}
