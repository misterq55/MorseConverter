#include "MorseConverter.h"

FMorseConverter::FMorseConverter()
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
		{43, L'丑'}, // 丑 1 2 1 1
		{49, L'中'}, // 中 1 1 2 1
		{41, L'之'}, // 之 2 1 1 1
		{67, L'予'}, // 予 1 1 1 2
		{8, L'仃'}, // 仃 2 2
		{25, L'仆'}, // 仆 1 2 2
		{17, L'今'}, // 今 2 2 1
		{23, L'仄'}, // 仄 2 1 2
		{52, L'元'}, // 元 1 2 2 1
		{50, L'內'}, // 內 2 1 2 1
		{68, L'六'}, // 六 2 1 1 2
		{44, L'兮'}, // 兮 2 2 1 1
		{26, L'公'}, // 公 2 2 2
		{79, L'冗'}, // 冗 1 2 2 2

		{1, L'凶'}, // 凶 1
		{4, L'切'}, // 切 1 1
		{2, L'勻'}, // 勻 2
		{13, L'勿'}, // 勿 1 1 1
		{7, L'匹'}, // 匹 1 2
		{5, L'卞'}, // 卞 2 1
		{40, L'厄'}, // 厄 1 1 1 1
		{16, L'壬'}, // 壬 1 2 1
		{14, L'天'}, // 天 2 1 1
		{22, L'太'}, // 太 1 1 2
		{71, L'分'}, // 分 2 2 1 2
		{77, L'勾'}, // 勾 2 1 2 2

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
		{L'丑', L".-.."},
		{L'中', L"..-."},
		{L'之', L"-..."},
		{L'予', L"...-"},
		{L'仃', L"--"},
		{L'仆', L".--"},
		{L'今', L"--."},
		{L'仄', L"-.-"},
		{L'元', L".--."},
		{L'內', L"-.-."},
		{L'六', L"-..-"},
		{L'兮', L"--.."},
		{L'公', L"---"},
		{L'冗', L".---"},

		{L'凶', L"."},
		{L'切', L".."},
		{L'勻', L"-"},
		{L'勿', L"..."},
		{L'匹', L".-"},
		{L'卞', L"-."},
		{L'厄', L"...."},
		{L'壬', L".-."},
		{L'天', L"-.."},
		{L'太', L"..-"},
		{L'分', L"--.-"},
		{L'勾', L"-.--"},

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

	delete FirstConsonantLetterToCode;
	delete MiddleVowerLetterToCode;
	delete LastConsonantLetterToCode;

	delete FromMorseToEngStringDictionary;
	delete FromMorseToKoreanStringDictionary;

	delete EngStringToMorseDictionary;
	delete KoreanStringToMorseDictionary;
}

wstring FMorseConverter::ConvertCodeToString(const wstring& InCode)
{
	if (InputType == IT_None)
		return L"殮溘 樹橫陛 撲薑腎雖 彊懊蝗棲棻.";

	wstring ResultString;

	if (InputType == IT_Engish)
	{
		ResultString = BlankConvertCodeToString(InCode, L"   ", L"       ");
		ResultString = InnerConvertCodeToString(ResultString, *FromMorseToEngStringDictionary);
	}

	if (InputType == IT_Korean)
	{
		ResultString = BlankConvertCodeToString(InCode, L"     ", L"       ");
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

		if (0xAC00 <= GivenString[i] && 0xD7A3 >= GivenString[i])
			KoreanCount++;

		if (EngCount && KoreanCount)
			return L"舒陛雖 檜鼻曖 樹橫陛 馬雖腎歷蝗棲棻.";
	}

	if (EngCount && !KoreanCount)
	{
		ResultCode = InnerConvertStringToCode(GivenString, *EngStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"   ", L"       ");
	}

	if (!EngCount && KoreanCount)
	{
		ResultCode = InnerConvertStringToCode(HangulParser(GivenString), *KoreanStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"     ", L"       ");
	}

	ResultCode += L'\0';

	return ResultCode;
}

wstring FMorseConverter::HangulParser(wstring InString)
{
	wstring Result;

	for (unsigned int i = 0; i < InString.size(); i++)
	{
		if (!(InString[i] >= L'陛' && InString[i] <= L'鼇'))
		{
			Result += InString[i];
			continue;
		}

		int StartNumber = 0xAC00;
		int Divider = 0x24C;
		int ConvertedNum = int(InString[i]);
		int PureNum = ConvertedNum - StartNumber;
		int Quotient = PureNum / Divider;
		int Range = Quotient * Divider + StartNumber;
		Result += FirstConsonantCodeToLetter->at(Range);

		StartNumber = Range;
		Divider = 0x1C;
		ConvertedNum = int(InString[i]);
		PureNum = ConvertedNum - StartNumber;
		Quotient = PureNum / Divider;
		int Ramnant = PureNum % Divider;
		Range = Quotient * Divider;
		Result += MiddleVowerCodeToLetter->at(Range);
		Result += LastConsonantCodeToLetter->at(Ramnant);
	}

	return Result;
}

wstring FMorseConverter::HangulStringfy(wstring InParsedHangulStr)
{
	wstring StringfiedResult;

	unsigned int Index = 0;

	while (Index < InParsedHangulStr.size())
	{
		if (InParsedHangulStr[Index] == L'\0')
			break;

		wstring FirstConsonantLetter;
		wstring MiddleVowerLetter;
		wstring LastConsonantLetter;

		int SubIndex = 0;

		while (InParsedHangulStr[Index + SubIndex] >= L'丑' && InParsedHangulStr[Index + SubIndex] <= L'冗' && SubIndex < 2)
			FirstConsonantLetter += InParsedHangulStr[Index + SubIndex++];

		Index = Index + SubIndex;
		SubIndex = 0;

		int FirstConsonantValue = FirstConsonantLetterToCode->at(FirstConsonantLetter);

		while (InParsedHangulStr[Index + SubIndex] >= L'凶' && InParsedHangulStr[Index + SubIndex] <= L'太' && SubIndex < 2)
			MiddleVowerLetter += InParsedHangulStr[Index + SubIndex++];

		Index = Index + SubIndex;
		SubIndex = 0;

		int MiddleVowerValue = MiddleVowerLetterToCode->at(MiddleVowerLetter);

		while (InParsedHangulStr[Index + SubIndex] >= L'丑' && InParsedHangulStr[Index + SubIndex] <= L'冗' && SubIndex < 2)
			LastConsonantLetter += InParsedHangulStr[Index + SubIndex++];

		Index = Index + SubIndex;
		SubIndex = 0;

		int LastConsonantValue = LastConsonantLetterToCode->at(LastConsonantLetter);
		int Result = FirstConsonantValue + MiddleVowerValue + LastConsonantValue;
		StringfiedResult += Result;
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

	ConvertedString += L'\0';

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
			ConvertedResult += L' ';

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
