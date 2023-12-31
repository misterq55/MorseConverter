// MorseConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
// #include "FHangulParser.h"
#include "MorseConverter/MorseConverter.h"
// #include "BinaryConverter.h"
#include "jsoncpp/json/json.h"

using namespace std;

void makeEnglishMorseCodeBook() {

  Json::Value root;
  Json::Value fromCode;
  Json::Value keyValueType;
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "WChar";
  fromCode["variableType"] = keyValueType;
  fromCode["7"] = L'A';
  fromCode["41"] = L'B';
  fromCode["50"] = L'C';
  fromCode["14"] = L'D';
  fromCode["1"] = L'E';
  fromCode["49"] = L'F';
  fromCode["17"] = L'G';
  fromCode["40"] = L'H';
  fromCode["4"] = L'I';
  fromCode["79"] = L'J';
  fromCode["23"] = L'K';
  fromCode["43"] = L'L';
  fromCode["8"] = L'M';
  fromCode["5"] = L'N';
  fromCode["26"] = L'O';
  fromCode["52"] = L'P';
  fromCode["71"] = L'Q';
  fromCode["16"] = L'R';
  fromCode["13"] = L'S';
  fromCode["2"] = L'T';
  fromCode["22"] = L'U';
  fromCode["67"] = L'V';
  fromCode["25"] = L'W';
  fromCode["68"] = L'X';
  fromCode["77"] = L'Y';
  fromCode["44"] = L'Z';
  fromCode["241"] = L'1';
  fromCode["238"] = L'2';
  fromCode["229"] = L'3';
  fromCode["202"] = L'4';
  fromCode["121"] = L'5';
  fromCode["122"] = L'6';
  fromCode["125"] = L'7';
  fromCode["134"] = L'8';
  fromCode["161"] = L'9';
  fromCode["242"] = L'0';
  fromCode["355"] = L'-'; 
  fromCode["637"] = L'.';
  fromCode["692"] = L',';
  fromCode["158"] = L'(';
  fromCode["644"] = L')';
  fromCode["400"] = L'?';
  fromCode["149"] = L'/';

  Json::Value toCode;

  keyValueType["keyVariableType"] = "String";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;
  toCode["A"] = ".-";
  toCode["B"] = "-...";
  toCode["C"] = "-.-.";
  toCode["D"] = "-..";
  toCode["E"] = ".";
  toCode["F"] = "..-.";
  toCode["G"] = "--.";
  toCode["H"] = "....";
  toCode["I"] = ".---";
  toCode["J"] = ".---";
  toCode["K"] = "-.-";
  toCode["L"] = ".-..";
  toCode["M"] = "--";
  toCode["N"] = "-.";
  toCode["O"] = "---";
  toCode["P"] = ".--.";
  toCode["Q"] = "--.-";
  toCode["R"] = ".-.";
  toCode["S"] = "...";
  toCode["T"] = "-";
  toCode["U"] = "..-";
  toCode["V"] = "...-";
  toCode["W"] = ".--";
  toCode["X"] = "-..-";
  toCode["Y"] = "-.--";
  toCode["Z"] = "--..";
  toCode["1"] = ".----";
  toCode["2"] = "..---";
  toCode["3"] = "...--";
  toCode["4"] = "....-";
  toCode["5"] = ".....";
  toCode["6"] = "-....";
  toCode["7"] = "--...";
  toCode["8"] = "---..";
  toCode["9"] = "----.";
  toCode["0"] = "-----";
  toCode["-"] = "-....-";
  toCode["."] = ".-.-.-";
  toCode[","] = "--..--";
  toCode["("] = "-.--.";
  toCode[")"] = "-.--.-";
  toCode["?"] = "..--..";
  toCode["/"] = "-..-.";
  toCode[" "] = "/";

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("MorseEnglishCodeBook.json");
  writer->write(root, &output_file);
}

