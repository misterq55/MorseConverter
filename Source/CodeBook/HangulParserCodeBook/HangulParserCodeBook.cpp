#include "HangulParserCodeBook.h"
#include <fstream>
#include <iostream>

FHangulParserCodeBook::FHangulParserCodeBook()
  : FCodeBook()
{
}

FHangulParserCodeBook::FHangulParserCodeBook(const string& jsonPath)
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
      string str = codeValue["value"].asCString();
      wstring value = wstring().assign(str.begin(), str.end());
      FromCodeDictionary.emplace(key, value);
    }
  }

  for (int i = 0; i < toCodeSize; i++)
  {
    Json::Value codeValue = ToCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      string str = codeValue["key"].asCString();
      wstring key = wstring().assign(str.begin(), str.end());
      int value = codeValue["value"].asInt();
      ToCodeDictionary.emplace(key, value);
    }
  }

  int temp = 0;
}

FHangulParserCodeBook::~FHangulParserCodeBook()
{
}

wstring FHangulParserCodeBook::Encode(const wchar_t parsedString)
{
  wstring encodeResult = L"";

  return encodeResult;
}

wchar_t FHangulParserCodeBook::Decode(const int wordValue)
{
  wchar_t decodedResult = L' ';

  return decodedResult;
}
