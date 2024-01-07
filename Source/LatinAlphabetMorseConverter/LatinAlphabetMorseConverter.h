#pragma once
#include "../MorseConverter/MorseConverter.h"

class FLatinAlphabetMorseConverter :
  public FMorseConverter
{
public:
  FLatinAlphabetMorseConverter();
  virtual ~FLatinAlphabetMorseConverter();

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InCode);
};

