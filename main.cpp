// MorseConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
// #include "FHangulParser.h"
#include "FMorseConverter.h"

using namespace std;

int main()
{
  wcin.imbue(locale("korean"));
  wcout.imbue(locale("korean"));

  // FCodeConverter *CodeInverter = new FHangulParser();
  FCodeConverter* CodeInverter = new FMorseConverter();
  // CodeInverter->SetInputType(FCodeConverter::EInputType::IT_Engish);
  CodeInverter->SetInputType(FCodeConverter::EInputType::IT_Korean);

  wstring str;

  getline(wcin, str);

  // wstring Code = CodeInverter->ConvertStringToCode(str);
  // wstring ConvertedString = CodeInverter->ConvertCodeToString(Code);
  wstring ConvertedString = CodeInverter->ConvertCodeToString(str);

  // wcout << Code << endl;
  wcout << ConvertedString << endl;

  delete CodeInverter;

  /*wcout << int(L'¤¡') << endl;
  wcout << int(L'¤¾') << endl;
  wcout << int(L'¤¿') << endl;
  wcout << int(L'¤Ó') << endl;*/
}
