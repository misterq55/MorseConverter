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
      
      #ifdef _WIN32
      strcpy_s(strMultibyte, 256, str.c_str());
      int nLen = MultiByteToWideChar(CP_ACP, 0, strMultibyte, strlen(strMultibyte), NULL, NULL);
      MultiByteToWideChar(CP_ACP, 0, strMultibyte, strlen(strMultibyte), strUnicode, nLen);
      #elif __linux__
      strcpy(strMultibyte, str.c_str());
      const int len = strlen(strMultibyte);
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);
      #endif

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

      #ifdef _WIN32
      strcpy_s(strMultibyte, 256, str.c_str());
      int nLen = MultiByteToWideChar(CP_ACP, 0, strMultibyte, strlen(strMultibyte), NULL, NULL);
      MultiByteToWideChar(CP_ACP, 0, strMultibyte, strlen(strMultibyte), strUnicode, nLen);
      #elif __linux__
      strcpy(strMultibyte, str.c_str());
      const int len = strlen(strMultibyte);
      setlocale(LC_ALL, "Korean");//로케일 설정
      std::mbstowcs(strUnicode, strMultibyte, 256);
      #endif

      key = wstring(strUnicode);    
      // std::wcout << key << std::endl;
      ToCodeDictionary.emplace(key, value);
    }
  }
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
