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
  Json::Value codeValue;
  // keyValueType["keyVariableType"] = "Int";
  // keyValueType["valueVariableType"] = "WChar";
  // fromCode["variableType"] = keyValueType;

  codeValue["from"] = 7;
  codeValue["to"] = L'A';
  fromCode["0"] = codeValue;

  codeValue["from"] = 41;
  codeValue["to"] = L'B';
  fromCode["1"] = codeValue;

  codeValue["from"] = 50;
  codeValue["to"] = L'C';
  fromCode["2"] = codeValue;

  codeValue["from"] = 14;
  codeValue["to"] = L'D';
  fromCode["3"] = codeValue;

  codeValue["from"] = 1;
  codeValue["to"] = L'E';
  fromCode["4"] = codeValue;

  codeValue["from"] = 49;
  codeValue["to"] = L'F';
  fromCode["5"] = codeValue;

  codeValue["from"] = 17;
  codeValue["to"] = L'G';
  fromCode["6"] = codeValue;

  codeValue["from"] = 40;
  codeValue["to"] = L'H';
  fromCode["7"] = codeValue;
  
  codeValue["from"] = 4;
  codeValue["to"] = L'I';
  fromCode["8"] = codeValue;

  codeValue["from"] = 79;
  codeValue["to"] = L'J';
  fromCode["9"] = codeValue;

  codeValue["from"] = 23;
  codeValue["to"] = L'K';
  fromCode["10"] = codeValue;

  codeValue["from"] = 43;
  codeValue["to"] = L'L';
  fromCode["11"] = codeValue;

  codeValue["from"] = 8;
  codeValue["to"] = L'M';
  fromCode["12"] = codeValue;

  codeValue["from"] = 5;
  codeValue["to"] = L'N';
  fromCode["13"] = codeValue;

  codeValue["from"] = 26;
  codeValue["to"] = L'O';
  fromCode["14"] = codeValue;

  codeValue["from"] = 52;
  codeValue["to"] = L'P';
  fromCode["15"] = codeValue;

  codeValue["from"] = 71;
  codeValue["to"] = L'Q';
  fromCode["16"] = codeValue;

  codeValue["from"] = 16;
  codeValue["to"] = L'R';
  fromCode["17"] = codeValue;

  codeValue["from"] = 13;
  codeValue["to"] = L'S';
  fromCode["18"] = codeValue;

  codeValue["from"] = 2;
  codeValue["to"] = L'T';
  fromCode["19"] = codeValue;

  codeValue["from"] = 22;
  codeValue["to"] = L'U';
  fromCode["20"] = codeValue;

  codeValue["from"] = 67;
  codeValue["to"] = L'V';
  fromCode["21"] = codeValue;

  codeValue["from"] = 25;
  codeValue["to"] = L'W';
  fromCode["22"] = codeValue;

  codeValue["from"] = 68;
  codeValue["to"] = L'X';
  fromCode["23"] = codeValue;

  codeValue["from"] = 77;
  codeValue["to"] = L'Y';
  fromCode["24"] = codeValue;

  codeValue["from"] = 44;
  codeValue["to"] = L'Z';
  fromCode["25"] = codeValue;

  codeValue["from"] = 241;
  codeValue["to"] = L'1';
  fromCode["26"] = codeValue;

  codeValue["from"] = 228;
  codeValue["to"] = L'2';
  fromCode["27"] = codeValue;

  codeValue["from"] = 229;
  codeValue["to"] = L'3';
  fromCode["28"] = codeValue;

  codeValue["from"] = 202;
  codeValue["to"] = L'4';
  fromCode["29"] = codeValue;

  codeValue["from"] = 121;
  codeValue["to"] = L'5';
  fromCode["30"] = codeValue;

  codeValue["from"] = 122;
  codeValue["to"] = L'6';
  fromCode["31"] = codeValue;
  
  codeValue["from"] = 125;
  codeValue["to"] = L'7';
  fromCode["32"] = codeValue;

  codeValue["from"] = 134;
  codeValue["to"] = L'8';
  fromCode["33"] = codeValue;

  codeValue["from"] = 161;
  codeValue["to"] = L'9';
  fromCode["34"] = codeValue;

  codeValue["from"] = 242;
  codeValue["to"] = L'0';
  fromCode["35"] = codeValue;

  codeValue["from"] = 355;
  codeValue["to"] = L'-';
  fromCode["36"] = codeValue;

  codeValue["from"] = 637;
  codeValue["to"] = L'.';
  fromCode["37"] = codeValue;

  codeValue["from"] = 692;
  codeValue["to"] = L',';
  fromCode["38"] = codeValue;
  
  codeValue["from"] = 158;
  codeValue["to"] = L'(';
  fromCode["39"] = codeValue;

  codeValue["from"] = 644;
  codeValue["to"] = L')';
  fromCode["40"] = codeValue;

  codeValue["from"] = 400;
  codeValue["to"] = L'?';
  fromCode["41"] = codeValue;

  codeValue["from"] = 149;
  codeValue["to"] = L'/';
  fromCode["42"] = codeValue;

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
  fromCode["43"] = "ㄱ";
  fromCode["49"] = "ㄴ";
  fromCode["41"] = "ㄷ";
  fromCode["67"] = "ㄹ";
  fromCode["8"] = "ㅁ";
  fromCode["25"] = "ㅂ";
  fromCode["17"] = "ㅅ";
  fromCode["23"] = "ㅇ";
  fromCode["52"] = "ㅈ";
  fromCode["50"] = "ㅊ";
  fromCode["68"] = "ㅋ";
  fromCode["44"] = "ㅌ";
  fromCode["26"] = "ㅍ";
  fromCode["79"] = "ㅎ";

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
  // wcin.imbue(locale("korean"));
  // wcout.imbue(locale("korean"));

  // FCodeConverter *CodeConverter = new FHangulParser();
  // FCodeConverter* CodeConverter = new FMorseConverter();
  // CodeConverter->Initilize();
  // CodeConverter->SetInputType(EInputType::IT_Engish);
  // CodeConverter->SetInputType(EInputType::IT_Korean);

  // FCodeConverter* CodeConverter = new FBinaryConverter();

  // wstring str;

  // getline(wcin, str);

  // wstring Code = CodeConverter->Encode(str);
  // wstring ConvertedString = CodeConverter->Decode(Code);
  // // wstring ConvertedString = CodeInverter->Decode(str);

  // wcout << Code << endl;
  // wcout << ConvertedString << endl;

  // delete CodeConverter;

  ///*wcout << int(L'ㄱ') << endl;
  //wcout << int(L'ㅎ') << endl;
  //wcout << int(L'ㅏ') << endl;
  //wcout << int(L'ㅣ') << endl;*/

  makeEnglishMorseCodeBook();
  // makeKoreanMorseCodeBook();

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
