#include "CodeBook.h"
#include <fstream>
#include <iostream>

FCodeBook::FCodeBook()
{
}

FCodeBook::FCodeBook(const string& jsonPath)
{
  std::ifstream input_file(jsonPath);
  std::string rawJson;

  if (input_file.is_open())
  {
    input_file.seekg(0, std::ios::end);
    int size = input_file.tellg();
    rawJson.resize(size);
    input_file.seekg(0, std::ios::beg);
    input_file.read(&rawJson[0], size);
  }

  const auto rawJsonLength = static_cast<int>(rawJson.length());
  constexpr bool shouldUseOldWay = false;
  JSONCPP_STRING err;
  Json::Value root;

  if (shouldUseOldWay) {
    Json::Reader reader;
    reader.parse(rawJson, root);
  }
  else {
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
      &err)) {
      std::cout << "error" << std::endl;
      return;
    }
  }

  FromCode = root["fromCode"];
  ToCode = root["toCode"];
}

FCodeBook::~FCodeBook()
{
}

wstring FCodeBook::Encode(const wchar_t parsedString)
{
  return wstring();
}

wchar_t FCodeBook::Decode(const int wordValue)
{
  return L'\0';
}

wstring FCodeBook::Encode(const int parsedString)
{
    return wstring();
}

int FCodeBook::Decode(const wstring wordValue)
{
    return 0;
}
