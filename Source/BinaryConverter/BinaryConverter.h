#pragma once
#include "../CodeConverter/CodeConverter.h"

class FBinaryConverter :
    public FCodeConverter
{
public:
  FBinaryConverter() {}
  virtual ~FBinaryConverter() {}

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InCode);

private:
  static const int WORD_SIZE = 8;
};

