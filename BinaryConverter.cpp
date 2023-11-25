#include "BinaryConverter.h"
#include <iostream>
using namespace std;

wstring FBinaryConverter::ConvertCodeToString(const wstring& InCode)
{
	wstring result = L"";
	return result;
}

wstring FBinaryConverter::ConvertStringToCode(const wstring& InString)
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
