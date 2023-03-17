#include <string>
#include <vector>

// #include <iostream>
#include "MorseConverter.h"

extern "C" char* native_ConvertFromMorseCode(char* MorseCharArr)
{
	string MorseStr = MorseConverter::Get().ConvertFromMorseCode(string(MorseCharArr));
	char* result = new char[MorseStr.size()];
	memcpy(result, MorseStr.c_str(), MorseStr.size());
	result[MorseStr.size() - 1] = '\0';

	return result;
}

extern "C" char* native_ConvertToMorseCode(char* MorseCharArr)
{
	string MorseStr = MorseConverter::Get().ConvertToMorseCode(string(MorseCharArr));
	char* result = new char[MorseStr.size()];
	memcpy(result, MorseStr.c_str(), MorseStr.size());
	result[MorseStr.size() - 1] = '\0';

	return result;
}

extern "C" const void delete_allocated(char* MorseCharArr)
{
	delete[] MorseCharArr;
}