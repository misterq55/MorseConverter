// MorseConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
// #include "FHangulParser.h"
#include "MorseConverter/MorseConverter.h"
// #include "BinaryConverter.h"
#include "jsoncpp/json/json.h"

using namespace std;

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

  ///*wcout << int(L'¤¡') << endl;
  //wcout << int(L'¤¾') << endl;
  //wcout << int(L'¤¿') << endl;
  //wcout << int(L'¤Ó') << endl;*/


  Json::Value root;
  Json::Value data;
  root["JsonTest"] = "name";
  data["try"] = 1;
  root["data"] = data;

	Json::StreamWriterBuilder builder;
	// const std::string json_file = Json::writeString(builder, root);
	// std::cout << json_file << std::endl;
  const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  writer->write(root, &std::cout);

  return EXIT_SUCCESS;
}
