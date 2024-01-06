#include "MorseCodeBook.h"
#include <fstream>
#include <iostream>
#include "../../jsoncpp/json/json.h"

FMorseCodeBook::FMorseCodeBook()
{
}

FMorseCodeBook::FMorseCodeBook(const string& jsonPath)
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

  Json::Value fromCode = root["fromCode"];
  Json::Value fromVariableType = fromCode["variableType"];

  const int fromCodeSize = fromCode.size();

  for (int i = 0; i < fromCodeSize; i++)
  {
    Json::Value codeValue = fromCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      int key = codeValue["key"].asInt();
      wchar_t value = codeValue["value"].asCString()[0];
      FromCodeDictionary.emplace(key, value);
    }
  }

  Json::Value toCode = root["toCode"];
  Json::Value toVariableType = fromCode["variableType"];

  const int toCodeSize = toCode.size();

  for (int i = 0; i < toCodeSize; i++)
  {
    Json::Value codeValue = toCode[std::to_string(i)];
    if (!codeValue.empty())
    {
      int key = codeValue["key"].asCString()[0];
      string str = codeValue["value"].asCString();
      wstring value;// = codeValue["value"].asCString();
      value.assign(str.begin(), str.end());
      ToCodeDictionary.emplace(key, value);
    }
  }

  int temp = 0;
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
