#include "MorseConverter.h"
#include <cmath>
#include "../HangulParser/HangulParser.h"

FMorseConverter::FMorseConverter()
	: FromMorseToEngStringDictionary(nullptr)
	, FromMorseToKoreanStringDictionary(nullptr)
	, EngStringToMorseDictionary(nullptr)
	, KoreanStringToMorseDictionary(nullptr)
{
	
}

FMorseConverter::~FMorseConverter()
{
	delete FromMorseToEngStringDictionary;
	delete FromMorseToKoreanStringDictionary;

	delete EngStringToMorseDictionary;
	delete KoreanStringToMorseDictionary;

	delete HangulParser;
}

void FMorseConverter::Initilize()
{
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

		{355, L'-'}, // 2 1 1 1 1 2
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
		{L'I', L".."},
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
		{43, L'ㄱ'}, // ㄱ 1 2 1 1
		{49, L'ㄴ'}, // ㄴ 1 1 2 1
		{41, L'ㄷ'}, // ㄷ 2 1 1 1
		{67, L'ㄹ'}, // ㄹ 1 1 1 2
		{8, L'ㅁ'}, // ㅁ 2 2
		{25, L'ㅂ'}, // ㅂ 1 2 2
		{17, L'ㅅ'}, // ㅅ 2 2 1
		{23, L'ㅇ'}, // ㅇ 2 1 2
		{52, L'ㅈ'}, // ㅈ 1 2 2 1
		{50, L'ㅊ'}, // ㅊ 2 1 2 1
		{68, L'ㅋ'}, // ㅋ 2 1 1 2
		{44, L'ㅌ'}, // ㅌ 2 2 1 1
		{26, L'ㅍ'}, // ㅍ 2 2 2
		{79, L'ㅎ'}, // ㅎ 1 2 2 2

		{1, L'ㅏ'}, // ㅏ 1
		{4, L'ㅑ'}, // ㅑ 1 1
		{2, L'ㅓ'}, // ㅓ 2
		{13, L'ㅕ'}, // ㅕ 1 1 1
		{7, L'ㅗ'}, // ㅗ 1 2
		{5, L'ㅛ'}, // ㅛ 2 1
		{40, L'ㅜ'}, // ㅜ 1 1 1 1
		{16, L'ㅠ'}, // ㅠ 1 2 1
		{14, L'ㅡ'}, // ㅡ 2 1 1
		{22, L'ㅣ'}, // ㅣ 1 1 2
		{71, L'ㅐ'}, // ㅐ 2 2 1 2
		{77, L'ㅔ'}, // ㅔ 2 1 2 2

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
		{L'ㄱ', L".-.."},
		{L'ㄴ', L"..-."},
		{L'ㄷ', L"-..."},
		{L'ㄹ', L"...-"},
		{L'ㅁ', L"--"},
		{L'ㅂ', L".--"},
		{L'ㅅ', L"--."},
		{L'ㅇ', L"-.-"},
		{L'ㅈ', L".--."},
		{L'ㅊ', L"-.-."},
		{L'ㅋ', L"-..-"},
		{L'ㅌ', L"--.."},
		{L'ㅍ', L"---"},
		{L'ㅎ', L".---"},

		{L'ㅏ', L"."},
		{L'ㅑ', L".."},
		{L'ㅓ', L"-"},
		{L'ㅕ', L"..."},
		{L'ㅗ', L".-"},
		{L'ㅛ', L"-."},
		{L'ㅜ', L"...."},
		{L'ㅠ', L".-."},
		{L'ㅡ', L"-.."},
		{L'ㅣ', L"..-"},
		{L'ㅐ', L"--.-"},
		{L'ㅔ', L"-.--"},

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

	HangulParser = new FHangulParser();

	if (HangulParser)
	{
		HangulParser->Initilize();
	}
}

wstring FMorseConverter::Encode(const wstring& InString)
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

		if ((L'가' <= GivenString[i] && L'힣' >= GivenString[i]) ||
			(L'ㄱ' <= GivenString[i] && L'ㅎ' >= GivenString[i]) ||
			(L'ㅏ' <= GivenString[i] && L'ㅣ' >= GivenString[i]))
			KoreanCount++;

		if (EngCount && KoreanCount)
			return L"두가지 이상의 언어가 감지되었습니다.";
	}

	if (EngCount && !KoreanCount)
	{
		if (InputType != IT_Engish)
			return L"현재 모드와 입력된 언어가 다릅니다.";

		ResultCode = encode_Inner(GivenString, *EngStringToMorseDictionary);
		ResultCode = addBlankSpaces(ResultCode, L"   ", L"", L"       ");
	}

	if (!EngCount && KoreanCount && InputType == IT_Korean)
	{
		if (InputType != IT_Korean)
			return L"현재 모드와 입력된 언어가 다릅니다.";

		ResultCode = encode_Inner(hangulParse(GivenString), *KoreanStringToMorseDictionary);
		ResultCode = addBlankSpaces(ResultCode, L"   ", L"     ", L"       ");
	}

	ResultCode += L'\0';

	return ResultCode;
}

wstring FMorseConverter::Decode(const wstring& InCode)
{
	if (InputType == IT_None)
		return L"입력 언어가 설정되지 않았습니다.";

	wstring ResultString;
	wstring GivenCode = InCode;
	
	if (GivenCode.back() != L'\0')
		GivenCode += L'\0';

	if (InputType == IT_Engish)
	{
		ResultString = removeBlankSpaces(GivenCode, L"   ", L"", L"       ");
		ResultString = decode_Inner(ResultString, *FromMorseToEngStringDictionary);
	}

	if (InputType == IT_Korean)
	{
		ResultString = removeBlankSpaces(GivenCode, L"   ", L"     ", L"       ");
		ResultString = decode_Inner(ResultString, *FromMorseToKoreanStringDictionary);
		ResultString = hangulStringfy(ResultString);
	}

	return ResultString;
}

wstring FMorseConverter::hangulParse(wstring InString)
{
	if (!HangulParser)
	{
		return L"";
	}

	return HangulParser->Encode(InString);
}

wstring FMorseConverter::hangulStringfy(const wstring& InParsedHangulStr)
{
	if (!HangulParser)
	{
		return L"";
	}

	return HangulParser->Decode(InParsedHangulStr);
}

wstring FMorseConverter::decode_Inner(wstring InCode, const FromMorseDirctionary& InToStringDictionary)
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
				return L"잘못된 코드입니다";

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

wstring FMorseConverter::encode_Inner(wstring InString, const ToMorseDictionary& InToCodeDictionary)
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

wstring FMorseConverter::removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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

wstring FMorseConverter::addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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
