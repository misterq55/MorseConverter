#include "MorseConverter.h"

FMorseConverter::FMorseConverter()
{
	FirstConsonantCodeToLetter = new KoreanCodeToLetterDictionary({
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
	});

	MiddleVowerCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L"��"},
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
	});

	LastConsonantCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L""},
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
	});

	JaeumOnlyCodeToLetter = new KoreanCodeToLetterDictionary({
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"��"},
		{L'��', L"����"},
		{L'��', L"��"},
		{L'��', L"��"},
		{L'��', L"��"},
		{L'��', L"��"},
		{L'��', L"��"},
	});

	FirstConsonantLetterToCode = new KoreanLetterToCodeDictionary({
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
	});

	MiddleVowerLetterToCode = new KoreanLetterToCodeDictionary({
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
	});

	LastConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"", 0x0},
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
	});

	JaeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"��", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"����", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"����", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
	});

	MoeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"�Ǥ�", L'��'},
		{L"�Ǥ�", L'��'},
		{L"�Ǥ�", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"�̤�", L'��'},
		{L"�̤�", L'��'},
		{L"�̤�", L'��'},
		{L"��", L'��'},
		{L"��", L'��'},
		{L"�Ѥ�", L'��'},
		{L"��", L'��'},
		});

	FromMorseToEngStringDictionary = new FromMorseDirctionary({
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

		{242, L'-'}, // 2 1 1 1 1 2
		{637, L'.'}, // 1 2 1 2 1 2
		{692, L','}, // 2 2 1 1 2 2
		{158, L'('}, // 2 1 2 2 1
		{644, L')'}, // 2 1 2 2 1 2
		{400, L'?'}, // 1 1 2 2 1 1
		{149, L'/'}, // 2 1 1 2 1
	});

	EngStringToMorseDictionary = new ToMorseDictionary({
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

		{L'-', L"-....-"},
		{L'.', L".-.-.-"},
		{L',', L"--..--"},
		{L'(', L"-.--."},
		{L')', L"-.--.-"},
		{L'?', L"..--.."},
		{L'/', L"-..-."},

		{L' ', L"/"},
	});

	FromMorseToKoreanStringDictionary = new FromMorseDirctionary({
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

		{242, L'-'}, // 2 1 1 1 1 2
		{637, L'.'}, // 1 2 1 2 1 2
		{692, L','}, // 2 2 1 1 2 2
		{158, L'('}, // 2 1 2 2 1
		{644, L')'}, // 2 1 2 2 1 2
		{400, L'?'}, // 1 1 2 2 1 1
		{149, L'/'}, // 2 1 1 2 1
	});

	KoreanStringToMorseDictionary = new ToMorseDictionary({
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
		{L'2', L"..---"},
		{L'3', L"...--"},
		{L'4', L"....-"},
		{L'5', L"....."},

		{L'6', L"-...."},
		{L'7', L"--..."},
		{L'8', L"---.."},
		{L'9', L"----."},
		{L'0', L"-----"},

		{L'-', L"-....-"},
		{L'.', L".-.-.-"},
		{L',', L"--..--"},
		{L'(', L"-.--."},
		{L')', L"-.--.-"},
		{L'?', L"..--.."},
		{L'/', L"-..-."},

		{L' ', L"/"},
	});
}

FMorseConverter::~FMorseConverter()
{
	delete FirstConsonantCodeToLetter;
	delete MiddleVowerCodeToLetter;
	delete LastConsonantCodeToLetter;

	delete JaeumOnlyCodeToLetter;

	delete FirstConsonantLetterToCode;
	delete MiddleVowerLetterToCode;
	delete LastConsonantLetterToCode;

	delete JaeumOnlyLetterCode;
	delete MoeumOnlyLetterCode;

	delete FromMorseToEngStringDictionary;
	delete FromMorseToKoreanStringDictionary;

	delete EngStringToMorseDictionary;
	delete KoreanStringToMorseDictionary;
}

