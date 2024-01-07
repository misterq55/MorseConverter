#include "HangulParser.h"
#include "../CodeBook/HangulParserCodeBook/HangulParserCodeBook.h"

FHangulParser::FHangulParser()
	: FirstConsonantCodeBook(nullptr)
	, MiddleVowerCodeBook(nullptr)
	, LastConsonantCodeBook(nullptr)
	, JaeumOnlyCodeBook(nullptr)
	, MoeumOnlyCodeBook(nullptr)
{
	/*
	FirstConsonantCodeToLetter = new KoreanCodeToLetterDictionary({
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
		});

	MiddleVowerCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L"ㅏ"},
		{0x1C, L"ㅐ"},
		{0x38, L"ㅑ"},
		{0x54, L"ㅒ"},
		{0x70, L"ㅓ"},
		{0x8C, L"ㅔ"},
		{0xA8, L"ㅕ"},
		{0xC4, L"ㅖ"},
		{0xE0, L"ㅗ"},
		{0xFC, L"ㅗㅏ"},
		{0x118, L"ㅗㅐ"},
		{0x134, L"ㅗㅣ"},
		{0x150, L"ㅛ"},
		{0x16C, L"ㅜ"},
		{0x188, L"ㅜㅓ"},
		{0x1A4, L"ㅜㅔ"},
		{0x1C0, L"ㅜㅣ"},
		{0x1DC, L"ㅠ"},
		{0x1F8, L"ㅡ"},
		{0x214, L"ㅡㅣ"},
		{0x230, L"ㅣ"},
		});

	LastConsonantCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L""},
		{0x1, L"ㄱ"},
		{0x2, L"ㄱㄱ"},
		{0x3, L"ㄱㅅ"},
		{0x4, L"ㄴ"},
		{0x5, L"ㄴㅈ"},
		{0x6, L"ㄴㅎ"},
		{0x7, L"ㄷ"},
		{0x8, L"ㄹ"},
		{0x9, L"ㄹㄱ"},
		{0xA, L"ㄹㅁ"},
		{0xB, L"ㄹㅂ"},ㄱ
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
		});

	JaeumOnlyCodeToLetter = new KoreanCodeToLetterDictionary({
		{L'ㄱ', L"ㄱ"},
		{L'ㄲ', L"ㄱㄱ"},
		{L'ㄳ', L"ㄱㅅ"},
		{L'ㄴ', L"ㄴ"},
		{L'ㄵ', L"ㄴㅈ"},
		{L'ㄶ', L"ㄴㅎ"},
		{L'ㄷ', L"ㄷ"},
		{L'ㄸ', L"ㄷㄷ"},
		{L'ㄹ', L"ㄹ"},
		{L'ㄺ', L"ㄹㄱ"},
		{L'ㄻ', L"ㄹㅁ"},
		{L'ㄼ', L"ㄹㅂ"},
		{L'ㄽ', L"ㄹㅅ"},
		{L'ㄾ', L"ㄹㅌ"},
		{L'ㄿ', L"ㄹㅍ"},
		{L'ㅀ', L"ㄹㅎ"},
		{L'ㅁ', L"ㅁ"},
		{L'ㅂ', L"ㅂ"},
		{L'ㅃ', L"ㅂㅂ"},
		{L'ㅄ', L"ㅂㅅ"},
		{L'ㅅ', L"ㅅ"},
		{L'ㅆ', L"ㅅㅅ"},
		{L'ㅇ', L"ㅇ"},
		{L'ㅈ', L"ㅈ"},
		{L'ㅉ', L"ㅈㅈ"},
		{L'ㅊ', L"ㅊ"},
		{L'ㅋ', L"ㅋ"},
		{L'ㅌ', L"ㅌ"},
		{L'ㅍ', L"ㅍ"},
		{L'ㅎ', L"ㅎ"},
		});

	FirstConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"ㄱ", 0xAC00},
		{L"ㄱㄱ", 0xAE4C},
		{L"ㄴ", 0xB098},
		{L"ㄷ", 0xB2E4},
		{L"ㄷㄷ", 0xB530},
		{L"ㄹ", 0xB77C},
		{L"ㅁ", 0xB9C8},
		{L"ㅂ", 0xBC14},
		{L"ㅂㅂ", 0xBE60},
		{L"ㅅ", 0xC0AC},
		{L"ㅅㅅ", 0xC2F8},
		{L"ㅇ", 0xC544},
		{L"ㅈ", 0xC790},
		{L"ㅈㅈ", 0xC9DC},
		{L"ㅊ", 0xCC28},
		{L"ㅋ", 0xCE74},
		{L"ㅌ", 0xD0C0},
		{L"ㅍ", 0xD30C},
		{L"ㅎ", 0xD558},
		});

	MiddleVowerLetterToCode = new KoreanLetterToCodeDictionary({
		{L"ㅏ", 0x00},
		{L"ㅐ", 0x1C},
		{L"ㅑ", 0x38},
		{L"ㅒ", 0x54},
		{L"ㅓ", 0x70},
		{L"ㅔ", 0x8C},
		{L"ㅕ", 0xA8},
		{L"ㅖ", 0xC4},
		{L"ㅗ", 0xE0},
		{L"ㅗㅏ", 0xFC},
		{L"ㅗㅐ", 0x118},
		{L"ㅗㅣ", 0x134},
		{L"ㅛ", 0x150},
		{L"ㅜ", 0x16C},
		{L"ㅜㅓ", 0x188},
		{L"ㅜㅔ", 0x1A4},
		{L"ㅜㅣ", 0x1C0},
		{L"ㅠ", 0x1DC},
		{L"ㅡ", 0x1F8},
		{L"ㅡㅣ", 0x214},
		{L"ㅣ", 0x230},
		});

	LastConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"", 0x0},
		{L"ㄱ", 0x1},
		{L"ㄱㄱ", 0x2},
		{L"ㄱㅅ", 0x3},
		{L"ㄴ", 0x4},
		{L"ㄴㅈ", 0x5},
		{L"ㄴㅎ", 0x6},
		{L"ㄷ", 0x7},
		{L"ㄹ", 0x8},
		{L"ㄹㄱ", 0x9},
		{L"ㄹㅁ", 0xA},
		{L"ㄹㅂ", 0xB},
		{L"ㄹㅅ", 0xC},
		{L"ㄹㅌ", 0xD},
		{L"ㄹㅍ", 0xE},
		{L"ㄹㅎ", 0xF},
		{L"ㅁ", 0x10},
		{L"ㅂ", 0x11},
		{L"ㅂㅅ", 0x12},
		{L"ㅅ", 0x13},
		{L"ㅅㅅ", 0x14},
		{L"ㅇ", 0x15},
		{L"ㅈ", 0x16},
		{L"ㅊ", 0x17},
		{L"ㅋ", 0x18},
		{L"ㅌ", 0x19},
		{L"ㅍ", 0x1A},
		{L"ㅎ", 0x1B},
		});

	JaeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"ㄱ", L'ㄱ'},
		{L"ㄱㄱ", L'ㄲ'},
		{L"ㄱㅅ", L'ㄳ'},
		{L"ㄴ", L'ㄴ'},
		{L"ㄴㅈ", L'ㄵ'},
		{L"ㄴㅎ", L'ㄶ'},
		{L"ㄷ", L'ㄷ'},
		{L"ㄷㄷ", L'ㄸ'},
		{L"ㄹ", L'ㄹ'},
		{L"ㄹㄱ", L'ㄺ'},
		{L"ㄹㅁ", L'ㄻ'},
		{L"ㄹㅂ", L'ㄼ'},
		{L"ㄹㅅ", L'ㄽ'},
		{L"ㄹㅌ", L'ㄾ'},
		{L"ㄹㅍ", L'ㄿ'},
		{L"ㄹㅎ", L'ㅀ'},
		{L"ㅁ", L'ㅁ'},
		{L"ㅂ", L'ㅂ'},
		{L"ㅂㅂ", L'ㅃ'},
		{L"ㅂㅅ", L'ㅄ'},
		{L"ㅅ", L'ㅅ'},
		{L"ㅅㅅ", L'ㅆ'},
		{L"ㅇ", L'ㅇ'},
		{L"ㅈ", L'ㅈ'},
		{L"ㅈㅈ", L'ㅉ'},
		{L"ㅊ", L'ㅊ'},
		{L"ㅋ", L'ㅋ'},
		{L"ㅌ", L'ㅌ'},
		{L"ㅍ", L'ㅍ'},
		{L"ㅎ", L'ㅎ'},
		});

	MoeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"ㅏ", L'ㅏ'},
		{L"ㅐ", L'ㅐ'},
		{L"ㅑ", L'ㅑ'},
		{L"ㅒ", L'ㅒ'},
		{L"ㅓ", L'ㅓ'},
		{L"ㅔ", L'ㅔ'},
		{L"ㅕ", L'ㅕ'},
		{L"ㅖ", L'ㅖ'},
		{L"ㅗ", L'ㅗ'},
		{L"ㅗㅏ", L'ㅘ'},
		{L"ㅗㅐ", L'ㅙ'},
		{L"ㅗㅣ", L'ㅚ'},
		{L"ㅛ", L'ㅛ'},
		{L"ㅜ", L'ㅜ'},
		{L"ㅜㅓ", L'ㅝ'},
		{L"ㅜㅔ", L'ㅞ'},
		{L"ㅜㅣ", L'ㅟ'},
		{L"ㅠ", L'ㅠ'},
		{L"ㅡ", L'ㅡ'},
		{L"ㅡㅣ", L'ㅢ'},
		{L"ㅣ", L'ㅣ'},
		});*/
}

