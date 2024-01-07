#pragma once

#include "../MorseCodeBook.h"

class FHangulMorseCodeBook : public FMorseCodeBook
{
public:
  FHangulMorseCodeBook();
  FHangulMorseCodeBook(const string& jsonPath);
  virtual ~FHangulMorseCodeBook();
};

