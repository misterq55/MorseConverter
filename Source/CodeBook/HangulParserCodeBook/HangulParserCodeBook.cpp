#define _CRT_SECURE_NO_WARNINGS

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
      wstring value;
      wchar_t strUnicode[256] = L"";//{ 0, };
      char strMultibyte[256] = { 0, };

      strcpy(strMultibyte, str.c_str());
      const int len = strlen(strMultibyte);
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);

      value = wstring(strUnicode);
      // std::wcout << value << std::endl;
      // std::cout << str << std::endl;
      FromCodeDictionary.emplace(key, value);
    }
  }

  for (int i = 0; i < toCodeSize; i++)
  {
    Json::Value codeValue = ToCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      string str = codeValue["key"].asCString();
      wstring key;
      int value = codeValue["value"].asInt();
      wchar_t strUnicode[256] = L"";//{ 0, };
      char strMultibyte[256] = { 0, };

      strcpy(strMultibyte, str.c_str());
      const int len = strlen(strMultibyte);
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);

      key = wstring(strUnicode);    
      // std::wcout << key << std::endl;
      ToCodeDictionary.emplace(key, value);
    }
  }

  int temp = 0;
}

FHangulParserCodeBook::~FHangulParserCodeBook()
{
}

wstring FHangulParserCodeBook::Encode(const int parsedString)
{
  wstring encodeResult = L"";

  if (FromCodeDictionary.find(parsedString) != FromCodeDictionary.end())
  {
    encodeResult = FromCodeDictionary.at(parsedString);
  }

  return encodeResult;
}

int FHangulParserCodeBook::Decode(const wstring wordValue)
{
  int decodedResult = 0;

  if (ToCodeDictionary.find(wordValue) != ToCodeDictionary.end())
  {
    decodedResult = ToCodeDictionary.at(wordValue);
  }

  return decodedResult;
}