void makeKoreanMorseCodeBook() 
{
  Json::Value root;
  Json::Value fromCode;
  Json::Value keyValueType;
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "WChar";
  fromCode["variableType"] = keyValueType;
  fromCode["43"] = "ぁ";
  fromCode["49"] = "い";
  fromCode["41"] = "ぇ";
  fromCode["67"] = "ぉ";
  fromCode["8"] = "け";
  fromCode["25"] = "げ";
  fromCode["17"] = "さ";
  fromCode["23"] = "し";
  fromCode["52"] = "じ";
  fromCode["50"] = "ず";
  fromCode["68"] = "せ";
  fromCode["44"] = "ぜ";
  fromCode["26"] = "そ";
  fromCode["79"] = "ぞ";

  /*fromCode["26"] = L'O';
  fromCode["52"] = L'P';
  fromCode["71"] = L'Q';
  fromCode["16"] = L'R';
  fromCode["13"] = L'S';
  fromCode["2"] = L'T';
  fromCode["22"] = L'U';
  fromCode["67"] = L'V';
  fromCode["25"] = L'W';
  fromCode["68"] = L'X';
  fromCode["77"] = L'Y';
  fromCode["44"] = L'Z';
  fromCode["241"] = L'1';
  fromCode["238"] = L'2';
  fromCode["229"] = L'3';
  fromCode["202"] = L'4';
  fromCode["121"] = L'5';
  fromCode["122"] = L'6';
  fromCode["125"] = L'7';
  fromCode["134"] = L'8';
  fromCode["161"] = L'9';
  fromCode["242"] = L'0';
  fromCode["355"] = L'-';
  fromCode["637"] = L'.';
  fromCode["692"] = L',';
  fromCode["158"] = L'(';
  fromCode["644"] = L')';
  fromCode["400"] = L'?';
  fromCode["149"] = L'/';*/

  Json::Value toCode;

  keyValueType["keyVariableType"] = "String";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;
  toCode["A"] = ".-";
  toCode["B"] = "-...";
  toCode["C"] = "-.-.";
  toCode["D"] = "-..";
  toCode["E"] = ".";
  toCode["F"] = "..-.";
  toCode["G"] = "--.";
  toCode["H"] = "....";
  toCode["I"] = ".---";
  toCode["J"] = ".---";
  toCode["K"] = "-.-";
  toCode["L"] = ".-..";
  toCode["M"] = "--";
  toCode["N"] = "-.";
  toCode["O"] = "---";
  toCode["P"] = ".--.";
  toCode["Q"] = "--.-";
  toCode["R"] = ".-.";
  toCode["S"] = "...";
  toCode["T"] = "-";
  toCode["U"] = "..-";
  toCode["V"] = "...-";
  toCode["W"] = ".--";
  toCode["X"] = "-..-";
  toCode["Y"] = "-.--";
  toCode["Z"] = "--..";
  toCode["1"] = ".----";
  toCode["2"] = "..---";
  toCode["3"] = "...--";
  toCode["4"] = "....-";
  toCode["5"] = ".....";
  toCode["6"] = "-....";
  toCode["7"] = "--...";
  toCode["8"] = "---..";
  toCode["9"] = "----.";
  toCode["0"] = "-----";
  toCode["-"] = "-....-";
  toCode["."] = ".-.-.-";
  toCode[","] = "--..--";
  toCode["("] = "-.--.";
  toCode[")"] = "-.--.-";
  toCode["?"] = "..--..";
  toCode["/"] = "-..-.";
  toCode[" "] = "/";

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("MorseKoreanCodeBook.json");
  writer->write(root, &output_file);
}

void read_json()
{
  std::ifstream input_file("D:/Project/MorseConverter/test.json");
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
  const int size = root["friends"].size();
  cout << root["friends"][0]["name"] << endl;
  // cout << root["friends"]["age"] << endl;
  //const std::string name = root["name"].asString();
  //const int age = root["age"].asInt();

  //std::cout << name << std::endl;
  //std::cout << age << std::endl;
}

int main()
{
  //wcin.imbue(locale("korean"));
  //wcout.imbue(locale("korean"));

  //// FCodeConverter *CodeConverter = new FHangulParser();
  //FCodeConverter* CodeConverter = new FMorseConverter();
  //CodeConverter->Initilize();
  //// CodeInverter->SetInputType(FCodeConverter::EInputType::IT_Engish);
  //CodeConverter->SetInputType(EInputType::IT_Korean);

  //// FCodeConverter* CodeConverter = new FBinaryConverter();

  //wstring str;

  //getline(wcin, str);

  //wstring Code = CodeConverter->Encode(str);
  //wstring ConvertedString = CodeConverter->Decode(Code);
  //// wstring ConvertedString = CodeInverter->Decode(str);

  //wcout << Code << endl;
  //wcout << ConvertedString << endl;

  //delete CodeConverter;

  ///*wcout << int(L'ぁ') << endl;
  //wcout << int(L'ぞ') << endl;
  //wcout << int(L'た') << endl;
  //wcout << int(L'び') << endl;*/

  makeEnglishMorseCodeBook();
  makeKoreanMorseCodeBook();

  // read_json();

  /*Json::Value root;
  std::ifstream ifs;
  ifs.open("D:\\Project\\MorseConverter\\test.json");

  Json::CharReaderBuilder builder;
  builder["collectComments"] = true;
  JSONCPP_STRING errs;
  if (!parseFromStream(builder, ifs, &root, &errs)) {
    std::cout << errs << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << root << std::endl;
  return EXIT_SUCCESS;*/
  
  return 0;
}
