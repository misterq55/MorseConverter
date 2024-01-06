#pragma once
#include "../CodeConverter/CodeConverter.h"

class FLatinAlphabetMorseConverter :
  public FCodeConverter
{
  typedef map<int, wchar_t> FromMorseDirctionary;
  typedef map<wchar_t, wstring> ToMorseDictionary;

public:
  FLatinAlphabetMorseConverter();
  virtual ~FLatinAlphabetMorseConverter();

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InCode);

private:
  wstring decode_Inner(wstring InCode, const FromMorseDirctionary& InToStringDictionary);
  wstring encode_Inner(wstring InString, const ToMorseDictionary& InToCodeDictionary);
  wstring removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);
  wstring addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);

private:
  FromMorseDirctionary *FromMorseToEngStringDictionary;
  ToMorseDictionary *EngStringToMorseDictionary;
};