wstring FMorseConverter::ConvertCodeToString(const wstring& InCode)
{
	if (InputType == IT_None)
		return L"�Է� �� �������� �ʾҽ��ϴ�.";

	wstring ResultString;
	wstring GivenCode = InCode;
	
	if (GivenCode.back() != L'\0')
		GivenCode += L'\0';

	if (InputType == IT_Engish)
	{
		ResultString = BlankConvertCodeToString(GivenCode, L"   ", L"", L"       ");
		ResultString = InnerConvertCodeToString(ResultString, *FromMorseToEngStringDictionary);
	}

	if (InputType == IT_Korean)
	{
		ResultString = BlankConvertCodeToString(GivenCode, L"   ", L"     ", L"       ");
		ResultString = InnerConvertCodeToString(ResultString, *FromMorseToKoreanStringDictionary);
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

		if ((L'��' <= GivenString[i] && L'�R' >= GivenString[i]) ||
			(L'��' <= GivenString[i] && L'��' >= GivenString[i]) ||
			(L'��' <= GivenString[i] && L'��' >= GivenString[i]))
			KoreanCount++;

		if (EngCount && KoreanCount)
			return L"�ΰ��� �̻��� �� �����Ǿ����ϴ�.";
	}

	if (EngCount && !KoreanCount)
	{
		if (InputType != IT_Engish)
			return L"���� ���� �Էµ� �� �ٸ��ϴ�.";

		ResultCode = InnerConvertStringToCode(GivenString, *EngStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"   ", L"", L"       ");
	}

	if (!EngCount && KoreanCount && InputType == IT_Korean)
	{
		if (InputType != IT_Korean)
			return L"���� ���� �Էµ� �� �ٸ��ϴ�.";

		ResultCode = InnerConvertStringToCode(HangulParser(GivenString), *KoreanStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"   ", L"     ", L"       ");
	}

	ResultCode += L'\0';

	return ResultCode;
}

wstring FMorseConverter::HangulParser(wstring InString)
{
	wstring Result;

	for (unsigned int i = 0; i < InString.size(); i++)
	{
		int Range = 0;
		int Ramnant = 0;

		if (InString[i] == L' ')
		{
			Result += InString[i];

			continue;
		}

		if (InString[i] >= L'��' && InString[i] <= L'�R')
		{
			HanguleJamoParser(int(InString[i]) - L'��', L'��' - L'��', Range, Ramnant);

			Range += L'��';
			KoreanCodeToLetterDictionary::iterator FinderIterator = FirstConsonantCodeToLetter->find(Range);
			if (FinderIterator != FirstConsonantCodeToLetter->end())
				Result += FirstConsonantCodeToLetter->at(Range);

			HanguleJamoParser(int(InString[i]) - Range, L'��' - L'��', Range, Ramnant);

			Result += MiddleVowerCodeToLetter->at(Range);
			Result += LastConsonantCodeToLetter->at(Ramnant);
		}
		else if (InString[i] >= L'��' && InString[i] <= L'��')
		{
			HanguleJamoParser(int(InString[i]) - L'��', L'��' - L'��', Range, Ramnant);
			Range *= (L'��' - L'��');
			Range += L'��';
			Result += JaeumOnlyCodeToLetter->at(Range);
		}
		else if (InString[i] >= L'��' && InString[i] <= L'��')
		{
			HanguleJamoParser(int(InString[i]) - L'��', L'��' - L'��', Range, Ramnant);
			Range *= (L'��' - L'��');
			Result += MiddleVowerCodeToLetter->at(Range);
		}
		else
			Result += InString[i];

		Result += L'|';
	}

	return Result;
}

void FMorseConverter::HanguleJamoParser(int ConvertedNum, int Divider, int& OutRange, int& OutRamnant)
{
	int Quotient = ConvertedNum / Divider;
	OutRange = Quotient * Divider;
	OutRamnant = ConvertedNum % Divider;
}

