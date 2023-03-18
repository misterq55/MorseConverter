#include "MorseConverter.h"

FMorseConverter::FMorseConverter()
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

	FirstConsonantLetterToCode = {
		{L"��", 0xAC00},
		{L"����", 0xAE4C},
		{L"��", 0xB098},
		{L"��", 0xB2E4},
		{L"����", 0xB530},
		{L"��", 0xB77C},
		{L"��", 0xB9C8},
		{L"��", 0xBC14},
		{L"����", 0xBE60},
		{L"��", 0xC0AC},
		{L"����", 0xC2F8},
		{L"��", 0xC544},
		{L"��", 0xC790},
		{L"����", 0xC9DC},
		{L"��", 0xCC28},
		{L"��", 0xCE74},
		{L"��", 0xD0C0},
		{L"��", 0xD30C},
		{L"��", 0xD558},
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
		{0xFC, L"�Ǥ�"},
		{0x118, L"�Ǥ�"},
		{0x134, L"�Ǥ�"},
		{0x150, L"��"},
		{0x16C, L"��"},
		{0x188, L"�̤�"},
		{0x1A4, L"�̤�"},
		{0x1C0, L"�̤�"},
		{0x1DC, L"��"},
		{0x1F8, L"��"},
		{0x214, L"�Ѥ�"},
		{0x230, L"��"},
	};

	MiddleVowerLetterToCode = {
		{L"��", 0x00},
		{L"��", 0x1C},
		{L"��", 0x38},
		{L"��", 0x54},
		{L"��", 0x70},
		{L"��", 0x8C},
		{L"��", 0xA8},
		{L"��", 0xC4},
		{L"��", 0xE0},
		{L"�Ǥ�", 0xFC},
		{L"�Ǥ�", 0x118},
		{L"�Ǥ�", 0x134},
		{L"��", 0x150},
		{L"��", 0x16C},
		{L"�̤�", 0x188},
		{L"�̤�", 0x1A4},
		{L"�̤�", 0x1C0},
		{L"��", 0x1DC},
		{L"��", 0x1F8},
		{L"�Ѥ�", 0x214},
		{L"��", 0x230},
	};

	LastConsonantCodeToLetter = {
		{0x1, L"��"},
		{0x2, L"����"},
		{0x3, L"����"},
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

	LastConsonantLetterToCode = {
		{L"��", 0x1},
		{L"����", 0x2},
		{L"����", 0x3},
		{L"��", 0x4},
		{L"����", 0x5},
		{L"����", 0x6},
		{L"��", 0x7},
		{L"��", 0x8},
		{L"����", 0x9},
		{L"����", 0xA},
		{L"����", 0xB},
		{L"����", 0xC},
		{L"����", 0xD},
		{L"����", 0xE},
		{L"����", 0xF},
		{L"��", 0x10},
		{L"��", 0x11},
		{L"����", 0x12},
		{L"��", 0x13},
		{L"����", 0x14},
		{L"��", 0x15},
		{L"��", 0x16},
		{L"��", 0x17},
		{L"��", 0x18},
		{L"��", 0x19},
		{L"��", 0x1A},
		{L"��", 0x1B},
	};

	FromMorseToEngStringDictionary = {
		{7, L'A'}, // 1 2
		{41, L'B'}, // 2 1 1 1
		{50, L'C'}, // 2 1 2 1
		{14, L'D'}, // 2 1 1
		{1, L'E'}, // 1
		{49, L'F'}, // 1 1 2 1
		{17, L'G'}, // 2 2 1
		{40, L'H'}, // 1 1 1 1
		{4, L'I'}, // 1 1
		{79, L'J'}, // 1 2 2 2
		{23, L'K'}, // 2 1 2
		{43, L'L'}, // 1 2 1 1
		{8, L'M'}, // 2 2
		{5, L'N'}, // 2 1
		{26, L'O'}, // 2 2 2
		{52, L'P'}, // 1 2 2 1
		{71, L'Q'}, // 2 2 1 2
		{16, L'R'}, // 1 2 1
		{13, L'S'}, // 1 1 1
		{2, L'T'}, // 2
		{22, L'U'}, // 1 1 2
		{67, L'V'}, // 1 1 1 2
		{25, L'W'}, // 1 2 2
		{68, L'X'}, // 2 1 1 2
		{77, L'Y'}, // 2 1 2 2
		{44, L'Z'}, // 2 2 1 1

		{241, L'1'}, // 1 2 2 2 2
		{238, L'2'}, // 1 1 2 2 2
		{229, L'3'}, // 1 1 1 2 2
		{202, L'4'}, // 1 1 1 1 2
		{121, L'5'}, // 1 1 1 1 1
		{122, L'6'}, // 2 1 1 1 1
		{125, L'7'}, // 2 2 1 1 1
		{134, L'8'}, // 2 2 2 1 1
		{161, L'9'}, // 2 2 2 2 1
		{242, L'0'}, // 2 2 2 2 2
	};

	EngStringToMorseDictionary = {
		{L'A', L".-"},
		{L'B', L"-..."},
		{L'C', L"-.-."},
		{L'D', L"-.."},
		{L'E', L"."},

		{L'F', L"..-."},
		{L'G', L"--."},
		{L'H', L"...."},
		{L'I', L".---"},
		{L'J', L".---"},

		{L'K', L"-.-"},
		{L'L', L".-.."},
		{L'M', L"--"},
		{L'N', L"-."},
		{L'O', L"---"},

		{L'P', L".--."},
		{L'Q', L"--.-"},
		{L'R', L".-."},
		{L'S', L"..."},
		{L'T', L"-"},

		{L'U', L"..-"},
		{L'V', L"...-"},
		{L'W', L".--"},
		{L'X', L"-..-"},
		{L'Y', L"-.--"},
		{L'Z', L"--.."},

		{L'1', L".----"},
		{L'2', L"..---"},
		{L'3', L"...--"},
		{L'4', L"....-"},
		{L'5', L"....."},

		{L'6', L"-...."},
		{L'7', L"--..."},
		{L'8', L"---.."},
		{L'9', L"----."},
		{L'0', L"-----"},

		{L' ', L"/"},
	};

	FromMorseToKoreanStringDictionary = {
		{43, L'��'}, // �� 1 2 1 1
		{49, L'��'}, // �� 1 1 2 1
		{41, L'��'}, // �� 2 1 1 1
		{67, L'��'}, // �� 1 1 1 2
		{8, L'��'}, // �� 2 2
		{25, L'��'}, // �� 1 2 2
		{17, L'��'}, // �� 2 2 1
		{23, L'��'}, // �� 2 1 2
		{52, L'��'}, // �� 1 2 2 1
		{50, L'��'}, // �� 2 1 2 1
		{68, L'��'}, // �� 2 1 1 2
		{44, L'��'}, // �� 2 2 1 1
		{26, L'��'}, // �� 2 2 2
		{79, L'��'}, // �� 1 2 2 2

		{1, L'��'}, // �� 1
		{4, L'��'}, // �� 1 1
		{2, L'��'}, // �� 2
		{13, L'��'}, // �� 1 1 1
		{7, L'��'}, // �� 1 2
		{5, L'��'}, // �� 2 1
		{40, L'��'}, // �� 1 1 1 1
		{16, L'��'}, // �� 1 2 1
		{14, L'��'}, // �� 2 1 1
		{22, L'��'}, // �� 1 1 2
		{71, L'��'}, // �� 2 2 1 2
		{77, L'��'}, // �� 2 1 2 2

		{241, L'1'}, // 1 2 2 2 2
		{238, L'2'}, // 1 1 2 2 2
		{229, L'3'}, // 1 1 1 2 2
		{202, L'4'}, // 1 1 1 1 2
		{121, L'5'}, // 1 1 1 1 1
		{122, L'6'}, // 2 1 1 1 1
		{125, L'7'}, // 2 2 1 1 1
		{134, L'8'}, // 2 2 2 1 1
		{161, L'9'}, // 2 2 2 2 1
		{242, L'0'}, // 2 2 2 2 2

		// - 2 1 1 1 1 2
		// . 1 2 1 2 1 2
		// , 2 2 1 1 2 2
		// ( 2 1 2 2 1
		// ) 2 1 2 2 1 2
		// ? 1 1 2 2 1 1
		// / 2 1 1 2 1
	};

	KoreanStringToMorseDictionary = {
		{L'��', L".-.."},
		{L'��', L"..-."},
		{L'��', L"-..."},
		{L'��', L"...-"},
		{L'��', L"--"},
		{L'��', L".--"},
		{L'��', L"--."},
		{L'��', L"-.-"},
		{L'��', L".--."},
		{L'��', L"-.-."},
		{L'��', L"-..-"},
		{L'��', L"--.."},
		{L'��', L"---"},
		{L'��', L".---"},

		{L'��', L"."},
		{L'��', L".."},
		{L'��', L"-"},
		{L'��', L"..."},
		{L'��', L".-"},
		{L'��', L"-."},
		{L'��', L"...."},
		{L'��', L".-."},
		{L'��', L"-.."},
		{L'��', L"..-"},
		{L'��', L"--.-"},
		{L'��', L"-.--"},

		{L'1', L".----"},

		{L'1', L".----"},
		{L'2', L"..---"},
		{L'3', L"...--"},
		{L'4', L"....-"},
		{L'5', L"....."},

		{L'6', L"-...."},
		{L'7', L"--..."},
		{L'8', L"---.."},
		{L'9', L"----."},
		{L'0', L"-----"},

		{L' ', L"/"},
	};
}