FHangulParser::~FHangulParser()
{
	delete FirstConsonantCodeBook;
	delete MiddleVowerCodeBook;
	delete LastConsonantCodeBook;
	delete JaeumOnlyCodeBook;
	delete MoeumOnlyCodeBook;
}

void FHangulParser::Initilize()
{
	FirstConsonantCodeBook = new FHangulParserCodeBook("Json/KoreanConsonantLetterCodeBook.json");
	MiddleVowerCodeBook = new FHangulParserCodeBook("Json/KoreanMiddleVowerLetterCodeBook.json");
	LastConsonantCodeBook = new FHangulParserCodeBook("Json/KoreanLastConsonantLetterCodeBook.json");
	JaeumOnlyCodeBook = new FHangulParserCodeBook("Json/KoreanLastJaeumLetterCodeBook.json");
	MoeumOnlyCodeBook = new FHangulParserCodeBook("Json/KoreanMoeumLetterCodeBook.json");
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

		if (InString[i] >= L'가' && InString[i] <= L'힣')
		{
			hanguleJamoParse(int(InString[i]) - L'가', L'까' - L'가', Range, Ramnant);

			Range += L'가';
			Result += FirstConsonantCodeBook->Encode(Range);

			hanguleJamoParse(int(InString[i]) - Range, L'개' - L'가', Range, Ramnant);

			Result += MiddleVowerCodeBook->Encode(Range);
			Result += LastConsonantCodeBook->Encode(Ramnant);
		}
		else if (InString[i] >= L'ㄱ' && InString[i] <= L'ㅎ')
		{
			hanguleJamoParse(int(InString[i]) - L'ㄱ', L'ㄲ' - L'ㄱ', Range, Ramnant);
			Range *= (L'ㄲ' - L'ㄱ');
			Range += L'ㄱ';
			Result += JaeumOnlyCodeBook->Encode(Range);
		}
		else if (InString[i] >= L'ㅏ' && InString[i] <= L'ㅣ')
		{
			hanguleJamoParse(int(InString[i]) - L'ㅏ', L'ㅐ' - L'ㅏ', Range, Ramnant);
			Range *= (L'개' - L'가');
			Result += MiddleVowerCodeBook->Encode(Range);
		}
		else
			Result += InString[i];

		Result += L'|';
	}

	return Result;
}

