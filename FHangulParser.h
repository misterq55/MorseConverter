#pragma once

#include "CodeConverter.h"
#include <map>

using std::map;

class FHangulParser :
    public FCodeConverter
{
  typedef map<int, wstring> KoreanLetterDictionary;

public:
  FHangulParser();
  virtual ~FHangulParser() {}

public:
  virtual wstring ConvertCodeToString(const wstring& InCode);
  virtual wstring ConvertStringToCode(const wstring& InString);

  KoreanLetterDictionary FirstConsonantLetter;
  KoreanLetterDictionary MiddleVowerLetter;
  KoreanLetterDictionary LastConsonantLetter;
};

