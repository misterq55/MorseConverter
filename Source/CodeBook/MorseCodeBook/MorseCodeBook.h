#pragma once

#include "../CodeBook.h"

class FMorseCodeBook : public FCodeBook
{
public:
  FMorseCodeBook();
  FMorseCodeBook(const string& jsonPath);
  virtual ~FMorseCodeBook();

public:
  virtual wstring Encode(const wchar_t parsedString) override;
  virtual wchar_t Decode(const int wordValue) override;

private:
  virtual wstring Encode(const int parsedString) override { return wstring(); };
  virtual int Decode(const wstring wordValue) override { return 0; };

protected:
  map<int, wchar_t> FromCodeDictionary;
  map<wchar_t, wstring> ToCodeDictionary;
};