wstring FHangulParser::Decode(const wstring& InParsedHangulStr)
{
	if (InParsedHangulStr == L"잘못된 코드입니다")
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

			while (InParsedHangulStr[SubIndex] >= L'ㄱ' && InParsedHangulStr[SubIndex] <= L'ㅎ')
				FirstConsonantLetter += InParsedHangulStr[SubIndex++];

			FirstConsonantValue = FirstConsonantCodeBook->Decode(FirstConsonantLetter);

			while (InParsedHangulStr[SubIndex] >= L'ㅏ' && InParsedHangulStr[SubIndex] <= L'ㅣ')
				MiddleVowerLetter += InParsedHangulStr[SubIndex++];

			// 초성이 없다면 중성만 입력
			if (FirstConsonantLetter == L"")
			{
				StringfiedResult += MoeumOnlyCodeBook->Decode(MiddleVowerLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			MiddleVowerValue = MiddleVowerCodeBook->Decode(MiddleVowerLetter);

			// 중성이 없다면 초성만 입력
			if (MiddleVowerLetter == L"")
			{
				StringfiedResult += JaeumOnlyCodeBook->Decode(FirstConsonantLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			while (InParsedHangulStr[SubIndex] >= L'ㄱ' && InParsedHangulStr[SubIndex] <= L'ㅎ')
				LastConsonantLetter += InParsedHangulStr[SubIndex++];

			LastConsonantValue = LastConsonantCodeBook->Decode(LastConsonantLetter);

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