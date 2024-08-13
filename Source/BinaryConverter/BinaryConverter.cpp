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

	wchar_t buffer[100];
	
	for (const wchar_t& wch : InString)
	{
		memset(buffer, 0, 100 * sizeof(wchar_t));
		_itow_s(wch, buffer, 2);

		wstring numberedBuffer(buffer);

		while (numberedBuffer.length() < WORD_SIZE)
		{
			numberedBuffer = wstring(L"0") + numberedBuffer;
		}

		result += numberedBuffer;
	}

	result += L"\0";

	return result;
}

wstring FBinaryConverter::Decode(const wstring& InCode)
{
	const int num = static_cast<int>(InCode.length() / WORD_SIZE);

	vector<wstring> parsedCode;

	for (int i = 0; i < num; i++)
	{
		parsedCode.emplace_back(InCode.substr(i * WORD_SIZE, WORD_SIZE));
	}

	wstring result = L"";

	for (const wstring& parsed : parsedCode)
	{
		int number = 0;
		const int len = static_cast<int>(parsed.length());

		for (int i = 0; i < len; i++)
		{
			const int powered = static_cast<int>(pow(2, i));
			const wchar_t& wch = parsed[len - i - 1];
			const int num = wch == 0 ? wch : wch - L'0';
			number += num * powered;
		}

		result += number;
	}
	
	return result;
}
