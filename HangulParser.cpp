#include "HangulParser.h"

FHangulParser::FHangulParser()
	: FirstConsonantCodeToLetter(nullptr)
	, MiddleVowerCodeToLetter(nullptr)
	, LastConsonantCodeToLetter(nullptr)
	, JaeumOnlyCodeToLetter(nullptr)
	, FirstConsonantLetterToCode(nullptr)
	, MiddleVowerLetterToCode(nullptr)
	, LastConsonantLetterToCode(nullptr)
	, JaeumOnlyLetterCode(nullptr)
	, MoeumOnlyLetterCode(nullptr)
{
	
}

void FHangulParser::Initilize()
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
}

wstring FHangulParser::Encode(const wstring& InString)
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
			hanguleJamoParse(int(InString[i]) - L'��', L'��' - L'��', Range, Ramnant);

			Range += L'��';
			KoreanCodeToLetterDictionary::iterator FinderIterator = FirstConsonantCodeToLetter->find(Range);
			if (FinderIterator != FirstConsonantCodeToLetter->end())
				Result += FirstConsonantCodeToLetter->at(Range);

			hanguleJamoParse(int(InString[i]) - Range, L'��' - L'��', Range, Ramnant);

			Result += MiddleVowerCodeToLetter->at(Range);
			Result += LastConsonantCodeToLetter->at(Ramnant);
		}
		else if (InString[i] >= L'��' && InString[i] <= L'��')
		{
			hanguleJamoParse(int(InString[i]) - L'��', L'��' - L'��', Range, Ramnant);
			Range *= (L'��' - L'��');
			Range += L'��';
			Result += JaeumOnlyCodeToLetter->at(Range);
		}
		else if (InString[i] >= L'��' && InString[i] <= L'��')
		{
			hanguleJamoParse(int(InString[i]) - L'��', L'��' - L'��', Range, Ramnant);
			Range *= (L'��' - L'��');
			Result += MiddleVowerCodeToLetter->at(Range);
		}
		else
			Result += InString[i];

		Result += L'|';
	}

	return Result;
}

wstring FHangulParser::Decode(const wstring& InParsedHangulStr)
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
				if (JaeumOnlyLetterCode->find(FirstConsonantLetter) != JaeumOnlyLetterCode->end())
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

void FHangulParser::hanguleJamoParse(int ConvertedNum, int Divider, int& OutRange, int& OutRamnant)
{
	int Quotient = ConvertedNum / Divider;
	OutRange = Quotient * Divider;
	OutRamnant = ConvertedNum % Divider;
}