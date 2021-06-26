#include <string>
#include <vector>
#include "MorseConverter.h"

extern "C" const char* native_ConvertFromMorseCode(char* MorseCharArr)
{
	string MorseStr = MorseConverter::Get().ConvertFromMorseCode(string(MorseCharArr));
	std::vector<char> writable(MorseStr.begin(), MorseStr.end());

	return &writable[0];
}

extern "C" const char* native_ConvertToMorseCode(char* MorseCharArr)
{
	string MorseStr = MorseConverter::Get().ConvertToMorseCode(string(MorseCharArr));
	std::vector<char> writable(MorseStr.begin(), MorseStr.end());

	return &writable[0];
}