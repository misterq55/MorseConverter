#define _CRT_SECURE_NO_WARNINGS

#include "LatinAlphbetMorseCodeBook.h"
#include <fstream>
#include <iostream>

FLatinAlphbetMorseCodeBook::FLatinAlphbetMorseCodeBook()
  : FMorseCodeBook()
{
}

FLatinAlphbetMorseCodeBook::FLatinAlphbetMorseCodeBook(const string& jsonPath)
  : FMorseCodeBook(jsonPath)
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

FLatinAlphbetMorseCodeBook::~FLatinAlphbetMorseCodeBook()
{
}