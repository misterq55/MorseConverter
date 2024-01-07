#pragma once
#include "../CodeConverter/CodeConverter.h"

class FCodeBook;
class FMorseConverter :
  public FCodeConverter
{

public:
  FMorseConverter();
  virtual ~FMorseConverter();

public:
  virtual void Initilize();

protected:
  wstring decode_Inner(wstring InCode, FCodeBook* InCodeBook);
  wstring encode_Inner(wstring InString, FCodeBook* InCodeBook);
  wstring removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);
  wstring addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);

protected:
  FCodeBook* MorseCodeBook = nullptr;
};

