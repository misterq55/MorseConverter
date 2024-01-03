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
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "WChar";
  fromCode["variableType"] = keyValueType;

  codeValue["from"] = 7;
  codeValue["to"] = "A";
  fromCode["0"] = codeValue;

  codeValue["from"] = 41;
  codeValue["to"] = "B";
  fromCode["1"] = codeValue;

  codeValue["from"] = 50;
  codeValue["to"] = "C";
  fromCode["2"] = codeValue;

  codeValue["from"] = 14;
  codeValue["to"] = "D";
  fromCode["3"] = codeValue;

  codeValue["from"] = 1;
  codeValue["to"] = "E";
  fromCode["4"] = codeValue;

  codeValue["from"] = 49;
  codeValue["to"] = "F";
  fromCode["5"] = codeValue;

  codeValue["from"] = 17;
  codeValue["to"] = "G";
  fromCode["6"] = codeValue;

  codeValue["from"] = 40;
  codeValue["to"] = "H";
  fromCode["7"] = codeValue;
  
  codeValue["from"] = 4;
  codeValue["to"] = "I";
  fromCode["8"] = codeValue;

  codeValue["from"] = 79;
  codeValue["to"] = "J";
  fromCode["9"] = codeValue;

  codeValue["from"] = 23;
  codeValue["to"] = "K";
  fromCode["10"] = codeValue;

  codeValue["from"] = 43;
  codeValue["to"] = "";
  fromCode["11"] = codeValue;

  codeValue["from"] = 8;
  codeValue["to"] = "M";
  fromCode["12"] = codeValue;

  codeValue["from"] = 5;
  codeValue["to"] = "N";
  fromCode["13"] = codeValue;

  codeValue["from"] = 26;
  codeValue["to"] = "O";
  fromCode["14"] = codeValue;

  codeValue["from"] = 52;
  codeValue["to"] = "P";
  fromCode["15"] = codeValue;

  codeValue["from"] = 71;
  codeValue["to"] = "Q";
  fromCode["16"] = codeValue;

  codeValue["from"] = 16;
  codeValue["to"] = "R";
  fromCode["17"] = codeValue;

  codeValue["from"] = 13;
  codeValue["to"] = "S";
  fromCode["18"] = codeValue;

  codeValue["from"] = 2;
  codeValue["to"] = "T";
  fromCode["19"] = codeValue;

  codeValue["from"] = 22;
  codeValue["to"] = "U";
  fromCode["20"] = codeValue;

  codeValue["from"] = 67;
  codeValue["to"] = "V";
  fromCode["21"] = codeValue;

  codeValue["from"] = 25;
  codeValue["to"] = "W";
  fromCode["22"] = codeValue;

  codeValue["from"] = 68;
  codeValue["to"] = "X";
  fromCode["23"] = codeValue;

  codeValue["from"] = 77;
  codeValue["to"] = "Y";
  fromCode["24"] = codeValue;

  codeValue["from"] = 44;
  codeValue["to"] = "Z";
  fromCode["25"] = codeValue;

  codeValue["from"] = 241;
  codeValue["to"] = "1";
  fromCode["26"] = codeValue;

  codeValue["from"] = 228;
  codeValue["to"] = "2";
  fromCode["27"] = codeValue;

  codeValue["from"] = 229;
  codeValue["to"] = "3";
  fromCode["28"] = codeValue;

  codeValue["from"] = 202;
  codeValue["to"] = "4";
  fromCode["29"] = codeValue;

  codeValue["from"] = 121;
  codeValue["to"] = "5";
  fromCode["30"] = codeValue;

  codeValue["from"] = 122;
  codeValue["to"] = "6";
  fromCode["31"] = codeValue;
  
  codeValue["from"] = 125;
  codeValue["to"] = "7";
  fromCode["32"] = codeValue;

  codeValue["from"] = 134;
  codeValue["to"] = "8";
  fromCode["33"] = codeValue;

  codeValue["from"] = 161;
  codeValue["to"] = "9";
  fromCode["34"] = codeValue;

  codeValue["from"] = 242;
  codeValue["to"] = "0";
  fromCode["35"] = codeValue;

  codeValue["from"] = 355;
  codeValue["to"] = "-";
  fromCode["36"] = codeValue;

  codeValue["from"] = 637;
  codeValue["to"] = ".";
  fromCode["37"] = codeValue;

  codeValue["from"] = 692;
  codeValue["to"] = ",";
  fromCode["38"] = codeValue;
  
  codeValue["from"] = 158;
  codeValue["to"] = "(";
  fromCode["39"] = codeValue;

  codeValue["from"] = 644;
  codeValue["to"] = ")";
  fromCode["40"] = codeValue;

  codeValue["from"] = 400;
  codeValue["to"] = "?";
  fromCode["41"] = codeValue;

  codeValue["from"] = 149;
  codeValue["to"] = "/";
  fromCode["42"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;

  codeValue["from"] = "A";
  codeValue["to"] = ".-";
  toCode["0"] = codeValue;

  codeValue["from"] = "B";
  codeValue["to"] = "-...";
  toCode["1"] = codeValue;

  codeValue["from"] = "C";
  codeValue["to"] = "-.-.";
  toCode["2"] = codeValue;

  codeValue["from"] = "D";
  codeValue["to"] = "-..";
  toCode["3"] = codeValue;

  codeValue["from"] = "E";
  codeValue["to"] = ".";
  toCode["4"] = codeValue;

  codeValue["from"] = "F";
  codeValue["to"] = "..-.";
  toCode["5"] = codeValue;

  codeValue["from"] = "G";
  codeValue["to"] = "--.";
  toCode["6"] = codeValue;

  codeValue["from"] = "H";
  codeValue["to"] = "....";
  toCode["7"] = codeValue;
  
  codeValue["from"] = "I";
  codeValue["to"] = ".---";
  toCode["8"] = codeValue;

  codeValue["from"] = "J";
  codeValue["to"] = ".---";
  toCode["9"] = codeValue;

  codeValue["from"] = "K";
  codeValue["to"] = "-.-";
  toCode["10"] = codeValue;

  codeValue["from"] = "L";
  codeValue["to"] = ".-..";
  toCode["11"] = codeValue;

  codeValue["from"] = "M";
  codeValue["to"] = "--";
  toCode["12"] = codeValue;

  codeValue["from"] = "N";
  codeValue["to"] = "-.";
  toCode["13"] = codeValue;

  codeValue["from"] = "O";
  codeValue["to"] = "---";
  toCode["14"] = codeValue;

  codeValue["from"] = "P";
  codeValue["to"] = ".--.";
  toCode["15"] = codeValue;

  codeValue["from"] = "Q";
  codeValue["to"] = "--.-";
  toCode["16"] = codeValue;

  codeValue["from"] = "R";
  codeValue["to"] = ".-.";
  toCode["17"] = codeValue;

  codeValue["from"] = "S";
  codeValue["to"] = "...";
  toCode["18"] = codeValue;

  codeValue["from"] = "T";
  codeValue["to"] = "-";
  toCode["19"] = codeValue;

  codeValue["from"] = "U";
  codeValue["to"] = "..-";
  toCode["20"] = codeValue;

  codeValue["from"] = "V";
  codeValue["to"] = "...-";
  toCode["21"] = codeValue;

  codeValue["from"] = "W";
  codeValue["to"] = ".--";
  toCode["22"] = codeValue;

  codeValue["from"] = "X";
  codeValue["to"] = "-..-";
  toCode["23"] = codeValue;

  codeValue["from"] = "Y";
  codeValue["to"] = "-.--";
  toCode["24"] = codeValue;

  codeValue["from"] = "Z";
  codeValue["to"] = "--..";
  toCode["25"] = codeValue;

  codeValue["from"] = "1";
  codeValue["to"] = ".----";
  toCode["26"] = codeValue;

  codeValue["from"] = "2";
  codeValue["to"] = "..---";
  toCode["27"] = codeValue;

  codeValue["from"] = "3";
  codeValue["to"] = "...--";
  toCode["28"] = codeValue;

  codeValue["from"] = "4";
  codeValue["to"] = "....-";
  toCode["29"] = codeValue;

  codeValue["from"] = "5";
  codeValue["to"] = ".....";
  toCode["30"] = codeValue;

  codeValue["from"] = "6";
  codeValue["to"] = "-....";
  toCode["31"] = codeValue;

  codeValue["from"] = "7";
  codeValue["to"] = "--...";
  toCode["32"] = codeValue;

  codeValue["from"] = "8";
  codeValue["to"] = "---..";
  toCode["33"] = codeValue;

  codeValue["from"] = "9";
  codeValue["to"] = "----.";
  toCode["34"] = codeValue;

  codeValue["from"] = "0";
  codeValue["to"] = "-----";
  toCode["35"] = codeValue;

  codeValue["from"] = "-";
  codeValue["to"] = "-....-";
  toCode["36"] = codeValue;

  codeValue["from"] = ".";
  codeValue["to"] = ".-.-.-";
  toCode["37"] = codeValue;

  codeValue["from"] = ",";
  codeValue["to"] = "--..--";
  toCode["38"] = codeValue;

  codeValue["from"] = "(";
  codeValue["to"] = "-.--.";
  toCode["39"] = codeValue;

  codeValue["from"] = ")";
  codeValue["to"] = "-.--.-";
  toCode["40"] = codeValue;

  codeValue["from"] = "?";
  codeValue["to"] = "..--..";
  toCode["41"] = codeValue;

  codeValue["from"] = "/";
  codeValue["to"] = "-..-.";
  toCode["42"] = codeValue;

  codeValue["from"] = " ";
  codeValue["to"] = "/";
  toCode["42"] = codeValue;

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
  Json::Value codeValue;
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "WChar";
  fromCode["variableType"] = keyValueType;

  codeValue["from"] = 43;
  codeValue["to"] = "ㄱ";
  fromCode["0"] = codeValue;

  codeValue["from"] = 49;
  codeValue["to"] = "ㄴ";
  fromCode["1"] = codeValue;

  codeValue["from"] = 41;
  codeValue["to"] = "ㄷ";
  fromCode["2"] = codeValue;

  codeValue["from"] = 67;
  codeValue["to"] = "ㄹ";
  fromCode["3"] = codeValue;

  codeValue["from"] = 8;
  codeValue["to"] = "ㅁ";
  fromCode["4"] = codeValue;

  codeValue["from"] = 25;
  codeValue["to"] = "ㅂ";
  fromCode["5"] = codeValue;

  codeValue["from"] = 17;
  codeValue["to"] = "ㅅ";
  fromCode["6"] = codeValue;

  codeValue["from"] = 23;
  codeValue["to"] = "ㅇ";
  fromCode["7"] = codeValue;

  codeValue["from"] = 52;
  codeValue["to"] = "ㅈ";
  fromCode["8"] = codeValue;

  codeValue["from"] = 50;
  codeValue["to"] = "ㅊ";
  fromCode["9"] = codeValue;

  codeValue["from"] = 68;
  codeValue["to"] = "ㅋ";
  fromCode["10"] = codeValue;

  codeValue["from"] = 44;
  codeValue["to"] = "ㅌ";
  fromCode["11"] = codeValue;

  codeValue["from"] = 26;
  codeValue["to"] = "ㅍ";
  fromCode["12"] = codeValue;

  codeValue["from"] = 79;
  codeValue["to"] = "ㅎ";
  fromCode["13"] = codeValue;

  codeValue["from"] = 1;
  codeValue["to"] = "ㅏ";
  fromCode["14"] = codeValue;

  codeValue["from"] = 4;
  codeValue["to"] = "ㅑ";
  fromCode["15"] = codeValue;

  codeValue["from"] = 2;
  codeValue["to"] = "ㅓ";
  fromCode["16"] = codeValue;

  codeValue["from"] = 13;
  codeValue["to"] = "ㅕ";
  fromCode["17"] = codeValue;

  codeValue["from"] = 7;
  codeValue["to"] = "ㅗ";
  fromCode["18"] = codeValue;

  codeValue["from"] = 5;
  codeValue["to"] = "ㅛ";
  fromCode["19"] = codeValue;

  codeValue["from"] = 40;
  codeValue["to"] = "ㅜ";
  fromCode["20"] = codeValue;

  codeValue["from"] = 16;
  codeValue["to"] = "ㅠ";
  fromCode["21"] = codeValue;

  codeValue["from"] = 14;
  codeValue["to"] = "ㅡ";
  fromCode["22"] = codeValue;

  codeValue["from"] = 22;
  codeValue["to"] = "ㅣ";
  fromCode["23"] = codeValue;

  codeValue["from"] = 71;
  codeValue["to"] = "ㅐ";
  fromCode["24"] = codeValue;

  codeValue["from"] = 77;
  codeValue["to"] = "ㅔ";
  fromCode["25"] = codeValue;

  codeValue["from"] = 241;
  codeValue["to"] = "1";
  fromCode["26"] = codeValue;

  codeValue["from"] = 228;
  codeValue["to"] = "2";
  fromCode["27"] = codeValue;

  codeValue["from"] = 229;
  codeValue["to"] = "3";
  fromCode["28"] = codeValue;

  codeValue["from"] = 202;
  codeValue["to"] = "4";
  fromCode["29"] = codeValue;

  codeValue["from"] = 121;
  codeValue["to"] = "5";
  fromCode["30"] = codeValue;

  codeValue["from"] = 122;
  codeValue["to"] = "6";
  fromCode["31"] = codeValue;

  codeValue["from"] = 125;
  codeValue["to"] = "7";
  fromCode["32"] = codeValue;

  codeValue["from"] = 134;
  codeValue["to"] = "8";
  fromCode["33"] = codeValue;

  codeValue["from"] = 161;
  codeValue["to"] = "9";
  fromCode["34"] = codeValue;

  codeValue["from"] = 242;
  codeValue["to"] = "0";
  fromCode["35"] = codeValue;

  codeValue["from"] = 355;
  codeValue["to"] = "-";
  fromCode["36"] = codeValue;

  codeValue["from"] = 637;
  codeValue["to"] = ".";
  fromCode["37"] = codeValue;

  codeValue["from"] = 692;
  codeValue["to"] = ",";
  fromCode["38"] = codeValue;

  codeValue["from"] = 158;
  codeValue["to"] = "(";
  fromCode["39"] = codeValue;

  codeValue["from"] = 644;
  codeValue["to"] = ")";
  fromCode["40"] = codeValue;

  codeValue["from"] = 400;
  codeValue["to"] = "?";
  fromCode["41"] = codeValue;

  codeValue["from"] = 149;
  codeValue["to"] = "/";
  fromCode["42"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;

  codeValue["from"] = "ㄱ";
  codeValue["to"] = ".-..";
  toCode["0"] = codeValue;

  codeValue["from"] = "ㄴ";
  codeValue["to"] = "..-.";
  toCode["1"] = codeValue;

  codeValue["from"] = "ㄷ";
  codeValue["to"] = "-...";
  toCode["2"] = codeValue;

  codeValue["from"] = "ㄹ";
  codeValue["to"] = "...-";
  toCode["3"] = codeValue;

  codeValue["from"] = "ㅁ";
  codeValue["to"] = "--";
  toCode["4"] = codeValue;

  codeValue["from"] = "ㅂ";
  codeValue["to"] = ".--";
  toCode["5"] = codeValue;

  codeValue["from"] = "ㅅ";
  codeValue["to"] = "--.";
  toCode["6"] = codeValue;

  codeValue["from"] = "ㅇ";
  codeValue["to"] = "-.-";
  toCode["7"] = codeValue;

  codeValue["from"] = "ㅈ";
  codeValue["to"] = ".--.";
  toCode["8"] = codeValue;

  codeValue["from"] = "ㅊ";
  codeValue["to"] = "-.-.";
  toCode["9"] = codeValue;

  codeValue["from"] = "ㅋ";
  codeValue["to"] = "-..-";
  toCode["10"] = codeValue;

  codeValue["from"] = "ㅌ";
  codeValue["to"] = "--..";
  toCode["11"] = codeValue;

  codeValue["from"] = "ㅍ";
  codeValue["to"] = "---";
  toCode["12"] = codeValue;

  codeValue["from"] = "ㅎ";
  codeValue["to"] = ".---";
  toCode["13"] = codeValue;

  codeValue["from"] = "ㅏ";
  codeValue["to"] = ".";
  toCode["14"] = codeValue;

  codeValue["from"] = "ㅑ";
  codeValue["to"] = "..";
  toCode["15"] = codeValue;

  codeValue["from"] = "ㅓ";
  codeValue["to"] = "-";
  toCode["16"] = codeValue;

  codeValue["from"] = "ㅕ";
  codeValue["to"] = "...";
  toCode["17"] = codeValue;

  codeValue["from"] = "ㅗ";
  codeValue["to"] = ".-";
  toCode["18"] = codeValue;

  codeValue["from"] = "ㅛ";
  codeValue["to"] = "-.";
  toCode["19"] = codeValue;

  codeValue["from"] = "ㅜ";
  codeValue["to"] = "....";
  toCode["20"] = codeValue;

  codeValue["from"] = "ㅠ";
  codeValue["to"] = ".-.";
  toCode["21"] = codeValue;

  codeValue["from"] = "ㅡ";
  codeValue["to"] = "-..";
  toCode["22"] = codeValue;

  codeValue["from"] = "ㅣ";
  codeValue["to"] = "..-";
  toCode["23"] = codeValue;

  codeValue["from"] = "ㅐ";
  codeValue["to"] = "--.-";
  toCode["24"] = codeValue;

  codeValue["from"] = "ㅔ";
  codeValue["to"] = "-.--";
  toCode["25"] = codeValue;

  codeValue["from"] = "1";
  codeValue["to"] = ".----";
  toCode["26"] = codeValue;

  codeValue["from"] = "2";
  codeValue["to"] = "..---";
  toCode["27"] = codeValue;

  codeValue["from"] = "3";
  codeValue["to"] = "...--";
  toCode["28"] = codeValue;

  codeValue["from"] = "4";
  codeValue["to"] = "....-";
  toCode["29"] = codeValue;

  codeValue["from"] = "5";
  codeValue["to"] = ".....";
  toCode["30"] = codeValue;

  codeValue["from"] = "6";
  codeValue["to"] = "-....";
  toCode["31"] = codeValue;

  codeValue["from"] = "7";
  codeValue["to"] = "--...";
  toCode["32"] = codeValue;

  codeValue["from"] = "8";
  codeValue["to"] = "---..";
  toCode["33"] = codeValue;

  codeValue["from"] = "9";
  codeValue["to"] = "----.";
  toCode["34"] = codeValue;

  codeValue["from"] = "0";
  codeValue["to"] = "-----";
  toCode["35"] = codeValue;

  codeValue["from"] = "-";
  codeValue["to"] = "-....-";
  toCode["36"] = codeValue;

  codeValue["from"] = ".";
  codeValue["to"] = ".-.-.-";
  toCode["37"] = codeValue;

  codeValue["from"] = ",";
  codeValue["to"] = "--..--";
  toCode["38"] = codeValue;

  codeValue["from"] = "(";
  codeValue["to"] = "-.--.";
  toCode["39"] = codeValue;

  codeValue["from"] = ")";
  codeValue["to"] = "-.--.-";
  toCode["40"] = codeValue;

  codeValue["from"] = "?";
  codeValue["to"] = "..--..";
  toCode["41"] = codeValue;

  codeValue["from"] = "/";
  codeValue["to"] = "-..-.";
  toCode["42"] = codeValue;

  codeValue["from"] = " ";
  codeValue["to"] = "/";
  toCode["42"] = codeValue;

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("MorseKoreanCodeBook.json");
  writer->write(root, &output_file);
}

void makeKoreanConsonantLetterCodeBook()
{
  Json::Value root;
  Json::Value fromCode;
  Json::Value keyValueType;
  Json::Value codeValue;
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "String";
  fromCode["variableType"] = keyValueType;

  codeValue["from"] = 0xAC00;
  codeValue["to"] = "ㄱ";
  fromCode["0"] = codeValue;

  codeValue["from"] = 0xAE4C;
  codeValue["to"] = "ㄱㄱ";
  fromCode["1"] = codeValue;

  codeValue["from"] = 0xB098;
  codeValue["to"] = "ㄴ";
  fromCode["2"] = codeValue;

  codeValue["from"] = 0xB2E4;
  codeValue["to"] = "ㄷ";
  fromCode["3"] = codeValue;

  codeValue["from"] = 0xB530;
  codeValue["to"] = "ㄷㄷ";
  fromCode["4"] = codeValue;

  codeValue["from"] = 0xB77C;
  codeValue["to"] = "ㄹ";
  fromCode["5"] = codeValue;

  codeValue["from"] = 0xB9C8;
  codeValue["to"] = "ㅁ";
  fromCode["6"] = codeValue;

  codeValue["from"] = 0xBC14;
  codeValue["to"] = "ㅂ";
  fromCode["7"] = codeValue;

  codeValue["from"] = 0xBE60;
  codeValue["to"] = "ㅂㅂ";
  fromCode["8"] = codeValue;

  codeValue["from"] = 0xC0AC;
  codeValue["to"] = "ㅅ";
  fromCode["9"] = codeValue;

  codeValue["from"] = 0xC2F8;
  codeValue["to"] = "ㅅㅅ";
  fromCode["10"] = codeValue;

  codeValue["from"] = 0xC544;
  codeValue["to"] = "ㅇ";
  fromCode["11"] = codeValue;

  codeValue["from"] = 0xC790;
  codeValue["to"] = "ㅈ";
  fromCode["12"] = codeValue;

  codeValue["from"] = 0xC9DC;
  codeValue["to"] = "ㅈㅈ";
  fromCode["13"] = codeValue;

  codeValue["from"] = 0xCC28;
  codeValue["to"] = "ㅊ";
  fromCode["14"] = codeValue;

  codeValue["from"] = 0xCE74;
  codeValue["to"] = "ㅋ";
  fromCode["15"] = codeValue;

  codeValue["from"] = 0xD0C0;
  codeValue["to"] = "ㅌ";
  fromCode["16"] = codeValue;

  codeValue["from"] = 0xD30C;
  codeValue["to"] = "ㅍ";
  fromCode["17"] = codeValue;

  codeValue["from"] = 0xD558;
  codeValue["to"] = "ㅎ";
  fromCode["18"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "Int";
  toCode["variableType"] = keyValueType;

  codeValue["from"] = "ㄱ";
  codeValue["to"] = 0xAC00;
  toCode["0"] = codeValue;

  codeValue["from"] = "ㄱㄱ";
  codeValue["to"] = 0xAE4C;
  toCode["1"] = codeValue;

  codeValue["from"] = "ㄴ";
  codeValue["to"] = 0xAE4C;
  toCode["2"] = codeValue;

  codeValue["from"] = "ㄷ";
  codeValue["to"] = 0xB2E4;
  toCode["3"] = codeValue;

  codeValue["from"] = "ㄷㄷ";
  codeValue["to"] = 0xB530;
  toCode["4"] = codeValue;

  codeValue["from"] = "ㄹ";
  codeValue["to"] = 0xB77C;
  toCode["5"] = codeValue;

  codeValue["from"] = "ㅁ";
  codeValue["to"] = 0xB9C8;
  toCode["6"] = codeValue;

  codeValue["from"] = "ㅂ";
  codeValue["to"] = 0xBC14;
  toCode["7"] = codeValue;

  codeValue["from"] = "ㅂㅂ";
  codeValue["to"] = 0xBE60;
  toCode["8"] = codeValue;

  codeValue["from"] = "ㅅ";
  codeValue["to"] = 0xC0AC;
  toCode["9"] = codeValue;

  codeValue["from"] = "ㅅㅅ";
  codeValue["to"] = 0xC2F8;
  toCode["10"] = codeValue;

  codeValue["from"] = "ㅇ";
  codeValue["to"] = 0xC544;
  toCode["11"] = codeValue;

  codeValue["from"] = "ㅈ";
  codeValue["to"] = 0xC790;
  toCode["12"] = codeValue;

  codeValue["from"] = "ㅈㅈ";
  codeValue["to"] = 0xC9DC;
  toCode["13"] = codeValue;

  codeValue["from"] = "ㅊ";
  codeValue["to"] = 0xCC28;
  toCode["14"] = codeValue;

  codeValue["from"] = "ㅋ";
  codeValue["to"] = 0xCE74;
  toCode["15"] = codeValue;

  codeValue["from"] = "ㅌ";
  codeValue["to"] = 0xD0C0;
  toCode["16"] = codeValue;

  codeValue["from"] = "ㅍ";
  codeValue["to"] = 0xD30C;
  toCode["17"] = codeValue;

  codeValue["from"] = "ㅎ";
  codeValue["to"] = 0xD558;
  toCode["18"] = codeValue;

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("KoreanConsonantLetterCodeBook.json");
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
  makeKoreanMorseCodeBook();
  makeKoreanConsonantLetterCodeBook();

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
