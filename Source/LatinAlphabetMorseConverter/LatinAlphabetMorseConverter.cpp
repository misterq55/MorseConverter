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
