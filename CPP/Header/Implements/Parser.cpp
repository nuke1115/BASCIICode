#pragma once
#include <string>
#include "..\Parser.h"
using namespace std;

Parser::Parser()
{

}

int Parser::Parse(string& rawCode , string &code, long long &valueLineIndex)
{
	long long codeIndex = 0 ,valueLineIndexMax = 1 , valueLineIndexLengthTmp = 1;
	int command = -1 , loopStackCnt = 0;

	while (codeIndex <= rawCode.length())
	{
		command = rawCode[codeIndex]%10;

		if (command == 0)
		{
			code += 'E';
		}
		else if (command == 1)
		{
			code += '<';
		}
		else if (command == 2)
		{
			code += '>';
			valueLineIndexLengthTmp++;
		}
		else if (command == 3)
		{
			code += '+';
		}
		else if (command == 4)
		{
			code += '-';
		}
		else if (command == 5)
		{
			code += 'A';
		}
		else if (command == 6)
		{
			code += 'S';
		}
		else if (command == 7)
		{
			code += '[';
			loopStackCnt++;
		}
		else if (command == 8)
		{
			loopStackCnt--;
			if (loopStackCnt < 0)
			{
				loopStackCnt = -1;
				break;
			}

			code += ']';
		}
		else if (command == 9)
		{
			code += 'D';
		}

		if (valueLineIndexMax < valueLineIndexLengthTmp)
		{
			valueLineIndexMax = valueLineIndexLengthTmp;
		}

		codeIndex++;
	}

	if (loopStackCnt != 0)
	{
		printf("loop syntex error at %lld?",codeIndex+1);
		return 1;
	}

	valueLineIndex = valueLineIndexMax;

	return 0;
}