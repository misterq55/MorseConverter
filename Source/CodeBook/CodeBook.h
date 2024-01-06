#pragma once

#include <string>
#include <map>

using std::string;
using std::map;
using std::wstring;

class FCodeBook
{
public:
  FCodeBook();
  FCodeBook(const string& jsonPath); 
  virtual ~FCodeBook();

public:
  virtual wstring Encode(const wchar_t parsedString);
  virtual wchar_t Decode(const int wordValue);
};

