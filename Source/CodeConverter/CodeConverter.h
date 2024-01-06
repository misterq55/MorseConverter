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

class FCodeConverter
{
public:
	virtual void Initilize() = 0;
	virtual wstring Encode(const wstring& InString) = 0;
	virtual wstring Decode(const wstring& InCode) = 0;
	
	void SetInputType(EInputType InInputType) {
		InputType = InInputType;
	}

	EInputType GetInputType() {
		return InputType;
	}

protected:
	EInputType InputType = IT_None;
};

