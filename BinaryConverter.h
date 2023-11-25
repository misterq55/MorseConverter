#pragma once
#include "CodeConverter.h"
class FBinaryConverter :
    public FCodeConverter
{
  virtual wstring ConvertCodeToString(const wstring& InCode);
  virtual wstring ConvertStringToCode(const wstring& InString);
};

