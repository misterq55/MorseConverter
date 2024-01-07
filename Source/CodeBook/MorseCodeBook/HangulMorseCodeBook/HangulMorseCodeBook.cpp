#define _CRT_SECURE_NO_WARNINGS

#include "HangulMorseCodeBook.h"
#include <fstream>
#include <iostream>

FHangulMorseCodeBook::FHangulMorseCodeBook()
  : FMorseCodeBook()
{
}

FHangulMorseCodeBook::FHangulMorseCodeBook(const string& jsonPath)
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
      string valueCStr = codeValue["value"].asCString();

      wchar_t strUnicode[256] = L"";//{ 0, };
      char strMultibyte[256] = { 0, };

      strcpy(strMultibyte, valueCStr.c_str());
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);

      wstring valueWStr(strUnicode);
      wchar_t value = valueWStr[0];

      FromCodeDictionary.emplace(key, value);
    }
  }

  for (int i = 0; i < toCodeSize; i++)
  {
    Json::Value codeValue = ToCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      string keyCStr = codeValue["key"].asCString();

      wchar_t strUnicode[256] = L"";//{ 0, };
      char strMultibyte[256] = { 0, };

      strcpy(strMultibyte, keyCStr.c_str());
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);

      wstring keyStr = wstring(strUnicode);
      int key = keyStr[0];

      string valueStr = codeValue["value"].asCString();

      wmemset(strUnicode, L' ', 256);
      memset(strMultibyte, 0, 256);

      strcpy(strMultibyte, valueStr.c_str());
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);

      wstring value(strUnicode);
      ToCodeDictionary.emplace(key, value);
    }
  }
}

FHangulMorseCodeBook::~FHangulMorseCodeBook()
{
}