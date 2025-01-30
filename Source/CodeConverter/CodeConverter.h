#pragma once

#include <string>
#include <map>

using std::map;
using std::wstring;
using std::string;

enum EInputType
{
	IT_Engish,
	IT_Korean,
	IT_None,
};

class ICodeConverter
{
public:
	virtual void Initilize() = 0;
	virtual wstring Encode(const wstring& InString) = 0;
	virtual wstring Decode(const wstring& InCode) = 0;

	ICodeConverter() {}
	virtual ~ICodeConverter() {}

//protected:
//	wstring removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);
//	wstring addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval);
};