wstring FMorseConverter::HangulStringfy(const wstring& InParsedHangulStr)
{
	if (InParsedHangulStr == L"�߸��� �ڵ��Դϴ�")
		return InParsedHangulStr;

	wstring StringfiedResult;

	wstring GivenParsedString = InParsedHangulStr;

	unsigned int Index = 0;
	unsigned int SubIndex = 0;

	while (Index < InParsedHangulStr.size())
	{
		if (InParsedHangulStr[Index] == L' ' ||
			InParsedHangulStr[Index] == L'|' ||
			InParsedHangulStr[Index] == L'\0')
		{
			wstring FirstConsonantLetter;
			wstring MiddleVowerLetter;
			wstring LastConsonantLetter;

			int FirstConsonantValue = 0;
			int MiddleVowerValue = 0;
			int LastConsonantValue = 0;
			
			while (InParsedHangulStr[SubIndex] >= L'(' && InParsedHangulStr[SubIndex] <= L'?')
				StringfiedResult += InParsedHangulStr[SubIndex++];

			while (InParsedHangulStr[SubIndex] >= L'��' && InParsedHangulStr[SubIndex] <= L'��')
				FirstConsonantLetter += InParsedHangulStr[SubIndex++];

			if (FirstConsonantLetterToCode->find(FirstConsonantLetter) != FirstConsonantLetterToCode->end())
				FirstConsonantValue = FirstConsonantLetterToCode->at(FirstConsonantLetter);

			while (InParsedHangulStr[SubIndex] >= L'��' && InParsedHangulStr[SubIndex] <= L'��')
				MiddleVowerLetter += InParsedHangulStr[SubIndex++];
			
			// �ʼ��� ���ٸ� �߼��� �Է�
			if (FirstConsonantLetter == L"")
			{
				if (MoeumOnlyLetterCode->find(MiddleVowerLetter) != MoeumOnlyLetterCode->end())
					StringfiedResult += MoeumOnlyLetterCode->at(MiddleVowerLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			if (MiddleVowerLetterToCode->find(MiddleVowerLetter) != MiddleVowerLetterToCode->end())
				MiddleVowerValue = MiddleVowerLetterToCode->at(MiddleVowerLetter);

			// �߼��� ���ٸ� �ʼ��� �Է�
			if (MiddleVowerLetter == L"")
			{
				if (MoeumOnlyLetterCode->find(FirstConsonantLetter) != JaeumOnlyLetterCode->end())
					StringfiedResult += JaeumOnlyLetterCode->at(FirstConsonantLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			while (InParsedHangulStr[SubIndex] >= L'��' && InParsedHangulStr[SubIndex] <= L'��')
				LastConsonantLetter += InParsedHangulStr[SubIndex++];
			
			if (LastConsonantLetterToCode->find(LastConsonantLetter) != LastConsonantLetterToCode->end())
				LastConsonantValue = LastConsonantLetterToCode->at(LastConsonantLetter);
			
			int Result = FirstConsonantValue + MiddleVowerValue + LastConsonantValue;

			StringfiedResult += Result;
			
			if (InParsedHangulStr[Index] == L' ')
				StringfiedResult += L' ';

			SubIndex = Index + 1;
		}

		Index++;
	}

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

		FromMorseDirctionary::const_iterator FinderIterator;

		if (GivenCode.at(i) == L'.')
			value = 1;
		else if (GivenCode.at(i) == L'-')
			value = 2;
		else // ' ' or '/'
		{
			FinderIterator = InToStringDictionary.find(wordValue);

			if (FinderIterator == InToStringDictionary.end())
				return L"�߸��� �ڵ��Դϴ�";

			ConvertedString += InToStringDictionary.at(wordValue);
			
			if (GivenCode.at(i) == L'/')
				ConvertedString += L' ';

			if (GivenCode.at(i) == L'|')
				ConvertedString += GivenCode.at(i);

			wordIndex = 0;
			wordValue = 0;

			continue;
		}

		wordValue += value * (int)(pow(3, wordIndex++));
	}

	ConvertedString += L'\0';

	return ConvertedString;
}

wstring FMorseConverter::InnerConvertStringToCode(wstring InString, const ToMorseDictionary& InToCodeDictionary)
{
	wstring ConvertedResult;

	ConvertedResult += InToCodeDictionary.at(InString[0]);

	for (unsigned int i = 1; i < InString.size(); i++)
	{
		if (InString[i] == L'|')
		{
			ConvertedResult += InString[i];
			continue;
		}

		wstring ContertedCode = InToCodeDictionary.at(InString[i]);
		
		if ((ContertedCode != L"/" && ConvertedResult.back() != L'/') && ConvertedResult.back() != L'|')
			ConvertedResult += L' ';

		if (ContertedCode == L"/" && ConvertedResult.back() == L'|')
			ConvertedResult.pop_back();

		ConvertedResult += ContertedCode;
	}

	return ConvertedResult;
}

wstring FMorseConverter::BlankConvertCodeToString(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
{
	wstring BlankConvertedString;
	
	size_t LetterIntervalSize = LetterInterval.size();
	size_t SyllableIntervalSize = SyllableInterval.size();
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
			else if (BlankInterval == SyllableIntervalSize - 1)
				BlankConvertedString += L'|';
			else if (BlankInterval == WordIntervalSize - 1)
				BlankConvertedString += L'/';

			i = BlankCounter;
		}
		else
			BlankConvertedString += InCode[i++];
	}

	return BlankConvertedString;
}

wstring FMorseConverter::BlankConvertStringToCode(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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
		else if (InString[i] == L'|')
		{
			if (i != InString.size() - 1)
				BlankConvertedCode += SyllableInterval;
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
