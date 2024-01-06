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
  const int fromCodeSize = FromCode.size();
  const int toCodeSize = ToCode.size();

  for (int i = 0; i < fromCodeSize; i++)
  {
    Json::Value codeValue = FromCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      int key = codeValue["key"].asInt();
      wchar_t value = codeValue["value"].asCString()[0];
      FromCodeDictionary.emplace(key, value);
    }
  }

  for (int i = 0; i < toCodeSize; i++)
  {
    Json::Value codeValue = ToCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      int key = codeValue["key"].asCString()[0];
      string str = codeValue["value"].asCString();
      wstring value;
      value.assign(str.begin(), str.end());
      ToCodeDictionary.emplace(key, value);
    }
  }
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
