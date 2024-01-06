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

  codeValue["key"] = 7;
  codeValue["value"] = "A";
  fromCode["0"] = codeValue;

  codeValue["key"] = 41;
  codeValue["value"] = "B";
  fromCode["1"] = codeValue;

  codeValue["key"] = 50;
  codeValue["value"] = "C";
  fromCode["2"] = codeValue;

  codeValue["key"] = 14;
  codeValue["value"] = "D";
  fromCode["3"] = codeValue;

  codeValue["key"] = 1;
  codeValue["value"] = "E";
  fromCode["4"] = codeValue;

  codeValue["key"] = 49;
  codeValue["value"] = "F";
  fromCode["5"] = codeValue;

  codeValue["key"] = 17;
  codeValue["value"] = "G";
  fromCode["6"] = codeValue;

  codeValue["key"] = 40;
  codeValue["value"] = "H";
  fromCode["7"] = codeValue;
  
  codeValue["key"] = 4;
  codeValue["value"] = "I";
  fromCode["8"] = codeValue;

  codeValue["key"] = 79;
  codeValue["value"] = "J";
  fromCode["9"] = codeValue;

  codeValue["key"] = 23;
  codeValue["value"] = "K";
  fromCode["10"] = codeValue;

  codeValue["key"] = 43;
  codeValue["value"] = "";
  fromCode["11"] = codeValue;

  codeValue["key"] = 8;
  codeValue["value"] = "M";
  fromCode["12"] = codeValue;

  codeValue["key"] = 5;
  codeValue["value"] = "N";
  fromCode["13"] = codeValue;

  codeValue["key"] = 26;
  codeValue["value"] = "O";
  fromCode["14"] = codeValue;

  codeValue["key"] = 52;
  codeValue["value"] = "P";
  fromCode["15"] = codeValue;

  codeValue["key"] = 71;
  codeValue["value"] = "Q";
  fromCode["16"] = codeValue;

  codeValue["key"] = 16;
  codeValue["value"] = "R";
  fromCode["17"] = codeValue;

  codeValue["key"] = 13;
  codeValue["value"] = "S";
  fromCode["18"] = codeValue;

  codeValue["key"] = 2;
  codeValue["value"] = "T";
  fromCode["19"] = codeValue;

  codeValue["key"] = 22;
  codeValue["value"] = "U";
  fromCode["20"] = codeValue;

  codeValue["key"] = 67;
  codeValue["value"] = "V";
  fromCode["21"] = codeValue;

  codeValue["key"] = 25;
  codeValue["value"] = "W";
  fromCode["22"] = codeValue;

  codeValue["key"] = 68;
  codeValue["value"] = "X";
  fromCode["23"] = codeValue;

  codeValue["key"] = 77;
  codeValue["value"] = "Y";
  fromCode["24"] = codeValue;

  codeValue["key"] = 44;
  codeValue["value"] = "Z";
  fromCode["25"] = codeValue;

  codeValue["key"] = 241;
  codeValue["value"] = "1";
  fromCode["26"] = codeValue;

  codeValue["key"] = 228;
  codeValue["value"] = "2";
  fromCode["27"] = codeValue;

  codeValue["key"] = 229;
  codeValue["value"] = "3";
  fromCode["28"] = codeValue;

  codeValue["key"] = 202;
  codeValue["value"] = "4";
  fromCode["29"] = codeValue;

  codeValue["key"] = 121;
  codeValue["value"] = "5";
  fromCode["30"] = codeValue;

  codeValue["key"] = 122;
  codeValue["value"] = "6";
  fromCode["31"] = codeValue;
  
  codeValue["key"] = 125;
  codeValue["value"] = "7";
  fromCode["32"] = codeValue;

  codeValue["key"] = 134;
  codeValue["value"] = "8";
  fromCode["33"] = codeValue;

  codeValue["key"] = 161;
  codeValue["value"] = "9";
  fromCode["34"] = codeValue;

  codeValue["key"] = 242;
  codeValue["value"] = "0";
  fromCode["35"] = codeValue;

  codeValue["key"] = 355;
  codeValue["value"] = "-";
  fromCode["36"] = codeValue;

  codeValue["key"] = 637;
  codeValue["value"] = ".";
  fromCode["37"] = codeValue;

  codeValue["key"] = 692;
  codeValue["value"] = ",";
  fromCode["38"] = codeValue;
  
  codeValue["key"] = 158;
  codeValue["value"] = "(";
  fromCode["39"] = codeValue;

  codeValue["key"] = 644;
  codeValue["value"] = ")";
  fromCode["40"] = codeValue;

  codeValue["key"] = 400;
  codeValue["value"] = "?";
  fromCode["41"] = codeValue;

  codeValue["key"] = 149;
  codeValue["value"] = "/";
  fromCode["42"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;

  codeValue["key"] = "A";
  codeValue["value"] = ".-";
  toCode["0"] = codeValue;

  codeValue["key"] = "B";
  codeValue["value"] = "-...";
  toCode["1"] = codeValue;

  codeValue["key"] = "C";
  codeValue["value"] = "-.-.";
  toCode["2"] = codeValue;

  codeValue["key"] = "D";
  codeValue["value"] = "-..";
  toCode["3"] = codeValue;

  codeValue["key"] = "E";
  codeValue["value"] = ".";
  toCode["4"] = codeValue;

  codeValue["key"] = "F";
  codeValue["value"] = "..-.";
  toCode["5"] = codeValue;

  codeValue["key"] = "G";
  codeValue["value"] = "--.";
  toCode["6"] = codeValue;

  codeValue["key"] = "H";
  codeValue["value"] = "....";
  toCode["7"] = codeValue;
  
  codeValue["key"] = "I";
  codeValue["value"] = ".---";
  toCode["8"] = codeValue;

  codeValue["key"] = "J";
  codeValue["value"] = ".---";
  toCode["9"] = codeValue;

  codeValue["key"] = "K";
  codeValue["value"] = "-.-";
  toCode["10"] = codeValue;

  codeValue["key"] = "L";
  codeValue["value"] = ".-..";
  toCode["11"] = codeValue;

  codeValue["key"] = "M";
  codeValue["value"] = "--";
  toCode["12"] = codeValue;

  codeValue["key"] = "N";
  codeValue["value"] = "-.";
  toCode["13"] = codeValue;

  codeValue["key"] = "O";
  codeValue["value"] = "---";
  toCode["14"] = codeValue;

  codeValue["key"] = "P";
  codeValue["value"] = ".--.";
  toCode["15"] = codeValue;

  codeValue["key"] = "Q";
  codeValue["value"] = "--.-";
  toCode["16"] = codeValue;

  codeValue["key"] = "R";
  codeValue["value"] = ".-.";
  toCode["17"] = codeValue;

  codeValue["key"] = "S";
  codeValue["value"] = "...";
  toCode["18"] = codeValue;

  codeValue["key"] = "T";
  codeValue["value"] = "-";
  toCode["19"] = codeValue;

  codeValue["key"] = "U";
  codeValue["value"] = "..-";
  toCode["20"] = codeValue;

  codeValue["key"] = "V";
  codeValue["value"] = "...-";
  toCode["21"] = codeValue;

  codeValue["key"] = "W";
  codeValue["value"] = ".--";
  toCode["22"] = codeValue;

  codeValue["key"] = "X";
  codeValue["value"] = "-..-";
  toCode["23"] = codeValue;

  codeValue["key"] = "Y";
  codeValue["value"] = "-.--";
  toCode["24"] = codeValue;

  codeValue["key"] = "Z";
  codeValue["value"] = "--..";
  toCode["25"] = codeValue;

  codeValue["key"] = "1";
  codeValue["value"] = ".----";
  toCode["26"] = codeValue;

  codeValue["key"] = "2";
  codeValue["value"] = "..---";
  toCode["27"] = codeValue;

  codeValue["key"] = "3";
  codeValue["value"] = "...--";
  toCode["28"] = codeValue;

  codeValue["key"] = "4";
  codeValue["value"] = "....-";
  toCode["29"] = codeValue;

  codeValue["key"] = "5";
  codeValue["value"] = ".....";
  toCode["30"] = codeValue;

  codeValue["key"] = "6";
  codeValue["value"] = "-....";
  toCode["31"] = codeValue;

  codeValue["key"] = "7";
  codeValue["value"] = "--...";
  toCode["32"] = codeValue;

  codeValue["key"] = "8";
  codeValue["value"] = "---..";
  toCode["33"] = codeValue;

  codeValue["key"] = "9";
  codeValue["value"] = "----.";
  toCode["34"] = codeValue;

  codeValue["key"] = "0";
  codeValue["value"] = "-----";
  toCode["35"] = codeValue;

  codeValue["key"] = "-";
  codeValue["value"] = "-....-";
  toCode["36"] = codeValue;

  codeValue["key"] = ".";
  codeValue["value"] = ".-.-.-";
  toCode["37"] = codeValue;

  codeValue["key"] = ",";
  codeValue["value"] = "--..--";
  toCode["38"] = codeValue;

  codeValue["key"] = "(";
  codeValue["value"] = "-.--.";
  toCode["39"] = codeValue;

  codeValue["key"] = ")";
  codeValue["value"] = "-.--.-";
  toCode["40"] = codeValue;

  codeValue["key"] = "?";
  codeValue["value"] = "..--..";
  toCode["41"] = codeValue;

  codeValue["key"] = "/";
  codeValue["value"] = "-..-.";
  toCode["42"] = codeValue;

  codeValue["key"] = " ";
  codeValue["value"] = "/";
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

  codeValue["key"] = 43;
  codeValue["value"] = "ㄱ";
  fromCode["0"] = codeValue;

  codeValue["key"] = 49;
  codeValue["value"] = "ㄴ";
  fromCode["1"] = codeValue;

  codeValue["key"] = 41;
  codeValue["value"] = "ㄷ";
  fromCode["2"] = codeValue;

  codeValue["key"] = 67;
  codeValue["value"] = "ㄹ";
  fromCode["3"] = codeValue;

  codeValue["key"] = 8;
  codeValue["value"] = "ㅁ";
  fromCode["4"] = codeValue;

  codeValue["key"] = 25;
  codeValue["value"] = "ㅂ";
  fromCode["5"] = codeValue;

  codeValue["key"] = 17;
  codeValue["value"] = "ㅅ";
  fromCode["6"] = codeValue;

  codeValue["key"] = 23;
  codeValue["value"] = "ㅇ";
  fromCode["7"] = codeValue;

  codeValue["key"] = 52;
  codeValue["value"] = "ㅈ";
  fromCode["8"] = codeValue;

  codeValue["key"] = 50;
  codeValue["value"] = "ㅊ";
  fromCode["9"] = codeValue;

  codeValue["key"] = 68;
  codeValue["value"] = "ㅋ";
  fromCode["10"] = codeValue;

  codeValue["key"] = 44;
  codeValue["value"] = "ㅌ";
  fromCode["11"] = codeValue;

  codeValue["key"] = 26;
  codeValue["value"] = "ㅍ";
  fromCode["12"] = codeValue;

  codeValue["key"] = 79;
  codeValue["value"] = "ㅎ";
  fromCode["13"] = codeValue;

  codeValue["key"] = 1;
  codeValue["value"] = "ㅏ";
  fromCode["14"] = codeValue;

  codeValue["key"] = 4;
  codeValue["value"] = "ㅑ";
  fromCode["15"] = codeValue;

  codeValue["key"] = 2;
  codeValue["value"] = "ㅓ";
  fromCode["16"] = codeValue;

  codeValue["key"] = 13;
  codeValue["value"] = "ㅕ";
  fromCode["17"] = codeValue;

  codeValue["key"] = 7;
  codeValue["value"] = "ㅗ";
  fromCode["18"] = codeValue;

  codeValue["key"] = 5;
  codeValue["value"] = "ㅛ";
  fromCode["19"] = codeValue;

  codeValue["key"] = 40;
  codeValue["value"] = "ㅜ";
  fromCode["20"] = codeValue;

  codeValue["key"] = 16;
  codeValue["value"] = "ㅠ";
  fromCode["21"] = codeValue;

  codeValue["key"] = 14;
  codeValue["value"] = "ㅡ";
  fromCode["22"] = codeValue;

  codeValue["key"] = 22;
  codeValue["value"] = "ㅣ";
  fromCode["23"] = codeValue;

  codeValue["key"] = 71;
  codeValue["value"] = "ㅐ";
  fromCode["24"] = codeValue;

  codeValue["key"] = 77;
  codeValue["value"] = "ㅔ";
  fromCode["25"] = codeValue;

  codeValue["key"] = 241;
  codeValue["value"] = "1";
  fromCode["26"] = codeValue;

  codeValue["key"] = 228;
  codeValue["value"] = "2";
  fromCode["27"] = codeValue;

  codeValue["key"] = 229;
  codeValue["value"] = "3";
  fromCode["28"] = codeValue;

  codeValue["key"] = 202;
  codeValue["value"] = "4";
  fromCode["29"] = codeValue;

  codeValue["key"] = 121;
  codeValue["value"] = "5";
  fromCode["30"] = codeValue;

  codeValue["key"] = 122;
  codeValue["value"] = "6";
  fromCode["31"] = codeValue;

  codeValue["key"] = 125;
  codeValue["value"] = "7";
  fromCode["32"] = codeValue;

  codeValue["key"] = 134;
  codeValue["value"] = "8";
  fromCode["33"] = codeValue;

  codeValue["key"] = 161;
  codeValue["value"] = "9";
  fromCode["34"] = codeValue;

  codeValue["key"] = 242;
  codeValue["value"] = "0";
  fromCode["35"] = codeValue;

  codeValue["key"] = 355;
  codeValue["value"] = "-";
  fromCode["36"] = codeValue;

  codeValue["key"] = 637;
  codeValue["value"] = ".";
  fromCode["37"] = codeValue;

  codeValue["key"] = 692;
  codeValue["value"] = ",";
  fromCode["38"] = codeValue;

  codeValue["key"] = 158;
  codeValue["value"] = "(";
  fromCode["39"] = codeValue;

  codeValue["key"] = 644;
  codeValue["value"] = ")";
  fromCode["40"] = codeValue;

  codeValue["key"] = 400;
  codeValue["value"] = "?";
  fromCode["41"] = codeValue;

  codeValue["key"] = 149;
  codeValue["value"] = "/";
  fromCode["42"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;

  codeValue["key"] = "ㄱ";
  codeValue["value"] = ".-..";
  toCode["0"] = codeValue;

  codeValue["key"] = "ㄴ";
  codeValue["value"] = "..-.";
  toCode["1"] = codeValue;

  codeValue["key"] = "ㄷ";
  codeValue["value"] = "-...";
  toCode["2"] = codeValue;

  codeValue["key"] = "ㄹ";
  codeValue["value"] = "...-";
  toCode["3"] = codeValue;

  codeValue["key"] = "ㅁ";
  codeValue["value"] = "--";
  toCode["4"] = codeValue;

  codeValue["key"] = "ㅂ";
  codeValue["value"] = ".--";
  toCode["5"] = codeValue;

  codeValue["key"] = "ㅅ";
  codeValue["value"] = "--.";
  toCode["6"] = codeValue;

  codeValue["key"] = "ㅇ";
  codeValue["value"] = "-.-";
  toCode["7"] = codeValue;

  codeValue["key"] = "ㅈ";
  codeValue["value"] = ".--.";
  toCode["8"] = codeValue;

  codeValue["key"] = "ㅊ";
  codeValue["value"] = "-.-.";
  toCode["9"] = codeValue;

  codeValue["key"] = "ㅋ";
  codeValue["value"] = "-..-";
  toCode["10"] = codeValue;

  codeValue["key"] = "ㅌ";
  codeValue["value"] = "--..";
  toCode["11"] = codeValue;

  codeValue["key"] = "ㅍ";
  codeValue["value"] = "---";
  toCode["12"] = codeValue;

  codeValue["key"] = "ㅎ";
  codeValue["value"] = ".---";
  toCode["13"] = codeValue;

  codeValue["key"] = "ㅏ";
  codeValue["value"] = ".";
  toCode["14"] = codeValue;

  codeValue["key"] = "ㅑ";
  codeValue["value"] = "..";
  toCode["15"] = codeValue;

  codeValue["key"] = "ㅓ";
  codeValue["value"] = "-";
  toCode["16"] = codeValue;

  codeValue["key"] = "ㅕ";
  codeValue["value"] = "...";
  toCode["17"] = codeValue;

  codeValue["key"] = "ㅗ";
  codeValue["value"] = ".-";
  toCode["18"] = codeValue;

  codeValue["key"] = "ㅛ";
  codeValue["value"] = "-.";
  toCode["19"] = codeValue;

  codeValue["key"] = "ㅜ";
  codeValue["value"] = "....";
  toCode["20"] = codeValue;

  codeValue["key"] = "ㅠ";
  codeValue["value"] = ".-.";
  toCode["21"] = codeValue;

  codeValue["key"] = "ㅡ";
  codeValue["value"] = "-..";
  toCode["22"] = codeValue;

  codeValue["key"] = "ㅣ";
  codeValue["value"] = "..-";
  toCode["23"] = codeValue;

  codeValue["key"] = "ㅐ";
  codeValue["value"] = "--.-";
  toCode["24"] = codeValue;

  codeValue["key"] = "ㅔ";
  codeValue["value"] = "-.--";
  toCode["25"] = codeValue;

  codeValue["key"] = "1";
  codeValue["value"] = ".----";
  toCode["26"] = codeValue;

  codeValue["key"] = "2";
  codeValue["value"] = "..---";
  toCode["27"] = codeValue;

  codeValue["key"] = "3";
  codeValue["value"] = "...--";
  toCode["28"] = codeValue;

  codeValue["key"] = "4";
  codeValue["value"] = "....-";
  toCode["29"] = codeValue;

  codeValue["key"] = "5";
  codeValue["value"] = ".....";
  toCode["30"] = codeValue;

  codeValue["key"] = "6";
  codeValue["value"] = "-....";
  toCode["31"] = codeValue;

  codeValue["key"] = "7";
  codeValue["value"] = "--...";
  toCode["32"] = codeValue;

  codeValue["key"] = "8";
  codeValue["value"] = "---..";
  toCode["33"] = codeValue;

  codeValue["key"] = "9";
  codeValue["value"] = "----.";
  toCode["34"] = codeValue;

  codeValue["key"] = "0";
  codeValue["value"] = "-----";
  toCode["35"] = codeValue;

  codeValue["key"] = "-";
  codeValue["value"] = "-....-";
  toCode["36"] = codeValue;

  codeValue["key"] = ".";
  codeValue["value"] = ".-.-.-";
  toCode["37"] = codeValue;

  codeValue["key"] = ",";
  codeValue["value"] = "--..--";
  toCode["38"] = codeValue;

  codeValue["key"] = "(";
  codeValue["value"] = "-.--.";
  toCode["39"] = codeValue;

  codeValue["key"] = ")";
  codeValue["value"] = "-.--.-";
  toCode["40"] = codeValue;

  codeValue["key"] = "?";
  codeValue["value"] = "..--..";
  toCode["41"] = codeValue;

  codeValue["key"] = "/";
  codeValue["value"] = "-..-.";
  toCode["42"] = codeValue;

  codeValue["key"] = " ";
  codeValue["value"] = "/";
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

  codeValue["key"] = 0xAC00;
  codeValue["value"] = "ㄱ";
  fromCode["0"] = codeValue;

  codeValue["key"] = 0xAE4C;
  codeValue["value"] = "ㄱㄱ";
  fromCode["1"] = codeValue;

  codeValue["key"] = 0xB098;
  codeValue["value"] = "ㄴ";
  fromCode["2"] = codeValue;

  codeValue["key"] = 0xB2E4;
  codeValue["value"] = "ㄷ";
  fromCode["3"] = codeValue;

  codeValue["key"] = 0xB530;
  codeValue["value"] = "ㄷㄷ";
  fromCode["4"] = codeValue;

  codeValue["key"] = 0xB77C;
  codeValue["value"] = "ㄹ";
  fromCode["5"] = codeValue;

  codeValue["key"] = 0xB9C8;
  codeValue["value"] = "ㅁ";
  fromCode["6"] = codeValue;

  codeValue["key"] = 0xBC14;
  codeValue["value"] = "ㅂ";
  fromCode["7"] = codeValue;

  codeValue["key"] = 0xBE60;
  codeValue["value"] = "ㅂㅂ";
  fromCode["8"] = codeValue;

  codeValue["key"] = 0xC0AC;
  codeValue["value"] = "ㅅ";
  fromCode["9"] = codeValue;

  codeValue["key"] = 0xC2F8;
  codeValue["value"] = "ㅅㅅ";
  fromCode["10"] = codeValue;

  codeValue["key"] = 0xC544;
  codeValue["value"] = "ㅇ";
  fromCode["11"] = codeValue;

  codeValue["key"] = 0xC790;
  codeValue["value"] = "ㅈ";
  fromCode["12"] = codeValue;

  codeValue["key"] = 0xC9DC;
  codeValue["value"] = "ㅈㅈ";
  fromCode["13"] = codeValue;

  codeValue["key"] = 0xCC28;
  codeValue["value"] = "ㅊ";
  fromCode["14"] = codeValue;

  codeValue["key"] = 0xCE74;
  codeValue["value"] = "ㅋ";
  fromCode["15"] = codeValue;

  codeValue["key"] = 0xD0C0;
  codeValue["value"] = "ㅌ";
  fromCode["16"] = codeValue;

  codeValue["key"] = 0xD30C;
  codeValue["value"] = "ㅍ";
  fromCode["17"] = codeValue;

  codeValue["key"] = 0xD558;
  codeValue["value"] = "ㅎ";
  fromCode["18"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "Int";
  toCode["variableType"] = keyValueType;

  codeValue["key"] = "ㄱ";
  codeValue["value"] = 0xAC00;
  toCode["0"] = codeValue;

  codeValue["key"] = "ㄱㄱ";
  codeValue["value"] = 0xAE4C;
  toCode["1"] = codeValue;

  codeValue["key"] = "ㄴ";
  codeValue["value"] = 0xAE4C;
  toCode["2"] = codeValue;

  codeValue["key"] = "ㄷ";
  codeValue["value"] = 0xB2E4;
  toCode["3"] = codeValue;

  codeValue["key"] = "ㄷㄷ";
  codeValue["value"] = 0xB530;
  toCode["4"] = codeValue;

  codeValue["key"] = "ㄹ";
  codeValue["value"] = 0xB77C;
  toCode["5"] = codeValue;

  codeValue["key"] = "ㅁ";
  codeValue["value"] = 0xB9C8;
  toCode["6"] = codeValue;

  codeValue["key"] = "ㅂ";
  codeValue["value"] = 0xBC14;
  toCode["7"] = codeValue;

  codeValue["key"] = "ㅂㅂ";
  codeValue["value"] = 0xBE60;
  toCode["8"] = codeValue;

  codeValue["key"] = "ㅅ";
  codeValue["value"] = 0xC0AC;
  toCode["9"] = codeValue;

  codeValue["key"] = "ㅅㅅ";
  codeValue["value"] = 0xC2F8;
  toCode["10"] = codeValue;

  codeValue["key"] = "ㅇ";
  codeValue["value"] = 0xC544;
  toCode["11"] = codeValue;

  codeValue["key"] = "ㅈ";
  codeValue["value"] = 0xC790;
  toCode["12"] = codeValue;

  codeValue["key"] = "ㅈㅈ";
  codeValue["value"] = 0xC9DC;
  toCode["13"] = codeValue;

  codeValue["key"] = "ㅊ";
  codeValue["value"] = 0xCC28;
  toCode["14"] = codeValue;

  codeValue["key"] = "ㅋ";
  codeValue["value"] = 0xCE74;
  toCode["15"] = codeValue;

  codeValue["key"] = "ㅌ";
  codeValue["value"] = 0xD0C0;
  toCode["16"] = codeValue;

  codeValue["key"] = "ㅍ";
  codeValue["value"] = 0xD30C;
  toCode["17"] = codeValue;

  codeValue["key"] = "ㅎ";
  codeValue["value"] = 0xD558;
  toCode["18"] = codeValue;

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("KoreanConsonantLetterCodeBook.json");
  writer->write(root, &output_file);
}

void makeKoreanMiddleVowerLetterCodeBook()
{
  Json::Value root;
  Json::Value fromCode;
  Json::Value keyValueType;
  Json::Value codeValue;
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "String";
  fromCode["variableType"] = keyValueType;

  codeValue["key"] = 0x00;
  codeValue["value"] = "ㅏ";
  fromCode["1"] = codeValue;

  codeValue["key"] = 0x1C;
  codeValue["value"] = "ㅐ";
  fromCode["2"] = codeValue;
		
  codeValue["key"] = 0x38;
  codeValue["value"] = "ㅑ";
  fromCode["3"] = codeValue;

  codeValue["key"] = 0x54;
  codeValue["value"] = "ㅒ";
  fromCode["3"] = codeValue;

  codeValue["key"] = 0x70;
  codeValue["value"] = "ㅓ";
  fromCode["4"] = codeValue;

  codeValue["key"] = 0x8C;
  codeValue["value"] = "ㅔ";
  fromCode["5"] = codeValue;

  codeValue["key"] = 0xA8;
  codeValue["value"] = "ㅕ";
  fromCode["6"] = codeValue;

  codeValue["key"] = 0xC4;
  codeValue["value"] = "ㅖ";
  fromCode["7"] = codeValue;

  codeValue["key"] = 0xE0;
  codeValue["value"] = "ㅗ";
  fromCode["8"] = codeValue;

  codeValue["key"] = 0xFC;
  codeValue["value"] = "ㅗㅏ";
  fromCode["8"] = codeValue;

  codeValue["key"] = 0x118;
  codeValue["value"] = "ㅗㅐ";
  fromCode["9"] = codeValue;

  codeValue["key"] = 0x134;
  codeValue["value"] = "ㅗㅣ";
  fromCode["10"] = codeValue;

  codeValue["key"] = 0x150;
  codeValue["value"] = "ㅛ";
  fromCode["11"] = codeValue;

  codeValue["key"] = 0x16C;
  codeValue["value"] = "ㅜ";
  fromCode["12"] = codeValue;

  codeValue["key"] = 0x188;
  codeValue["value"] = "ㅜㅓ";
  fromCode["13"] = codeValue;

  codeValue["key"] = 0x1A4;
  codeValue["value"] = "ㅜㅔ";
  fromCode["14"] = codeValue;
  
  codeValue["key"] = 0x1C0;
  codeValue["value"] = "ㅜㅣ";
  fromCode["15"] = codeValue;

  codeValue["key"] = 0x1DC;
  codeValue["value"] = "ㅠ";
  fromCode["16"] = codeValue;

  codeValue["key"] = 0x1F8;
  codeValue["value"] = "ㅡ";
  fromCode["17"] = codeValue;

  codeValue["key"] = 0x214;
  codeValue["value"] = "ㅡㅣ";
  fromCode["18"] = codeValue;

  codeValue["key"] = 0x230;
  codeValue["value"] = "ㅣ";
  fromCode["19"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "String";
  keyValueType["valueVariableType"] = "Int";
  toCode["variableType"] = keyValueType;

  codeValue["key"] = "ㅏ";
  codeValue["value"] = 0x00;
  toCode["1"] = codeValue;

  codeValue["key"] = "ㅐ";
  codeValue["value"] = 0x1C;
  toCode["2"] = codeValue;
		
  codeValue["key"] = "ㅑ";
  codeValue["value"] = 0x38;
  toCode["3"] = codeValue;

  codeValue["key"] = "ㅒ";
  codeValue["value"] = 0x54;
  toCode["3"] = codeValue;

  codeValue["key"] = "ㅓ";
  codeValue["value"] = 0x70;
  toCode["4"] = codeValue;

  codeValue["key"] = "ㅔ";
  codeValue["value"] = 0x8C;
  toCode["5"] = codeValue;

  codeValue["key"] = "ㅕ";
  codeValue["value"] = 0xA8;
  toCode["6"] = codeValue;

  codeValue["key"] = "ㅖ";
  codeValue["value"] = 0xC4;
  toCode["7"] = codeValue;

  codeValue["key"] = "ㅗ";
  codeValue["value"] = 0xE0;
  toCode["8"] = codeValue;

  codeValue["key"] = "ㅗㅏ";
  codeValue["value"] = 0xFC;
  toCode["8"] = codeValue;

  codeValue["key"] = "ㅗㅐ";
  codeValue["value"] = 0x118;
  toCode["9"] = codeValue;

  codeValue["key"] = "ㅗㅣ";
  codeValue["value"] = 0x134;
  toCode["10"] = codeValue;

  codeValue["key"] = "ㅛ";
  codeValue["value"] = 0x150;
  toCode["11"] = codeValue;

  codeValue["key"] = "ㅜ";
  codeValue["value"] = 0x16C;
  toCode["12"] = codeValue;

  codeValue["key"] = "ㅜㅓ";
  codeValue["value"] = 0x188;
  toCode["13"] = codeValue;

  codeValue["key"] = "ㅜㅔ";
  codeValue["value"] = 0x1A4;
  toCode["14"] = codeValue;
  
  codeValue["key"] = "ㅜㅣ";
  codeValue["value"] = 0x1C0;
  toCode["15"] = codeValue;

  codeValue["key"] = "ㅠ";
  codeValue["value"] = 0x1DC;
  toCode["16"] = codeValue;

  codeValue["key"] = "ㅡ";
  codeValue["value"] = 0x1F8;
  toCode["17"] = codeValue;

  codeValue["key"] = "ㅡㅣ";
  codeValue["value"] = 0x214;
  toCode["18"] = codeValue;

  codeValue["key"] = "ㅣ";
  codeValue["value"] = 0x230;
  toCode["19"] = codeValue;

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("KoreanMiddleVowerLetterCodeBook.json");
  writer->write(root, &output_file);
}

void makeKoreanLastConsonantLetterCodeBook()
{
  Json::Value root;
  Json::Value fromCode;
  Json::Value keyValueType;
  Json::Value codeValue;
  keyValueType["keyVariableType"] = "Int";
  keyValueType["valueVariableType"] = "String";
  fromCode["variableType"] = keyValueType;

  codeValue["key"] = 0x0;
  codeValue["value"] = " ";
  fromCode["0"] = codeValue;

  codeValue["key"] = 0x1;
  codeValue["value"] = "ㄱ";
  fromCode["1"] = codeValue;
		
  codeValue["key"] = 0x2;
  codeValue["value"] = "ㄱㄱ";
  fromCode["2"] = codeValue;

  codeValue["key"] = 0x3;
  codeValue["value"] = "ㄱㅅ";
  fromCode["3"] = codeValue;
		
  codeValue["key"] = 0x4;
  codeValue["value"] = "ㄴ";
  fromCode["4"] = codeValue;

  codeValue["key"] = 0x5;
  codeValue["value"] = "ㄴㅈ";
  fromCode["5"] = codeValue;

  codeValue["key"] = 0x6;
  codeValue["value"] = "ㄴㅎ";
  fromCode["6"] = codeValue;

  codeValue["key"] = 0x7;
  codeValue["value"] = "ㄷ";
  fromCode["7"] = codeValue;

  codeValue["key"] = 0x8;
  codeValue["value"] = "ㄹ";
  fromCode["8"] = codeValue;

  codeValue["key"] = 0x9;
  codeValue["value"] = "ㄹㄱ";
  fromCode["9"] = codeValue;

  codeValue["key"] = 0xA;
  codeValue["value"] = "ㄹㅁ";
  fromCode["10"] = codeValue;

  codeValue["key"] = 0xB;
  codeValue["value"] = "ㄹㅂ";
  fromCode["11"] = codeValue;

  codeValue["key"] = 0xC;
  codeValue["value"] = "ㄹㅅ";
  fromCode["12"] = codeValue;

  codeValue["key"] = 0xD;
  codeValue["value"] = "ㄹㅌ";
  fromCode["13"] = codeValue;

  codeValue["key"] = 0xE;
  codeValue["value"] = "ㄹㅍ";
  fromCode["14"] = codeValue;

  codeValue["key"] = 0xF;
  codeValue["value"] = "ㄹㅎ";
  fromCode["15"] = codeValue;

  codeValue["key"] = 0x10;
  codeValue["value"] = "ㅁ";
  fromCode["16"] = codeValue;

  codeValue["key"] = 0x11;
  codeValue["value"] = "ㅂ";
  fromCode["17"] = codeValue;

  codeValue["key"] = 0x12;
  codeValue["value"] = "ㅂㅅ";
  fromCode["18"] = codeValue;

  codeValue["key"] = 0x13;
  codeValue["value"] = "ㅅ";
  fromCode["19"] = codeValue;

  codeValue["key"] = 0x14;
  codeValue["value"] = "ㅅㅅ";
  fromCode["20"] = codeValue;

  codeValue["key"] = 0x15;
  codeValue["value"] = "ㅇ";
  fromCode["21"] = codeValue;

  codeValue["key"] = 0x16;
  codeValue["value"] = "ㅈ";
  fromCode["22"] = codeValue;

  codeValue["key"] = 0x17;
  codeValue["value"] = "ㅊ";
  fromCode["23"] = codeValue;

  codeValue["key"] = 0x18;
  codeValue["value"] = "ㅋ";
  fromCode["24"] = codeValue;

  codeValue["key"] = 0x19;
  codeValue["value"] = "ㅌ";
  fromCode["25"] = codeValue;

  codeValue["key"] = 0x1A;
  codeValue["value"] = "ㅍ";
  fromCode["26"] = codeValue;

  codeValue["key"] = 0x1B;
  codeValue["value"] = "ㅎ";
  fromCode["27"] = codeValue;

  Json::Value toCode;

  keyValueType["keyVariableType"] = "WChar";
  keyValueType["valueVariableType"] = "Int";
  toCode["variableType"] = keyValueType;

  codeValue["key"] = " ";
  codeValue["value"] = 0x0;
  toCode["0"] = codeValue;

  codeValue["key"] = "ㄱ";
  codeValue["value"] = 0x1;
  toCode["1"] = codeValue;
		
  codeValue["key"] = "ㄱㄱ";
  codeValue["value"] = 0x2;
  toCode["2"] = codeValue;

  codeValue["key"] = "ㄱㅅ";
  codeValue["value"] = 0x3;
  toCode["3"] = codeValue;
		
  codeValue["key"] = "ㄴ";
  codeValue["value"] = 0x4;
  toCode["4"] = codeValue;

  codeValue["key"] = "ㄴㅈ";
  codeValue["value"] = 0x5;
  toCode["5"] = codeValue;

  codeValue["key"] = "ㄴㅎ";
  codeValue["value"] = 0x6;
  toCode["6"] = codeValue;

  codeValue["key"] = "ㄷ";
  codeValue["value"] = 0x7;
  toCode["7"] = codeValue;

  codeValue["key"] = "ㄹ";
  codeValue["value"] = 0x8;
  toCode["8"] = codeValue;

  codeValue["key"] = "ㄹㄱ";
  codeValue["value"] = 0x9;
  toCode["9"] = codeValue;

  codeValue["key"] = "ㄹㅁ";
  codeValue["value"] = 0xA;
  toCode["10"] = codeValue;

  codeValue["key"] = "ㄹㅂ";
  codeValue["value"] = 0xB;
  toCode["11"] = codeValue;

  codeValue["key"] = "ㄹㅅ";
  codeValue["value"] = 0xC;
  toCode["12"] = codeValue;

  codeValue["key"] = "ㄹㅌ";
  codeValue["value"] = 0xD;
  toCode["13"] = codeValue;

  codeValue["key"] = "ㄹㅍ";
  codeValue["value"] = 0xE;
  toCode["14"] = codeValue;

  codeValue["key"] = "ㄹㅎ";
  codeValue["value"] = 0xF;
  toCode["15"] = codeValue;

  codeValue["key"] = "ㅁ";
  codeValue["value"] = 0x10;
  toCode["16"] = codeValue;

  codeValue["key"] = "ㅂ";
  codeValue["value"] = 0x11;
  toCode["17"] = codeValue;

  codeValue["key"] = "ㅂㅅ";
  codeValue["value"] = 0x12;
  toCode["18"] = codeValue;

  codeValue["key"] = "ㅅ";
  codeValue["value"] = 0x13;
  toCode["19"] = codeValue;

  codeValue["key"] = "ㅅㅅ";
  codeValue["value"] = 0x14;
  toCode["20"] = codeValue;

  codeValue["key"] = "ㅇ";
  codeValue["value"] = 0x15;
  toCode["21"] = codeValue;

  codeValue["key"] = "ㅈ";
  codeValue["value"] = 0x16;
  toCode["22"] = codeValue;

  codeValue["key"] = "ㅊ";
  codeValue["value"] = 0x17;
  toCode["23"] = codeValue;

  codeValue["key"] = "ㅋ";
  codeValue["value"] = 0x18;
  toCode["24"] = codeValue;

  codeValue["key"] = "ㅌ";
  codeValue["value"] = 0x19;
  toCode["25"] = codeValue;

  codeValue["key"] = "ㅍ";
  codeValue["value"] = 0x1A;
  toCode["26"] = codeValue;

  codeValue["key"] = "ㅎ";
  codeValue["value"] = 0x1B;
  toCode["27"] = codeValue;

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("KoreanLastConsonantLetterCodeBook.json");
  writer->write(root, &output_file);
}

void makeKoreanJaeumLetterCodeBook()
{
  Json::Value root;
  Json::Value fromCode;
  Json::Value keyValueType;
  Json::Value codeValue;
  keyValueType["keyVariableType"] = "String";
  keyValueType["valueVariableType"] = "String";
  fromCode["variableType"] = keyValueType;

  codeValue["key"] = "ㄱ";
  codeValue["value"] = "ㄱ";
  fromCode["0"] = codeValue;

  codeValue["key"] = "ㄲ";
  codeValue["value"] = "ㄱㄱ";
  fromCode["1"] = codeValue;

  codeValue["key"] = "ㄳ";
  codeValue["value"] = "ㄱㅅ";
  fromCode["2"] = codeValue;

  codeValue["key"] = "ㄴ";
  codeValue["value"] = "ㄴ";
  fromCode["3"] = codeValue;

  codeValue["key"] = "ㄵ";
  codeValue["value"] = "ㄴㅈ";
  fromCode["4"] = codeValue;

  codeValue["key"] = "ㄶ";
  codeValue["value"] = "ㄴㅎ";
  fromCode["5"] = codeValue;

  codeValue["key"] = "ㄷ";
  codeValue["value"] = "ㄷ";
  fromCode["6"] = codeValue;

  codeValue["key"] = "ㄸ";
  codeValue["value"] = "ㄷㄷ";
  fromCode["7"] = codeValue;

  codeValue["key"] = "ㄹ";
  codeValue["value"] = "ㄹ";
  fromCode["8"] = codeValue;
  
	codeValue["key"] = "ㄺ";
  codeValue["value"] = "ㄹㄱ";
  fromCode["9"] = codeValue;

  codeValue["key"] = "ㄻ";
  codeValue["value"] = "ㄹㅁ";
  fromCode["10"] = codeValue;

  codeValue["key"] = "ㄼ";
  codeValue["value"] = "ㄹㅂ";
  fromCode["11"] = codeValue;

  codeValue["key"] = "ㄽ";
  codeValue["value"] = "ㄹㅅ";
  fromCode["12"] = codeValue;

  codeValue["key"] = "ㄾ";
  codeValue["value"] = "ㄹㅌ";
  fromCode["13"] = codeValue;

  codeValue["key"] = "ㄿ";
  codeValue["value"] = "ㄹㅍ";
  fromCode["14"] = codeValue;

  codeValue["key"] = "ㅀ";
  codeValue["value"] = "ㄹㅎ";
  fromCode["15"] = codeValue;

  codeValue["key"] = "ㅁ";
  codeValue["value"] = "ㅁ";
  fromCode["16"] = codeValue;

  codeValue["key"] = "ㅂ";
  codeValue["value"] = "ㅂ";
  fromCode["17"] = codeValue;

  codeValue["key"] = "ㅃ";
  codeValue["value"] = "ㅂㅂ";
  fromCode["18"] = codeValue;

  codeValue["key"] = "ㅄ";
  codeValue["value"] = "ㅂㅅ";
  fromCode["19"] = codeValue;

  codeValue["key"] = "ㅅ";
  codeValue["value"] = "ㅅ";
  fromCode["20"] = codeValue;
		
  codeValue["key"] = "ㅆ";
  codeValue["value"] = "ㅅㅅ";
  fromCode["21"] = codeValue;

  codeValue["key"] = "ㅇ";
  codeValue["value"] = "ㅇ";
  fromCode["22"] = codeValue;

  codeValue["key"] = "ㅈ";
  codeValue["value"] = "ㅈ";
  fromCode["23"] = codeValue;

  codeValue["key"] = "ㅉ";
  codeValue["value"] = "ㅈㅈ";
  fromCode["24"] = codeValue;

  codeValue["key"] = "ㅊ";
  codeValue["value"] = "ㅊ";
  fromCode["25"] = codeValue;

  codeValue["key"] = "ㅋ";
  codeValue["value"] = "ㅋ";
  fromCode["26"] = codeValue;

  codeValue["key"] = "ㅌ";
  codeValue["value"] = "ㅌ";
  fromCode["27"] = codeValue;

  codeValue["key"] = "ㅍ";
  codeValue["value"] = "ㅍ";
  fromCode["28"] = codeValue;

  codeValue["key"] = "ㅎ";
  codeValue["value"] = "ㅎ";
  fromCode["29"] = codeValue;
  

  Json::Value toCode;

  keyValueType["keyVariableType"] = "String";
  keyValueType["valueVariableType"] = "String";
  toCode["variableType"] = keyValueType;

  codeValue["key"] = "ㄱ";
  codeValue["value"] = "ㄱ";
  toCode["0"] = codeValue;

  codeValue["key"] = "ㄱㄱ";
  codeValue["value"] = "ㄲ";
  toCode["1"] = codeValue;

  codeValue["key"] = "ㄱㅅ";
  codeValue["value"] = "ㄳ";
  toCode["2"] = codeValue;

  codeValue["key"] = "ㄴ";
  codeValue["value"] = "ㄴ";
  toCode["3"] = codeValue;

  codeValue["key"] = "ㄴㅈ";
  codeValue["value"] = "ㄵ";
  toCode["4"] = codeValue;

  codeValue["key"] = "ㄴㅎ";
  codeValue["value"] = "ㄶ";
  toCode["5"] = codeValue;

  codeValue["key"] = "ㄷ";
  codeValue["value"] = "ㄷ";
  toCode["6"] = codeValue;

  codeValue["key"] = "ㄷㄷ";
  codeValue["value"] = "ㄸ";
  toCode["7"] = codeValue;

  codeValue["key"] = "ㄹ";
  codeValue["value"] = "ㄹ";
  toCode["8"] = codeValue;
  
	codeValue["key"] = "ㄹㄱ";
  codeValue["value"] = "ㄺ";
  toCode["9"] = codeValue;

  codeValue["key"] = "ㄹㅁ";
  codeValue["value"] = "ㄻ";
  toCode["10"] = codeValue;

  codeValue["key"] = "ㄹㅂ";
  codeValue["value"] = "ㄼ";
  toCode["11"] = codeValue;

  codeValue["key"] = "ㄹㅅ";
  codeValue["value"] = "ㄽ";
  toCode["12"] = codeValue;

  codeValue["key"] = "ㄹㅌ";
  codeValue["value"] = "ㄾ";
  toCode["13"] = codeValue;

  codeValue["key"] = "ㄹㅍ";
  codeValue["value"] = "ㄿ";
  toCode["14"] = codeValue;

  codeValue["key"] = "ㄹㅎ";
  codeValue["value"] = "ㅀ";
  toCode["15"] = codeValue;

  codeValue["key"] = "ㅁ";
  codeValue["value"] = "ㅁ";
  toCode["16"] = codeValue;

  codeValue["key"] = "ㅂ";
  codeValue["value"] = "ㅂ";
  toCode["17"] = codeValue;

  codeValue["key"] = "ㅂㅂ";
  codeValue["value"] = "ㅃ";
  toCode["18"] = codeValue;

  codeValue["key"] = "ㅂㅅ";
  codeValue["value"] = "ㅄ";
  toCode["19"] = codeValue;

  codeValue["key"] = "ㅅ";
  codeValue["value"] = "ㅅ";
  toCode["20"] = codeValue;
		
  codeValue["key"] = "ㅅㅅ";
  codeValue["value"] = "ㅆ";
  toCode["21"] = codeValue;

  codeValue["key"] = "ㅇ";
  codeValue["value"] = "ㅇ";
  toCode["22"] = codeValue;

  codeValue["key"] = "ㅈ";
  codeValue["value"] = "ㅈ";
  toCode["23"] = codeValue;

  codeValue["key"] = "ㅈㅈ";
  codeValue["value"] = "ㅉ";
  toCode["24"] = codeValue;

  codeValue["key"] = "ㅊ";
  codeValue["value"] = "ㅊ";
  toCode["25"] = codeValue;

  codeValue["key"] = "ㅋ";
  codeValue["value"] = "ㅋ";
  toCode["26"] = codeValue;

  codeValue["key"] = "ㅌ";
  codeValue["value"] = "ㅌ";
  toCode["27"] = codeValue;

  codeValue["key"] = "ㅍ";
  codeValue["value"] = "ㅍ";
  toCode["28"] = codeValue;

  codeValue["key"] = "ㅎ";
  codeValue["value"] = "ㅎ";
  toCode["29"] = codeValue;

  root["fromCode"] = fromCode;
  root["toCode"] = toCode;

  // cout << root << endl;
  Json::StreamWriterBuilder builder;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream output_file("KoreanLastJaeumLetterCodeBook.json");
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
  makeKoreanMiddleVowerLetterCodeBook();
  makeKoreanJaeumLetterCodeBook();

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
