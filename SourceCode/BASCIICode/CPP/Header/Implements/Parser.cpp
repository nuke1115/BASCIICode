#ifndef PARSER_IMPLEMENT
#define PARSER_IMPLEMENT
#include "..\Parser.h"

int Parse(string& rawCode, string& code, unsigned int& valueLineCnt , unordered_map<unsigned int, unsigned int> & loopMap)
{
	long long loopStackCnt = 0;
	unsigned int codeIndex = 0 , command = 0 , valueLineIndexMax = 1, valueLineIndexLengthTmp = 1;

	stack<unsigned int> loopStack;

	while (codeIndex <= rawCode.length())
	{
		command = rawCode[codeIndex] % 10;

		if (command == 0)
		{
			code += 'E';
		}
		else if (command == 1)
		{
			code += '<';
			valueLineIndexLengthTmp--;

			if (valueLineIndexLengthTmp < 1)
			{
				valueLineIndexLengthTmp = -1;
				break;
			}

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
			loopStack.push(codeIndex);
		}
		else if (command == 8)
		{
			loopStackCnt--;

			if (loopStackCnt < 0)
			{
				loopStackCnt = -1;
				break;
			}

			unsigned int head = loopStack.top();
			loopStack.pop();
			loopMap[head] = codeIndex;
			loopMap[codeIndex] = head;

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

	if (valueLineIndexLengthTmp < 1)
	{
		puts("valueLine Pointer movement range error");
		return 2;
	}

	if (loopStackCnt != 0)
	{
		puts("loop syntex error");
		return 1;
	}

	valueLineCnt = valueLineIndexMax;

	return 0;
}
#endif // ! PARSER_IMPLEMENT