FMorseConverter::~FMorseConverter()
{
	FirstConsonantCodeToLetter.clear();
	MiddleVowerCodeToLetter.clear();
	LastConsonantCodeToLetter.clear();
	
	FirstConsonantLetterToCode.clear();
	MiddleVowerLetterToCode.clear();
	LastConsonantLetterToCode.clear();
}

wstring FMorseConverter::ConvertCodeToString(const wstring& InCode)
{
	if (InputType == IT_None)
		return L"�Է� �� �������� �ʾҽ��ϴ�.";

	wstring ResultString;

	if (InputType == IT_Engish)
	{
		ResultString = BlankConvertCodeToString(InCode, L"   ", L"       ");
		ResultString = InnerConvertCodeToString(ResultString, FromMorseToEngStringDictionary);
	}

	if (InputType == IT_Korean)
	{
		ResultString = BlankConvertCodeToString(InCode, L"     ", L"       ");
		ResultString = InnerConvertCodeToString(ResultString, FromMorseToKoreanStringDictionary);
		ResultString = HangulStringfy(ResultString);
	}

	return ResultString;
}

wstring FMorseConverter::ConvertStringToCode(const wstring& InString)
{
	wstring GivenString = InString;
	wstring ResultCode;

	int EngCount = 0;
	int KoreanCount = 0;

	for (unsigned int i = 0; i < GivenString.size(); i++)
	{
		if (L'A' <= GivenString[i] && L'Z' >= GivenString[i])
			EngCount++;
		else if (L'a' <= GivenString[i] && L'z' >= GivenString[i])
		{
			GivenString[i] -= ' ';
			EngCount++;
		}

		if (0xAC00 <= GivenString[i] && 0xD7A3 >= GivenString[i])
			KoreanCount++;

		if (EngCount && KoreanCount)
			return L"�ΰ��� �̻��� �� �����Ǿ����ϴ�.";
	}

	if (EngCount && !KoreanCount)
	{
		ResultCode = InnerConvertStringToCode(GivenString, EngStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"   ", L"       ");
	}

	if (!EngCount && KoreanCount)
	{
		ResultCode = InnerConvertStringToCode(HangulParser(GivenString), KoreanStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"     ", L"       ");
	}

	return ResultCode;
}

