#define _CRT_SECURE_NO_WARNINGS

#include "MorseCodeBook.h"
#include <fstream>
#include <iostream>

FMorseCodeBook::FMorseCodeBook()
  : FCodeBook()
{
}

FMorseCodeBook::FMorseCodeBook(const string& jsonPath)
  : FCodeBook(jsonPath)
{
  
}

FMorseCodeBook::~FMorseCodeBook()
{
}

wstring FMorseCodeBook::Encode(const wchar_t parsedString)
{
  wstring encodeResult = L"";

  if (ToCodeDictionary.find(parsedString) != ToCodeDictionary.end())
  {
    encodeResult = ToCodeDictionary.at(parsedString);
  }

  return encodeResult;
}

wchar_t FMorseCodeBook::Decode(const int wordValue)
{
  wchar_t decodedResult = L' ';

  if (FromCodeDictionary.find(wordValue) != FromCodeDictionary.end())
  {
    decodedResult = FromCodeDictionary.at(wordValue);
  }

  return decodedResult;
}
