#pragma once

#include "../CodeBook.h"

class FHangulParserCodeBook : public FCodeBook
{
public:
  FHangulParserCodeBook();
  FHangulParserCodeBook(const string& jsonPath);
  virtual ~FHangulParserCodeBook();

public:
  virtual wstring Encode(const wchar_t parsedString) override;
  virtual wchar_t Decode(const int wordValue) override;

private:
  map<int, wstring> FromCodeDictionary;
  map<wstring, int> ToCodeDictionary;
};

