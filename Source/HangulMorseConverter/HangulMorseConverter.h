#pragma once
#include "../MorseConverter/MorseConverter.h"

class FHangulParser;
class FHangulMorseConverter :
  public FMorseConverter
{
public:
  FHangulMorseConverter();
  virtual ~FHangulMorseConverter();

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InCode);

private:
  wstring hangulParse(wstring InString);
  wstring hangulStringfy(const wstring& InParsedHangulStr);

private:
  FHangulParser* HangulParser;
};

