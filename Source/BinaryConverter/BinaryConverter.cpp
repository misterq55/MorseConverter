#include "BinaryConverter.h"
#include <iostream>
using namespace std;

void FBinaryConverter::Initilize()
{
}

wstring FBinaryConverter::Encode(const wstring& InString)
{
	wstring result = L"";
	// result = std::to_wstring(InString.size());
	result = InString;

	for (const wchar_t& wch : result)
	{
		cout << wch << endl;
		// cout << static_cast<int>(wch) << endl;
	}
	return result;
}

wstring FBinaryConverter::Decode(const wstring& InCode)
{
	wstring result = L"";
	return result;
}
