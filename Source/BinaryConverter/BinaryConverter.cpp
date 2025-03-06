#include "BinaryConverter.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void FBinaryConverter::Initilize()
{
}

wstring FBinaryConverter::Encode(const wstring& InString)
{
	wstring result = L"";

	for (const wchar_t& wch : InString)
	{
		wstring binaryString;
		for (int i = 0; i < sizeof(wchar_t) * 8; i++)  // wchar_t의 비트 수 (16 또는 32비트)
		{
			binaryString = ((wch >> i) & 1 ? L"1" : L"0") + binaryString;
		}
		result += binaryString;
	}

	return result;
}


wstring FBinaryConverter::Decode(const wstring& InCode)
{
	wstring result = L"";
	int bitSize = sizeof(wchar_t) * 8;

	for (size_t i = 0; i < InCode.length(); i += bitSize)
	{
		wstring binarySegment = InCode.substr(i, bitSize);
		wchar_t character = 0;

		for (size_t j = 0; j < bitSize; j++)
		{
			character = (character << 1) | (binarySegment[j] - L'0');
		}

		result += character;
	}

	return result;
}