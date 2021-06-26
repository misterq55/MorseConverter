#include <string>
#include <map>
#include <math.h>

using std::string;
typedef std::map<int, char> FromMorseDictionary;
typedef std::map<char, string> ToMorseDictionary;

class MorseConverter
{
private:
	MorseConverter();

public:
	~MorseConverter();

public:
	static MorseConverter& Get();
	bool Init();
	string ConvertFromMorseCode(string MorseStr);
	string ConvertToMorseCode(string Str);

private:
	FromMorseDictionary FromMorseDic;
	ToMorseDictionary ToMorseDic;
};

