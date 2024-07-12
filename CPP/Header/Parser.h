#pragma once
#include <string>
using namespace std;
class Parser
{
private:
public:
	Parser();
	int Parse(string& rawCode , string &code , long long &valueLineCnt);
};