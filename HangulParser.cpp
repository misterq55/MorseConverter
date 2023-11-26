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
		{0xAC00, L"ぁ"},
		{0xAE4C, L"ぁぁ"},
		{0xB098, L"い"},
		{0xB2E4, L"ぇ"},
		{0xB530, L"ぇぇ"},
		{0xB77C, L"ぉ"},
		{0xB9C8, L"け"},
		{0xBC14, L"げ"},
		{0xBE60, L"げげ"},
		{0xC0AC, L"さ"},
		{0xC2F8, L"ささ"},
		{0xC544, L"し"},
		{0xC790, L"じ"},
		{0xC9DC, L"じじ"},
		{0xCC28, L"ず"},
		{0xCE74, L"せ"},
		{0xD0C0, L"ぜ"},
		{0xD30C, L"そ"},
		{0xD558, L"ぞ"},
		});

	MiddleVowerCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L"た"},
		{0x1C, L"だ"},
		{0x38, L"ち"},
		{0x54, L"ぢ"},
		{0x70, L"っ"},
		{0x8C, L"つ"},
		{0xA8, L"づ"},
		{0xC4, L"て"},
		{0xE0, L"で"},
		{0xFC, L"でた"},
		{0x118, L"でだ"},
		{0x134, L"でび"},
		{0x150, L"に"},
		{0x16C, L"ぬ"},
		{0x188, L"ぬっ"},
		{0x1A4, L"ぬつ"},
		{0x1C0, L"ぬび"},
		{0x1DC, L"ば"},
		{0x1F8, L"ぱ"},
		{0x214, L"ぱび"},
		{0x230, L"び"},
		});

	LastConsonantCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L""},
		{0x1, L"ぁ"},
		{0x2, L"ぁぁ"},
		{0x3, L"ぁさ"},
		{0x4, L"い"},
		{0x5, L"いじ"},
		{0x6, L"いぞ"},
		{0x7, L"ぇ"},
		{0x8, L"ぉ"},
		{0x9, L"ぉぁ"},
		{0xA, L"ぉけ"},
		{0xB, L"ぉげ"},
		{0xC, L"ぉさ"},
		{0xD, L"ぉぜ"},
		{0xE, L"ぉそ"},
		{0xF, L"ぉぞ"},
		{0x10, L"け"},
		{0x11, L"げ"},
		{0x12, L"げさ"},
		{0x13, L"さ"},
		{0x14, L"ささ"},
		{0x15, L"し"},
		{0x16, L"じ"},
		{0x17, L"ず"},
		{0x18, L"せ"},
		{0x19, L"ぜ"},
		{0x1A, L"そ"},
		{0x1B, L"ぞ"},
		});

	JaeumOnlyCodeToLetter = new KoreanCodeToLetterDictionary({
		{L'ぁ', L"ぁ"},
		{L'あ', L"ぁぁ"},
		{L'ぃ', L"ぁさ"},
		{L'い', L"い"},
		{L'ぅ', L"いじ"},
		{L'う', L"いぞ"},
		{L'ぇ', L"ぇ"},
		{L'え', L"ぇぇ"},
		{L'ぉ', L"ぉ"},
		{L'お', L"ぉぁ"},
		{L'か', L"ぉけ"},
		{L'が', L"ぉげ"},
		{L'き', L"ぉさ"},
		{L'ぎ', L"ぉぜ"},
		{L'く', L"ぉそ"},
		{L'ぐ', L"ぉぞ"},
		{L'け', L"け"},
		{L'げ', L"げ"},
		{L'こ', L"げげ"},
		{L'ご', L"げさ"},
		{L'さ', L"さ"},
		{L'ざ', L"ささ"},
		{L'し', L"し"},
		{L'じ', L"じ"},
		{L'す', L"じじ"},
		{L'ず', L"ず"},
		{L'せ', L"せ"},
		{L'ぜ', L"ぜ"},
		{L'そ', L"そ"},
		{L'ぞ', L"ぞ"},
		});

	FirstConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"ぁ", 0xAC00},
		{L"ぁぁ", 0xAE4C},
		{L"い", 0xB098},
		{L"ぇ", 0xB2E4},
		{L"ぇぇ", 0xB530},
		{L"ぉ", 0xB77C},
		{L"け", 0xB9C8},
		{L"げ", 0xBC14},
		{L"げげ", 0xBE60},
		{L"さ", 0xC0AC},
		{L"ささ", 0xC2F8},
		{L"し", 0xC544},
		{L"じ", 0xC790},
		{L"じじ", 0xC9DC},
		{L"ず", 0xCC28},
		{L"せ", 0xCE74},
		{L"ぜ", 0xD0C0},
		{L"そ", 0xD30C},
		{L"ぞ", 0xD558},
		});

	MiddleVowerLetterToCode = new KoreanLetterToCodeDictionary({
		{L"た", 0x00},
		{L"だ", 0x1C},
		{L"ち", 0x38},
		{L"ぢ", 0x54},
		{L"っ", 0x70},
		{L"つ", 0x8C},
		{L"づ", 0xA8},
		{L"て", 0xC4},
		{L"で", 0xE0},
		{L"でた", 0xFC},
		{L"でだ", 0x118},
		{L"でび", 0x134},
		{L"に", 0x150},
		{L"ぬ", 0x16C},
		{L"ぬっ", 0x188},
		{L"ぬつ", 0x1A4},
		{L"ぬび", 0x1C0},
		{L"ば", 0x1DC},
		{L"ぱ", 0x1F8},
		{L"ぱび", 0x214},
		{L"び", 0x230},
		});

	LastConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"", 0x0},
		{L"ぁ", 0x1},
		{L"ぁぁ", 0x2},
		{L"ぁさ", 0x3},
		{L"い", 0x4},
		{L"いじ", 0x5},
		{L"いぞ", 0x6},
		{L"ぇ", 0x7},
		{L"ぉ", 0x8},
		{L"ぉぁ", 0x9},
		{L"ぉけ", 0xA},
		{L"ぉげ", 0xB},
		{L"ぉさ", 0xC},
		{L"ぉぜ", 0xD},
		{L"ぉそ", 0xE},
		{L"ぉぞ", 0xF},
		{L"け", 0x10},
		{L"げ", 0x11},
		{L"げさ", 0x12},
		{L"さ", 0x13},
		{L"ささ", 0x14},
		{L"し", 0x15},
		{L"じ", 0x16},
		{L"ず", 0x17},
		{L"せ", 0x18},
		{L"ぜ", 0x19},
		{L"そ", 0x1A},
		{L"ぞ", 0x1B},
		});

	JaeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"ぁ", L'ぁ'},
		{L"ぁぁ", L'あ'},
		{L"ぁさ", L'ぃ'},
		{L"い", L'い'},
		{L"いじ", L'ぅ'},
		{L"いぞ", L'う'},
		{L"ぇ", L'ぇ'},
		{L"ぇぇ", L'え'},
		{L"ぉ", L'ぉ'},
		{L"ぉぁ", L'お'},
		{L"ぉけ", L'か'},
		{L"ぉげ", L'が'},
		{L"ぉさ", L'き'},
		{L"ぉぜ", L'ぎ'},
		{L"ぉそ", L'く'},
		{L"ぉぞ", L'ぐ'},
		{L"け", L'け'},
		{L"げ", L'げ'},
		{L"げげ", L'こ'},
		{L"げさ", L'ご'},
		{L"さ", L'さ'},
		{L"ささ", L'ざ'},
		{L"し", L'し'},
		{L"じ", L'じ'},
		{L"じじ", L'す'},
		{L"ず", L'ず'},
		{L"せ", L'せ'},
		{L"ぜ", L'ぜ'},
		{L"そ", L'そ'},
		{L"ぞ", L'ぞ'},
		});

	MoeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"た", L'た'},
		{L"だ", L'だ'},
		{L"ち", L'ち'},
		{L"ぢ", L'ぢ'},
		{L"っ", L'っ'},
		{L"つ", L'つ'},
		{L"づ", L'づ'},
		{L"て", L'て'},
		{L"で", L'で'},
		{L"でた", L'と'},
		{L"でだ", L'ど'},
		{L"でび", L'な'},
		{L"に", L'に'},
		{L"ぬ", L'ぬ'},
		{L"ぬっ", L'ね'},
		{L"ぬつ", L'の'},
		{L"ぬび", L'は'},
		{L"ば", L'ば'},
		{L"ぱ", L'ぱ'},
		{L"ぱび", L'ひ'},
		{L"び", L'び'},
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

		if (InString[i] >= L'亜' && InString[i] <= L'�R')
		{
			hanguleJamoParse(int(InString[i]) - L'亜', L'猿' - L'亜', Range, Ramnant);

			Range += L'亜';
			KoreanCodeToLetterDictionary::iterator FinderIterator = FirstConsonantCodeToLetter->find(Range);
			if (FinderIterator != FirstConsonantCodeToLetter->end())
				Result += FirstConsonantCodeToLetter->at(Range);

			hanguleJamoParse(int(InString[i]) - Range, L'鯵' - L'亜', Range, Ramnant);

			Result += MiddleVowerCodeToLetter->at(Range);
			Result += LastConsonantCodeToLetter->at(Ramnant);
		}
		else if (InString[i] >= L'ぁ' && InString[i] <= L'ぞ')
		{
			hanguleJamoParse(int(InString[i]) - L'ぁ', L'あ' - L'ぁ', Range, Ramnant);
			Range *= (L'あ' - L'ぁ');
			Range += L'ぁ';
			Result += JaeumOnlyCodeToLetter->at(Range);
		}
		else if (InString[i] >= L'た' && InString[i] <= L'び')
		{
			hanguleJamoParse(int(InString[i]) - L'た', L'だ' - L'た', Range, Ramnant);
			Range *= (L'鯵' - L'亜');
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
	if (InParsedHangulStr == L"設公吉 坪球脊艦陥")
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

			while (InParsedHangulStr[SubIndex] >= L'ぁ' && InParsedHangulStr[SubIndex] <= L'ぞ')
				FirstConsonantLetter += InParsedHangulStr[SubIndex++];

			if (FirstConsonantLetterToCode->find(FirstConsonantLetter) != FirstConsonantLetterToCode->end())
				FirstConsonantValue = FirstConsonantLetterToCode->at(FirstConsonantLetter);

			while (InParsedHangulStr[SubIndex] >= L'た' && InParsedHangulStr[SubIndex] <= L'び')
				MiddleVowerLetter += InParsedHangulStr[SubIndex++];

			// 段失戚 蒸陥檎 掻失幻 脊径
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

			// 掻失戚 蒸陥檎 段失幻 脊径
			if (MiddleVowerLetter == L"")
			{
				if (JaeumOnlyLetterCode->find(FirstConsonantLetter) != JaeumOnlyLetterCode->end())
					StringfiedResult += JaeumOnlyLetterCode->at(FirstConsonantLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			while (InParsedHangulStr[SubIndex] >= L'ぁ' && InParsedHangulStr[SubIndex] <= L'ぞ')
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