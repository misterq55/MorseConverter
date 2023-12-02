#pragma once

#include "../CodeConverter/CodeConverter.h"

class FHangulParser :
    public FCodeConverter
{
  typedef map<int, wstring> KoreanCodeToLetterDictionary;
  typedef map<wstring, int> KoreanLetterToCodeDictionary;

public:
  FHangulParser();
  virtual ~FHangulParser() {}

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InParsedHangulStr);

private:
  void hanguleJamoParse(int ConvertedNum, int Divider, int& OutRange, int& OutRamnant);

private:
  KoreanCodeToLetterDictionary* FirstConsonantCodeToLetter;
  KoreanCodeToLetterDictionary* MiddleVowerCodeToLetter;
  KoreanCodeToLetterDictionary* LastConsonantCodeToLetter;

  KoreanCodeToLetterDictionary* JaeumOnlyCodeToLetter;

  KoreanLetterToCodeDictionary* FirstConsonantLetterToCode;
  KoreanLetterToCodeDictionary* MiddleVowerLetterToCode;
  KoreanLetterToCodeDictionary* LastConsonantLetterToCode;

  KoreanLetterToCodeDictionary* JaeumOnlyLetterCode;
  KoreanLetterToCodeDictionary* MoeumOnlyLetterCode;
};

