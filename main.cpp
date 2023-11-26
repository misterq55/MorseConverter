// MorseConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
// #include "FHangulParser.h"
#include "MorseConverter.h"
// #include "BinaryConverter.h"

using namespace std;

int main()
{
  wcin.imbue(locale("korean"));
  wcout.imbue(locale("korean"));

  // FCodeConverter *CodeConverter = new FHangulParser();
  FCodeConverter* CodeConverter = new FMorseConverter();
  CodeConverter->Initilize();
  // CodeInverter->SetInputType(FCodeConverter::EInputType::IT_Engish);
  CodeConverter->SetInputType(EInputType::IT_Korean);

  // FCodeConverter* CodeConverter = new FBinaryConverter();

  wstring str;

  getline(wcin, str);

  wstring Code = CodeConverter->Encode(str);
  wstring ConvertedString = CodeConverter->Decode(Code);
  // wstring ConvertedString = CodeInverter->Decode(str);

  wcout << Code << endl;
  wcout << ConvertedString << endl;

  delete CodeConverter;

  /*wcout << int(L'¤¡') << endl;
  wcout << int(L'¤¾') << endl;
  wcout << int(L'¤¿') << endl;
  wcout << int(L'¤Ó') << endl;*/
}
