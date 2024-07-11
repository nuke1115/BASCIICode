#pragma once
#include <string>
using namespace std;
class Tokenizer
{
private:
public:
	Tokenizer();
	int tokenize(string& rawCode , string &code , long long &valueLineCnt);
};