#pragma once

#include "../CodeConverter/CodeConverter.h"

class FHangulParserCodeBook;
class FHangulParser :
    public ICodeConverter
{
public:
  FHangulParser();
  virtual ~FHangulParser();

public:
  virtual void Initilize();
  virtual wstring Encode(const wstring& InString);
  virtual wstring Decode(const wstring& InParsedHangulStr);

private:
  void hanguleJamoParse(int ConvertedNum, int Divider, int& OutRange, int& OutRamnant);

private:
  FHangulParserCodeBook* FirstConsonantCodeBook;
  FHangulParserCodeBook* MiddleVowerCodeBook;
  FHangulParserCodeBook* LastConsonantCodeBook;
  FHangulParserCodeBook* JaeumOnlyCodeBook;
  FHangulParserCodeBook* MoeumOnlyCodeBook;
};

