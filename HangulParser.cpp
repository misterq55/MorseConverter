#include "HangulParser.h"

FHangulParser::FHangulParser()
{
	FirstConsonantCodeToLetter = {
		{0xAC00, L"ㄱ"},
		{0xAE4C, L"ㄱㄱ"},
		{0xB098, L"ㄴ"},
		{0xB2E4, L"ㄷ"},
		{0xB530, L"ㄷㄷ"},
		{0xB77C, L"ㄹ"},
		{0xB9C8, L"ㅁ"},
		{0xBC14, L"ㅂ"},
		{0xBE60, L"ㅂㅂ"},
		{0xC0AC, L"ㅅ"},
		{0xC2F8, L"ㅅㅅ"},
		{0xC544, L"ㅇ"},
		{0xC790, L"ㅈ"},
		{0xC9DC, L"ㅈㅈ"},
		{0xCC28, L"ㅊ"},
		{0xCE74, L"ㅋ"},
		{0xD0C0, L"ㅌ"},
		{0xD30C, L"ㅍ"},
		{0xD558, L"ㅎ"},
	};

	MiddleVowerCodeToLetter = {
		{0x00, L"ㅏ"},
		{0x1C, L"ㅐ"},
		{0x38, L"ㅑ"},
		{0x54, L"ㅒ"},
		{0x70, L"ㅓ"},
		{0x8C, L"ㅔ"},
		{0xA8, L"ㅕ"},
		{0xC4, L"ㅖ"},
		{0xE0, L"ㅗ"},
		{0xFC, L"ㅘ"},
		{0x118, L"ㅙ"},
		{0x134, L"ㅚ"},
		{0x150, L"ㅛ"},
		{0x16C, L"ㅜ"},
		{0x188, L"ㅝ"},
		{0x1A4, L"ㅞ"},
		{0x1C0, L"ㅟ"},
		{0x1DC, L"ㅠ"},
		{0x1F8, L"ㅡ"},
		{0x214, L"ㅢ"},
		{0x230, L"ㅣ"},
	};

	LastConsonantCodeToLetter = {
		{0x1, L"ㄱ"},
		{0x2, L"ㄱㄱ"},
		{0x3, L"ㄳ"},
		{0x4, L"ㄴ"},
		{0x5, L"ㄴㅈ"},
		{0x6, L"ㄴㅎ"},
		{0x7, L"ㄷ"},
		{0x8, L"ㄹ"},
		{0x9, L"ㄹㄱ"},
		{0xA, L"ㄹㅁ"},
		{0xB, L"ㄹㅂ"},
		{0xC, L"ㄹㅅ"},
		{0xD, L"ㄹㅌ"},
		{0xE, L"ㄹㅍ"},
		{0xF, L"ㄹㅎ"},
		{0x10, L"ㅁ"},
		{0x11, L"ㅂ"},
		{0x12, L"ㅂㅅ"},
		{0x13, L"ㅅ"},
		{0x14, L"ㅅㅅ"},
		{0x15, L"ㅇ"},
		{0x16, L"ㅈ"},
		{0x17, L"ㅊ"},
		{0x18, L"ㅋ"},
		{0x19, L"ㅌ"},
		{0x1A, L"ㅍ"},
		{0x1B, L"ㅎ"},
	};
}

wstring FHangulParser::ConvertCodeToString(const wstring& InCode)
{
	return L"내용이 없습니다.";
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
