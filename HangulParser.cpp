#include "HangulParser.h"

FHangulParser::FHangulParser()
{
	FirstConsonantCodeToLetter = {
		{0xAC00, L"��"},
		{0xAE4C, L"����"},
		{0xB098, L"��"},
		{0xB2E4, L"��"},
		{0xB530, L"����"},
		{0xB77C, L"��"},
		{0xB9C8, L"��"},
		{0xBC14, L"��"},
		{0xBE60, L"����"},
		{0xC0AC, L"��"},
		{0xC2F8, L"����"},
		{0xC544, L"��"},
		{0xC790, L"��"},
		{0xC9DC, L"����"},
		{0xCC28, L"��"},
		{0xCE74, L"��"},
		{0xD0C0, L"��"},
		{0xD30C, L"��"},
		{0xD558, L"��"},
	};

	MiddleVowerCodeToLetter = {
		{0x00, L"��"},
		{0x1C, L"��"},
		{0x38, L"��"},
		{0x54, L"��"},
		{0x70, L"��"},
		{0x8C, L"��"},
		{0xA8, L"��"},
		{0xC4, L"��"},
		{0xE0, L"��"},
		{0xFC, L"��"},
		{0x118, L"��"},
		{0x134, L"��"},
		{0x150, L"��"},
		{0x16C, L"��"},
		{0x188, L"��"},
		{0x1A4, L"��"},
		{0x1C0, L"��"},
		{0x1DC, L"��"},
		{0x1F8, L"��"},
		{0x214, L"��"},
		{0x230, L"��"},
	};

	LastConsonantCodeToLetter = {
		{0x1, L"��"},
		{0x2, L"����"},
		{0x3, L"��"},
		{0x4, L"��"},
		{0x5, L"����"},
		{0x6, L"����"},
		{0x7, L"��"},
		{0x8, L"��"},
		{0x9, L"����"},
		{0xA, L"����"},
		{0xB, L"����"},
		{0xC, L"����"},
		{0xD, L"����"},
		{0xE, L"����"},
		{0xF, L"����"},
		{0x10, L"��"},
		{0x11, L"��"},
		{0x12, L"����"},
		{0x13, L"��"},
		{0x14, L"����"},
		{0x15, L"��"},
		{0x16, L"��"},
		{0x17, L"��"},
		{0x18, L"��"},
		{0x19, L"��"},
		{0x1A, L"��"},
		{0x1B, L"��"},
	};
}

wstring FHangulParser::ConvertCodeToString(const wstring& InCode)
{
	return L"������ �����ϴ�.";
}

wstring FHangulParser::ConvertStringToCode(const wstring& InString)
{
	wstring Result;

	for (int i = 0; i < InString.size(); i++)
	{
		int StartNumber = 0xAC00;
		int Divider = 0x24C;
		int ConvertedNum = int(InString[i]);
		int PureNum = ConvertedNum - StartNumber;
		int Quotient = PureNum / Divider;
		int Range = Quotient * Divider + StartNumber;
		Result += FirstConsonantCodeToLetter[Range];

		StartNumber = Range;
		Divider = 0x1C;
		ConvertedNum = int(InString[i]);
		PureNum = ConvertedNum - StartNumber;
		Quotient = PureNum / Divider;
		int Ramnant = PureNum % Divider;
		Range = Quotient * Divider;
		Result += MiddleVowerCodeToLetter[Range];
		Result += LastConsonantCodeToLetter[Ramnant];
	}

	return Result;
}
