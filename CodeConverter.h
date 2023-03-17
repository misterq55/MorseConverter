#pragma once

#include <string>

using std::wstring;

class FCodeConverter
{
public:
	enum EInputType
	{
		IT_Engish,
		IT_Korean,
		IT_None,
	};

public:
	virtual wstring ConvertCodeToString(const wstring& InCode) = 0;
	virtual wstring ConvertStringToCode(const wstring& InString) = 0;
	
	void SetInputType(EInputType InInputType) {
		InputType = InInputType;
	}

	EInputType GetInputType() {
		return InputType;
	}

protected:
	EInputType InputType = IT_None;
};

