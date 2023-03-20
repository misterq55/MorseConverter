#include "MorseConverter.h"

FMorseConverter::FMorseConverter()
{
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
		{0xB, L"ㄹㅂ"},
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
}

FMorseConverter::~FMorseConverter()
{
	delete FirstConsonantCodeToLetter;
	delete MiddleVowerCodeToLetter;
	delete LastConsonantCodeToLetter;

	delete JaeumOnlyCodeToLetter;

	delete FirstConsonantLetterToCode;
	delete MiddleVowerLetterToCode;
	delete LastConsonantLetterToCode;

	delete JaeumOnlyLetterCode;

	delete FromMorseToEngStringDictionary;
	delete FromMorseToKoreanStringDictionary;

	delete EngStringToMorseDictionary;
	delete KoreanStringToMorseDictionary;
}

wstring FMorseConverter::ConvertCodeToString(const wstring& InCode)
{
	if (InputType == IT_None)
		return L"입력 언어가 설정되지 않았습니다.";

	wstring ResultString;
	wstring GivenCode = InCode;
	
	if (GivenCode.back() != L'\0')
		GivenCode += L'\0';

	if (InputType == IT_Engish)
	{
		ResultString = BlankConvertCodeToString(GivenCode, L"   ", L"", L"       ");
		ResultString = InnerConvertCodeToString(ResultString, *FromMorseToEngStringDictionary);
	}

	if (InputType == IT_Korean)
	{
		ResultString = BlankConvertCodeToString(GivenCode, L"   ", L"     ", L"       ");
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
			return L"현재 모드와 입력된 언어가가 다릅니다.";

		ResultCode = InnerConvertStringToCode(GivenString, *EngStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"   ", L"", L"       ");
	}

	if (!EngCount && KoreanCount && InputType == IT_Korean)
	{
		if (InputType != IT_Korean)
			return L"현재 모드와 입력된 언어가가 다릅니다.";

		ResultCode = InnerConvertStringToCode(HangulParser(GivenString), *KoreanStringToMorseDictionary);
		ResultCode = BlankConvertStringToCode(ResultCode, L"   ", L"     ", L"       ");
	}

	ResultCode += L'\0';

	return ResultCode;
}

wstring FMorseConverter::HangulParser(wstring InString)
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
			HanguleJamoParser(int(InString[i]) - L'가', L'까' - L'가', Range, Ramnant);

			Range += L'가';
			KoreanCodeToLetterDictionary::iterator FinderIterator = FirstConsonantCodeToLetter->find(Range);
			if (FinderIterator != FirstConsonantCodeToLetter->end())
				Result += FirstConsonantCodeToLetter->at(Range);

			HanguleJamoParser(int(InString[i]) - Range, L'개' - L'가', Range, Ramnant);

			Result += MiddleVowerCodeToLetter->at(Range);
			Result += LastConsonantCodeToLetter->at(Ramnant);
		}
		else if (InString[i] >= L'ㄱ' && InString[i] <= L'ㅎ')
		{
			HanguleJamoParser(int(InString[i]) - L'ㄱ', L'ㄲ' - L'ㄱ', Range, Ramnant);
			Range *= (L'ㄲ' - L'ㄱ');
			Range += L'ㄱ';
			Result += JaeumOnlyCodeToLetter->at(Range);
		}
		else if (InString[i] >= L'ㅏ' && InString[i] <= L'ㅣ')
		{
			HanguleJamoParser(int(InString[i]) - L'ㅏ', L'ㅐ' - L'ㅏ', Range, Ramnant);
			Range *= (L'개' - L'가');
			Result += MiddleVowerCodeToLetter->at(Range);
		}
		else
			Result += InString[i];

		Result += L'|';
	}

	return Result;
}

void FMorseConverter::HanguleJamoParser(int ConvertedNum, int Divider, int& OutRange, int& OutRamnant)
{
	int Quotient = ConvertedNum / Divider;
	OutRange = Quotient * Divider;
	OutRamnant = ConvertedNum % Divider;
}

wstring FMorseConverter::HangulStringfy(const wstring& InParsedHangulStr)
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

			if (FirstConsonantLetterToCode->find(FirstConsonantLetter) != FirstConsonantLetterToCode->end())
				FirstConsonantValue = FirstConsonantLetterToCode->at(FirstConsonantLetter);

			while (InParsedHangulStr[SubIndex] >= L'ㅏ' && InParsedHangulStr[SubIndex] <= L'ㅣ')
				MiddleVowerLetter += InParsedHangulStr[SubIndex++];
			
			// 초성이 없다면 중성만 입력
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

			// 중성이 없다면 초성만 입력
			if (MiddleVowerLetter == L"")
			{
				if (MoeumOnlyLetterCode->find(FirstConsonantLetter) != JaeumOnlyLetterCode->end())
					StringfiedResult += JaeumOnlyLetterCode->at(FirstConsonantLetter);

				if (InParsedHangulStr[Index] == L' ')
					StringfiedResult += L' ';

				SubIndex = Index++ + 1;

				continue;
			}

			while (InParsedHangulStr[SubIndex] >= L'ㄱ' && InParsedHangulStr[SubIndex] <= L'ㅎ')
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

wstring FMorseConverter::InnerConvertCodeToString(wstring InCode, const FromMorseDirctionary& InToStringDictionary)
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

wstring FMorseConverter::InnerConvertStringToCode(wstring InString, const ToMorseDictionary& InToCodeDictionary)
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

wstring FMorseConverter::BlankConvertCodeToString(wstring InCode, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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

wstring FMorseConverter::BlankConvertStringToCode(wstring InString, const wstring& LetterInterval, const wstring& SyllableInterval, const wstring& WordInterval)
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
