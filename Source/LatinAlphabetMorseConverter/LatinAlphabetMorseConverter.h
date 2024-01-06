#pragma once
#include "../CodeConverter/CodeConverter.h"

class FCodeBook;
class FLatinAlphabetMorseConverter :
  public FCodeConverter
{
public:
  FLatinAlphabetMorseConverter();
  virtual ~FLatinAlphabetMorseConverter();

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InCode);

private:
  wstring decode_Inner(wstring InCode);
  wstring encode_Inner(wstring InString);

  wstring removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);
  wstring addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);

private:

  FCodeBook* LatinAlphbetMorseCodeBook = nullptr;;
};

