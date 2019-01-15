#pragma once

namespace jvm
{
  namespace exception
  {
    class Exception
    {
    public:
      Exception(unsigned int error_code);
      virtual ~Exception();
      unsigned int error_code;
      unsigned int get_error_code();
    };

  }
}