#pragma once

#include "exception.h"

namespace jvm
{
  namespace exception
  {
    class LoadClassException : public Exception
    {
    public:
      LoadClassException(unsigned int error_code);
      ~LoadClassException();
    };
  }
}