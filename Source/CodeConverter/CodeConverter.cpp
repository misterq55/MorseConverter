#include "CodeConverter.h"

//wstring FCodeConverter::removeBlankSpaces(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
//{
//	wstring BlankConvertedString;
//
//	size_t LetterIntervalSize = LetterInterval.size();
//	size_t SyllableIntervalSize = SyllableInterval.size();
//	size_t WordIntervalSize = WordInterval.size();
//
//	int BlankCounter = 0;
//
//	for (unsigned int i = 0; i < InCode.size();)
//	{
//		if (InCode[i] == L' ')
//		{
//			BlankCounter = i;
//
//			int BlankInterval = 0;
//
//			while (InCode[BlankCounter] == L' ')
//			{
//				BlankInterval = BlankCounter - i;
//				BlankCounter++;
//			}
//
//			if (BlankInterval == LetterIntervalSize - 1)
//				BlankConvertedString += L' ';
//			else if (BlankInterval == SyllableIntervalSize - 1)
//				BlankConvertedString += L'|';
//			else if (BlankInterval == WordIntervalSize - 1)
//				BlankConvertedString += L'/';
//
//			i = BlankCounter;
//		}
//		else
//			BlankConvertedString += InCode[i++];
//	}
//
//	return BlankConvertedString;
//}
//
//wstring FCodeConverter::addBlankSpaces(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
//{
//	wstring BlankConvertedCode;
//
//	BlankConvertedCode += InString[0];
//
//	for (unsigned int i = 1; i < InString.size(); i++)
//	{
//		if (InString[i] == L' ')
//		{
//			BlankConvertedCode += LetterInterval;
//		}
//		else if (InString[i] == L'/')
//		{
//			BlankConvertedCode += WordInterval;
//		}
//		else if (InString[i] == L'|')
//		{
//			if (i != InString.size() - 1)
//				BlankConvertedCode += SyllableInterval;
//		}
//		else
//		{
//			if (BlankConvertedCode.back() != L' ')
//				BlankConvertedCode += L" ";
//			BlankConvertedCode += InString[i];
//		}
//	}
//
//	return BlankConvertedCode;
//}
