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
		{0xAC00, L"丑"},
		{0xAE4C, L"丑丑"},
		{0xB098, L"中"},
		{0xB2E4, L"之"},
		{0xB530, L"之之"},
		{0xB77C, L"予"},
		{0xB9C8, L"仃"},
		{0xBC14, L"仆"},
		{0xBE60, L"仆仆"},
		{0xC0AC, L"今"},
		{0xC2F8, L"今今"},
		{0xC544, L"仄"},
		{0xC790, L"元"},
		{0xC9DC, L"元元"},
		{0xCC28, L"內"},
		{0xCE74, L"六"},
		{0xD0C0, L"兮"},
		{0xD30C, L"公"},
		{0xD558, L"冗"},
		});

	MiddleVowerCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L"凶"},
		{0x1C, L"分"},
		{0x38, L"切"},
		{0x54, L"刈"},
		{0x70, L"勻"},
		{0x8C, L"勾"},
		{0xA8, L"勿"},
		{0xC4, L"化"},
		{0xE0, L"匹"},
		{0xFC, L"匹凶"},
		{0x118, L"匹分"},
		{0x134, L"匹太"},
		{0x150, L"卞"},
		{0x16C, L"厄"},
		{0x188, L"厄勻"},
		{0x1A4, L"厄勾"},
		{0x1C0, L"厄太"},
		{0x1DC, L"壬"},
		{0x1F8, L"天"},
		{0x214, L"天太"},
		{0x230, L"太"},
		});

	LastConsonantCodeToLetter = new KoreanCodeToLetterDictionary({
		{0x0, L""},
		{0x1, L"丑"},
		{0x2, L"丑丑"},
		{0x3, L"丑今"},
		{0x4, L"中"},
		{0x5, L"中元"},
		{0x6, L"中冗"},
		{0x7, L"之"},
		{0x8, L"予"},
		{0x9, L"予丑"},
		{0xA, L"予仃"},
		{0xB, L"予仆"},
		{0xC, L"予今"},
		{0xD, L"予兮"},
		{0xE, L"予公"},
		{0xF, L"予冗"},
		{0x10, L"仃"},
		{0x11, L"仆"},
		{0x12, L"仆今"},
		{0x13, L"今"},
		{0x14, L"今今"},
		{0x15, L"仄"},
		{0x16, L"元"},
		{0x17, L"內"},
		{0x18, L"六"},
		{0x19, L"兮"},
		{0x1A, L"公"},
		{0x1B, L"冗"},
		});

	JaeumOnlyCodeToLetter = new KoreanCodeToLetterDictionary({
		{L'丑', L"丑"},
		{L'丐', L"丑丑"},
		{L'不', L"丑今"},
		{L'中', L"中"},
		{L'丰', L"中元"},
		{L'丹', L"中冗"},
		{L'之', L"之"},
		{L'尹', L"之之"},
		{L'予', L"予"},
		{L'云', L"予丑"},
		{L'井', L"予仃"},
		{L'互', L"予仆"},
		{L'五', L"予今"},
		{L'亢', L"予兮"},
		{L'仁', L"予公"},
		{L'什', L"予冗"},
		{L'仃', L"仃"},
		{L'仆', L"仆"},
		{L'仇', L"仆仆"},
		{L'仍', L"仆今"},
		{L'今', L"今"},
		{L'介', L"今今"},
		{L'仄', L"仄"},
		{L'元', L"元"},
		{L'允', L"元元"},
		{L'內', L"內"},
		{L'六', L"六"},
		{L'兮', L"兮"},
		{L'公', L"公"},
		{L'冗', L"冗"},
		});

	FirstConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"丑", 0xAC00},
		{L"丑丑", 0xAE4C},
		{L"中", 0xB098},
		{L"之", 0xB2E4},
		{L"之之", 0xB530},
		{L"予", 0xB77C},
		{L"仃", 0xB9C8},
		{L"仆", 0xBC14},
		{L"仆仆", 0xBE60},
		{L"今", 0xC0AC},
		{L"今今", 0xC2F8},
		{L"仄", 0xC544},
		{L"元", 0xC790},
		{L"元元", 0xC9DC},
		{L"內", 0xCC28},
		{L"六", 0xCE74},
		{L"兮", 0xD0C0},
		{L"公", 0xD30C},
		{L"冗", 0xD558},
		});

	MiddleVowerLetterToCode = new KoreanLetterToCodeDictionary({
		{L"凶", 0x00},
		{L"分", 0x1C},
		{L"切", 0x38},
		{L"刈", 0x54},
		{L"勻", 0x70},
		{L"勾", 0x8C},
		{L"勿", 0xA8},
		{L"化", 0xC4},
		{L"匹", 0xE0},
		{L"匹凶", 0xFC},
		{L"匹分", 0x118},
		{L"匹太", 0x134},
		{L"卞", 0x150},
		{L"厄", 0x16C},
		{L"厄勻", 0x188},
		{L"厄勾", 0x1A4},
		{L"厄太", 0x1C0},
		{L"壬", 0x1DC},
		{L"天", 0x1F8},
		{L"天太", 0x214},
		{L"太", 0x230},
		});

	LastConsonantLetterToCode = new KoreanLetterToCodeDictionary({
		{L"", 0x0},
		{L"丑", 0x1},
		{L"丑丑", 0x2},
		{L"丑今", 0x3},
		{L"中", 0x4},
		{L"中元", 0x5},
		{L"中冗", 0x6},
		{L"之", 0x7},
		{L"予", 0x8},
		{L"予丑", 0x9},
		{L"予仃", 0xA},
		{L"予仆", 0xB},
		{L"予今", 0xC},
		{L"予兮", 0xD},
		{L"予公", 0xE},
		{L"予冗", 0xF},
		{L"仃", 0x10},
		{L"仆", 0x11},
		{L"仆今", 0x12},
		{L"今", 0x13},
		{L"今今", 0x14},
		{L"仄", 0x15},
		{L"元", 0x16},
		{L"內", 0x17},
		{L"六", 0x18},
		{L"兮", 0x19},
		{L"公", 0x1A},
		{L"冗", 0x1B},
		});

	JaeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"丑", L'丑'},
		{L"丑丑", L'丐'},
		{L"丑今", L'不'},
		{L"中", L'中'},
		{L"中元", L'丰'},
		{L"中冗", L'丹'},
		{L"之", L'之'},
		{L"之之", L'尹'},
		{L"予", L'予'},
		{L"予丑", L'云'},
		{L"予仃", L'井'},
		{L"予仆", L'互'},
		{L"予今", L'五'},
		{L"予兮", L'亢'},
		{L"予公", L'仁'},
		{L"予冗", L'什'},
		{L"仃", L'仃'},
		{L"仆", L'仆'},
		{L"仆仆", L'仇'},
		{L"仆今", L'仍'},
		{L"今", L'今'},
		{L"今今", L'介'},
		{L"仄", L'仄'},
		{L"元", L'元'},
		{L"元元", L'允'},
		{L"內", L'內'},
		{L"六", L'六'},
		{L"兮", L'兮'},
		{L"公", L'公'},
		{L"冗", L'冗'},
		});

	MoeumOnlyLetterCode = new KoreanLetterToCodeDictionary({
		{L"凶", L'凶'},
		{L"分", L'分'},
		{L"切", L'切'},
		{L"刈", L'刈'},
		{L"勻", L'勻'},
		{L"勾", L'勾'},
		{L"勿", L'勿'},
		{L"化", L'化'},
		{L"匹", L'匹'},
		{L"匹凶", L'午'},
		{L"匹分", L'升'},
		{L"匹太", L'卅'},
		{L"卞", L'卞'},
		{L"厄", L'厄'},
		{L"厄勻", L'友'},
		{L"厄勾", L'及'},
		{L"厄太", L'反'},
		{L"壬", L'壬'},
		{L"天", L'天'},
		{L"天太", L'夫'},
		{L"太", L'太'},
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

		if (InString[i] >= L'陛' && InString[i] <= L'鼇')
		{
			hanguleJamoParse(int(InString[i]) - L'陛', L'梱' - L'陛', Range, Ramnant);

			Range += L'陛';
			KoreanCodeToLetterDictionary::iterator FinderIterator = FirstConsonantCodeToLetter->find(Range);
			if (FinderIterator != FirstConsonantCodeToLetter->end())
				Result += FirstConsonantCodeToLetter->at(Range);

			hanguleJamoParse(int(InString[i]) - Range, L'偃' - L'陛', Range, Ramnant);

			Result += MiddleVowerCodeToLetter->at(Range);
			Result += LastConsonantCodeToLetter->at(Ramnant);
		}
		else if (InString[i] >= L'丑' && InString[i] <= L'冗')
		{
			hanguleJamoParse(int(InString[i]) - L'丑', L'丐' - L'丑', Range, Ramnant);
			Range *= (L'丐' - L'丑');
			Range += L'丑';
			Result += JaeumOnlyCodeToLetter->at(Range);
		}
		else if (InString[i] >= L'凶' && InString[i] <= L'太')
		{
			hanguleJamoParse(int(InString[i]) - L'凶', L'分' - L'凶', Range, Ramnant);
			Range *= (L'偃' - L'陛');
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
	if (InParsedHangulStr == L"澀跤脹 囀萄殮棲棻")
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

			while (InParsedHangulStr[SubIndex] >= L'丑' && InParsedHangulStr[SubIndex] <= L'冗')
				FirstConsonantLetter += InParsedHangulStr[SubIndex++];

			if (FirstConsonantLetterToCode->find(FirstConsonantLetter) != FirstConsonantLetterToCode->end())
				FirstConsonantValue = FirstConsonantLetterToCode->at(FirstConsonantLetter);

			while (InParsedHangulStr[SubIndex] >= L'凶' && InParsedHangulStr[SubIndex] <= L'太')
				MiddleVowerLetter += InParsedHangulStr[SubIndex++];

			// 蟾撩檜 橈棻賊 醞撩虜 殮溘
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

			// 醞撩檜 橈棻賊 蟾撩虜 殮溘
			if (MiddleVowerLetter == L"")
			{
				if (JaeumOnlyLetterCode->find(FirstConsonantLetter) != JaeumOnlyLetterCode->end())
					StringfiedResult += JaeumOnlyLetterCode->at(FirstConsonantLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			while (InParsedHangulStr[SubIndex] >= L'丑' && InParsedHangulStr[SubIndex] <= L'冗')
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