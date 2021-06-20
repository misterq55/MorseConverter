// MorseConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "MorseConverter.h"

int main()
{
  string MorseStr;

  std::getline(std::cin, MorseStr);

  string Result;

  Result = MorseConverter::Get().ConvertFromMorseCode(MorseStr);
  // Result = MorseConverter::Get().ConvertToMorseCode(MorseStr);

  std::cout << Result << std::endl;
}