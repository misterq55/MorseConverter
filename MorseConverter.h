#pragma once
#include "CodeConverter.h"
#include <map>

using std::map;

class FMorseConverter :
  public FCodeConverter
{
  typedef map<int, wstring> KoreanCodeToLetterDictionary;
  typedef map<wstring, int> KoreanLetterToCodeDictionary;
  typedef map<int, wchar_t> FromMorseDirctionary;
  typedef map<wchar_t, wstring> ToMorseDictionary;

public:
  FMorseConverter();
  virtual ~FMorseConverter();

public:
  virtual wstring ConvertCodeToString(const wstring& InCode);
  virtual wstring ConvertStringToCode(const wstring& InString);

private:
  wstring HangulParser(wstring InString);
  wstring HangulStringfy(wstring InParsedHangulStr);
  wstring InnerConvertCodeToString(wstring InCode, const FromMorseDirctionary& InToStringDictionary);
  wstring InnerConvertStringToCode(wstring InString, const ToMorseDictionary& InToCodeDictionary);
  wstring BlankConvertCodeToString(wstring InCode, const wstring& LetterInterval, const wstring& WordInterval);
  wstring BlankConvertStringToCode(wstring InString, const wstring& LetterInterval, const wstring& WordInterval);
  

private:
  KoreanCodeToLetterDictionary FirstConsonantCodeToLetter;
  KoreanCodeToLetterDictionary MiddleVowerCodeToLetter;
  KoreanCodeToLetterDictionary LastConsonantCodeToLetter;

  KoreanLetterToCodeDictionary FirstConsonantLetterToCode;
  KoreanLetterToCodeDictionary MiddleVowerLetterToCode;
  KoreanLetterToCodeDictionary LastConsonantLetterToCode;

  FromMorseDirctionary FromMorseToEngStringDictionary;
  FromMorseDirctionary FromMorseToKoreanStringDictionary;
  ToMorseDictionary EngStringToMorseDictionary;
  ToMorseDictionary KoreanStringToMorseDictionary;
};

