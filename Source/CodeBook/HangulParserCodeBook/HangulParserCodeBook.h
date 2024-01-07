#pragma once

#include "../CodeBook.h"

class FHangulParserCodeBook : public FCodeBook
{
public:
  FHangulParserCodeBook();
  FHangulParserCodeBook(const string& jsonPath);
  virtual ~FHangulParserCodeBook();

public:
  virtual wstring Encode(const int parsedString) override;
  virtual int Decode(const wstring wordValue) override;

private:
  virtual wstring Encode(const wchar_t parsedString) override { return wstring(); }
  virtual wchar_t Decode(const int wordValue) override { return L'\0'; }

private:
  map<int, wstring> FromCodeDictionary;
  map<wstring, int> ToCodeDictionary;
};

