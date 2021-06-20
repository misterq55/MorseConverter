#include "MorseConverter.h"

MorseConverter::MorseConverter()
{
  Init();
}

MorseConverter::~MorseConverter()
{
}

MorseConverter& MorseConverter::Get()
{
	static MorseConverter Instance;
	return Instance;
}

bool MorseConverter::Init()
{
  // . 1
  // - 2

  FromMorseDic = {
    {7, 'A'}, // 1 2
    {41, 'B'}, // 2 1 1 1
    {50, 'C'}, // 2 1 2 1
    {14, 'D'}, // 2 1 1
    {1, 'E'}, // 1
    {49, 'F'}, // 1 1 2 1
    {17, 'G'}, // 2 2 1
    {40, 'H'}, // 1 1 1 1
    {4, 'I'}, // 1 1
    {79, 'J'}, // 1 2 2 2
    {23, 'K'}, // 2 1 2
    {43, 'L'}, // 1 2 1 1
    {8, 'M'}, // 2 2
    {5, 'N'}, // 2 1
    {26, 'O'}, // 2 2 2
    {52, 'P'}, // 1 2 2 1
    {71, 'Q'}, // 2 2 1 2
    {16, 'R'}, // 1 2 1
    {13, 'S'}, // 1 1 1
    {2, 'T'}, // 2
    {22, 'U'}, // 1 1 2
    {67, 'V'}, // 1 1 1 2
    {25, 'W'}, // 1 2 2
    {68, 'X'}, // 2 1 1 2
    {77, 'Y'}, // 2 1 2 2
    {44, 'Z'}, // 2 2 1 1

    {241, '1'}, // 1 2 2 2 2
    {238, '2'}, // 1 1 2 2 2
    {229, '3'}, // 1 1 1 2 2
    {202, '4'}, // 1 1 1 1 2
    {121, '5'}, // 1 1 1 1 1
    {122, '6'}, // 2 1 1 1 1
    {125, '7'}, // 2 2 1 1 1
    {134, '8'}, // 2 2 2 1 1
    {161, '9'}, // 2 2 2 2 1
    {242, '0'}, // 2 2 2 2 2
  };

  ToMorseDic = {
    {'A', string(".-")},
    {'B', string("-...")},
    {'C', string("-.-.")},
    {'D', string("-..")},
    {'E', string(".")},

    {'F', string("..-.")},
    {'G', string("--.")},
    {'H', string("....")},
    {'I', string(".---")},
    {'J', string(".---")},

    {'K', string("-.-")},
    {'L', string(".-..")},
    {'M', string("--")},
    {'N', string("-.")},
    {'O', string("---")},

    {'P', string(".--.")},
    {'Q', string("--.-")},
    {'R', string(".-.")},
    {'S', string("...")},
    {'T', string("-")},

    {'U', string("..-")},
    {'V', string("...-")},
    {'W', string(".--")},
    {'X', string("-..-")},
    {'Y', string("-.--")},
    {'Z', string("--..")},

    {'1', string(".----")},
    {'2', string("..---")},
    {'3', string("...--")},
    {'4', string("....-")},
    {'5', string(".....")},

    {'6', string("-....")},
    {'7', string("--...")},
    {'8', string("---..")},
    {'9', string("----.")},
    {'0', string("-----")},

    {' ', string("/")},
  };

	return true;
}

string MorseConverter::ConvertFromMorseCode(string MorseStr)
{
  MorseStr += ' ';

  string Result;

  int wordIndex = 0;
  int wordValue = 0;

  unsigned int length = MorseStr.length();

  for (unsigned int i = 0; i < length; i++)
  {
    int value = -1;
    if (MorseStr[i] == '.')
      value = 1;
    else if (MorseStr[i] == '-')
      value = 2;
    else if (MorseStr[i] == ' ')
    {
      Result += FromMorseDic[wordValue];

      wordIndex = 0;
      wordValue = 0;

      continue;
    }
    else if (MorseStr[i] == '/')
    {
      Result += ' ';

      wordIndex = 0;
      wordValue = 0;
    }

    wordValue += value * (int)(pow(3, wordIndex++));
  }

	return Result;
}

string MorseConverter::ConvertToMorseCode(string Str)
{
  string Result;

  unsigned int length = Str.length();

  for (unsigned int i = 0; i < length; i++)
  {
    if ('a' <= Str[i] && 'z' >= Str[i])
    {
      Str[i] -= ' ';
    }

    Result += ToMorseDic[Str[i]] + ' ';
  }

  return Result;
}
