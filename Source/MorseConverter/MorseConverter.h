#pragma once
#include "../CodeConverter/CodeConverter.h"

class FHangulParser;
class FMorseConverter :
  public FCodeConverter
{
  typedef map<int, wchar_t> FromMorseDirctionary;
  typedef map<wchar_t, wstring> ToMorseDictionary;

public:
  FMorseConverter();
  virtual ~FMorseConverter();

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InCode);

private:
  wstring hangulParse(wstring InString);
  wstring hangulStringfy(const wstring& InParsedHangulStr);
  wstring decode_Inner(wstring InCode, const FromMorseDirctionary& InToStringDictionary);
  wstring encode_Inner(wstring InString, const ToMorseDictionary& InToCodeDictionary);
  wstring removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);
  wstring addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);

private:
  FHangulParser* HangulParser;

  FromMorseDirctionary *FromMorseToEngStringDictionary;
  FromMorseDirctionary *FromMorseToKoreanStringDictionary;

  ToMorseDictionary *EngStringToMorseDictionary;
  ToMorseDictionary *KoreanStringToMorseDictionary;
};

