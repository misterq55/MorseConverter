#include "LatinAlphabetMorseConverter.h"
#include "../CodeBook/MorseCodeBook/MorseCodeBook.h"
#include <cmath>

FLatinAlphabetMorseConverter::FLatinAlphabetMorseConverter()
	: LatinAlphbetMorseCodeBook(nullptr)
{
	
}

FLatinAlphabetMorseConverter::~FLatinAlphabetMorseConverter()
{
	delete LatinAlphbetMorseCodeBook;
}

void FLatinAlphabetMorseConverter::Initilize()
{
	LatinAlphbetMorseCodeBook = new FMorseCodeBook("Json/MorseEnglishCodeBook.json");
}

wstring FLatinAlphabetMorseConverter::Encode(const wstring& InString)
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

		ResultCode = encode_Inner(GivenString);
		ResultCode = addBlankSpaces(ResultCode, L"   ", L"", L"       ");
	}

	ResultCode += L'\0';

	return ResultCode;
}

wstring FLatinAlphabetMorseConverter::Decode(const wstring& InCode)
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
		ResultString = decode_Inner(ResultString);
	}

	return ResultString;
}

wstring FLatinAlphabetMorseConverter::decode_Inner(wstring InCode)
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
			ConvertedString += LatinAlphbetMorseCodeBook->Decode(wordValue);

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

wstring FLatinAlphabetMorseConverter::encode_Inner(wstring InString)
{
	wstring ConvertedResult;

	ConvertedResult += LatinAlphbetMorseCodeBook->Encode(InString[0]);

	for (unsigned int i = 1; i < InString.size(); i++)
	{
		if (InString[i] == L'|')
		{
			ConvertedResult += InString[i];
			continue;
		}

		wstring ContertedCode = LatinAlphbetMorseCodeBook->Encode(InString[i]);

		if ((ContertedCode != L"/" && ConvertedResult.back() != L'/') && ConvertedResult.back() != L'|')
			ConvertedResult += L' ';

		if (ContertedCode == L"/" && ConvertedResult.back() == L'|')
			ConvertedResult.pop_back();

		ConvertedResult += ContertedCode;
	}

	return ConvertedResult;
}

wstring FLatinAlphabetMorseConverter::removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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

wstring FLatinAlphabetMorseConverter::addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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
