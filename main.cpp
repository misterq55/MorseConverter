// MorseConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "flutter_interface.h"

int main()
{
  string MorseStr;

  // std::getline(std::cin, MorseStr);

  char* result = native_ConvertToMorseCode((char*)"Test");
  std::cout << result << std::endl;
  delete_allocated(result);

  //std::getline(std::cin, MorseStr);

  //string Result;

  //Result = MorseConverter::Get().ConvertFromMorseCode(MorseStr);
  //// Result = MorseConverter::Get().ConvertToMorseCode(MorseStr);

  //std::cout << Result << std::endl;

  return 0;
}