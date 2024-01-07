#include "LatinAlphabetMorseConverter.h"
#include "../CodeBook/MorseCodeBook/LatinAlphbetMorseCodeBook/LatinAlphbetMorseCodeBook.h"

FLatinAlphabetMorseConverter::FLatinAlphabetMorseConverter()
	: FMorseConverter()
{
	
}

FLatinAlphabetMorseConverter::~FLatinAlphabetMorseConverter()
{
}

void FLatinAlphabetMorseConverter::Initilize()
{
	MorseCodeBook = new FLatinAlphbetMorseCodeBook("Json/MorseEnglishCodeBook.json");
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
		ResultCode = encode_Inner(GivenString, MorseCodeBook);
		ResultCode = addBlankSpaces(ResultCode, L"   ", L"", L"       ");
	}

	ResultCode += L'\0';

	return ResultCode;
}

wstring FLatinAlphabetMorseConverter::Decode(const wstring& InCode)
{
	wstring ResultString;
	wstring GivenCode = InCode;

	if (GivenCode.back() != L'\0')
		GivenCode += L'\0';

	ResultString = removeBlankSpaces(GivenCode, L"   ", L"", L"       ");
	ResultString = decode_Inner(ResultString, MorseCodeBook);

	return ResultString;
}

//wstring FLatinAlphabetMorseConverter::decode_Inner(wstring InCode, FCodeBook* InCodeBook)
//{
//	wstring GivenCode = InCode;
//	wstring ConvertedString;
//
//	int wordIndex = 0;
//	int wordValue = 0;
//
//	for (unsigned int i = 0; i < GivenCode.size(); i++)
//	{
//		int value = -1;
//
//		if (GivenCode.at(i) == L'.')
//			value = 1;
//		else if (GivenCode.at(i) == L'-')
//			value = 2;
//		else // ' ' or '/'
//		{
//			ConvertedString += InCodeBook->Decode(wordValue);
//
//			if (GivenCode.at(i) == L'/')
//				ConvertedString += L' ';
//
//			if (GivenCode.at(i) == L'|')
//				ConvertedString += GivenCode.at(i);
//
//			wordIndex = 0;
//			wordValue = 0;
//
//			continue;
//		}
//
//		wordValue += value * (int)(pow(3, wordIndex++));
//	}
//
//	ConvertedString += L'\0';
//
//	return ConvertedString;
//}
//
//wstring FLatinAlphabetMorseConverter::encode_Inner(wstring InString, FCodeBook* InCodeBook)
//{
//	wstring ConvertedResult;
//
//	ConvertedResult += InCodeBook->Encode(InString[0]);
//
//	for (unsigned int i = 1; i < InString.size(); i++)
//	{
//		if (InString[i] == L'|')
//		{
//			ConvertedResult += InString[i];
//			continue;
//		}
//
//		wstring ContertedCode = InCodeBook->Encode(InString[i]);
//
//		if ((ContertedCode != L"/" && ConvertedResult.back() != L'/') && ConvertedResult.back() != L'|')
//			ConvertedResult += L' ';
//
//		if (ContertedCode == L"/" && ConvertedResult.back() == L'|')
//			ConvertedResult.pop_back();
//
//		ConvertedResult += ContertedCode;
//	}
//
//	return ConvertedResult;
//}
