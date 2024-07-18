#ifndef PARSER_HEADER
#define PARSER_HEADER
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int Parse(string& rawCode, string& code, unsigned int& valueLineCnt, unordered_map<unsigned int, unsigned int>& loopMap);
#endif // !PARSER_HEADER