wstring FMorseConverter::HangulParser(wstring InString)
{
	wstring Result;

	for (unsigned int i = 0; i < InString.size(); i++)
	{
		if (InString[i] == L' ')
		{
			Result += L' ';
			continue;
		}

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

wstring FMorseConverter::HangulStringfy(wstring InParsedHangulStr)
{
	wstring StringfiedResult;

	unsigned int Index = 0;

	wstring FirstConsonantLetter;
	wstring MiddleVowerLetter;
	wstring LastConsonantLetter;

	// while (Index < InParsedHangulStr.size())
	{
		while (InParsedHangulStr[Index] >= L'��' && InParsedHangulStr[Index] <= L'��')
			FirstConsonantLetter += InParsedHangulStr[Index++];

		int FirstConsonantValue = FirstConsonantLetterToCode[FirstConsonantLetter];

		while (InParsedHangulStr[Index] >= L'��' && InParsedHangulStr[Index] <= L'��')
			MiddleVowerLetter += InParsedHangulStr[Index++];

		int MiddleVowerValue = MiddleVowerLetterToCode[MiddleVowerLetter];

		while (InParsedHangulStr[Index] >= L'��' && InParsedHangulStr[Index] <= L'��')
			LastConsonantLetter += InParsedHangulStr[Index++];

		int LastConsonantValue = LastConsonantLetterToCode[LastConsonantLetter];

		int Result = FirstConsonantValue + MiddleVowerValue + LastConsonantValue;

		StringfiedResult += Result;
	}
	// StringfiedResult = InParsedHangulStr;

	return StringfiedResult;
}

wstring FMorseConverter::InnerConvertCodeToString(wstring InCode, const FromMorseDirctionary& InToStringDictionary)
{
	wstring GivenCode = InCode;
	wstring ConvertedString;

	int wordIndex = 0;
	int wordValue = 0;

	for (unsigned int i = 0; i < GivenCode.size(); i++)
	{
		int value = -1;

		if (GivenCode.at(i) == L'.')
			value = 1;
		else if (GivenCode.at(i) == L'-')
			value = 2;
		else // ' ' or '/'
		{
			ConvertedString += InToStringDictionary.at(wordValue);
			if (GivenCode.at(i) == L'/')
				ConvertedString += L' ';
			wordIndex = 0;
			wordValue = 0;

			continue;
		}

		wordValue += value * (int)(pow(3, wordIndex++));
	}

	return ConvertedString;
}

wstring FMorseConverter::InnerConvertStringToCode(wstring InString, const ToMorseDictionary& InToCodeDictionary)
{
	wstring ConvertedResult;

	ConvertedResult += InToCodeDictionary.at(InString[0]);

	for (unsigned int i = 1; i < InString.size(); i++)
	{
		wstring ContertedCode = InToCodeDictionary.at(InString[i]);
		
		if (ContertedCode != L"/" && ConvertedResult.back() != L'/')
		{
			ConvertedResult += L' ';
		}

		ConvertedResult += ContertedCode;
	}

	return ConvertedResult;
}

wstring FMorseConverter::BlankConvertCodeToString(wstring InCode, const wstring& LetterInterval, const wstring& WordInterval)
{
	wstring BlankConvertedString;
	
	size_t LetterIntervalSize = LetterInterval.size();
	size_t WordIntervalSize = WordInterval.size();

	int BlankCounter = 0;

	for (unsigned int i = 0; i < InCode.size();)
	{
		if (InCode[i] == L' ')
		{
			BlankCounter = i;

			int BlankInterval = 0;

			while (InCode[BlankCounter] == L' ')
			{
				BlankInterval = BlankCounter - i;
				BlankCounter++;
			}

			if (BlankInterval == LetterIntervalSize - 1)
				BlankConvertedString += L' ';
			else if (BlankInterval == WordIntervalSize - 1)
				BlankConvertedString += L'/';

			i = BlankCounter;
		}
		else
			BlankConvertedString += InCode[i++];
	}

	BlankConvertedString += L' ';

	return BlankConvertedString;
}

wstring FMorseConverter::BlankConvertStringToCode(wstring InString, const wstring& LetterInterval, const wstring& WordInterval)
{
	wstring BlankConvertedCode;

	BlankConvertedCode += InString[0];

	for (unsigned int i = 1; i < InString.size(); i++)
	{
		if (InString[i] == L' ')
		{
			BlankConvertedCode += LetterInterval;
		}
		else if (InString[i] == L'/')
		{
			BlankConvertedCode += WordInterval;
		}
		else
		{
			if (BlankConvertedCode.back() != L' ')
				BlankConvertedCode += L" ";
			BlankConvertedCode += InString[i];
		}
	}

	return BlankConvertedCode;
}
