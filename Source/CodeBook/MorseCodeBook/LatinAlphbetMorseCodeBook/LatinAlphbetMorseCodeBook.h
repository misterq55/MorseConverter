#pragma once

#include "../MorseCodeBook.h"

class FLatinAlphbetMorseCodeBook : public FMorseCodeBook
{
public:
  FLatinAlphbetMorseCodeBook();
  FLatinAlphbetMorseCodeBook(const string& jsonPath);
  virtual ~FLatinAlphbetMorseCodeBook();
};

