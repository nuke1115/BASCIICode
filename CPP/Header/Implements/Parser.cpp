#ifndef PARSER_IMPLEMENT
#define PARSER_IMPLEMENT
#include "..\Parser.h"

int Parse(string& rawCode, string& code, int& valueLineCnt , unordered_map<int,int> & loopMap)
{
	int codeIndex = 0, valueLineIndexMax = 1, valueLineIndexLengthTmp = 1, loopStackCnt = 0, command = -1;
	stack<int> loopStack;

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
			int head = loopStack.top();
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

	if (loopStackCnt != 0)
	{
		printf("loop syntex error");
		return 1;
	}

	valueLineCnt = valueLineIndexMax;

	return 0;
}
#endif // ! PARSER_IMPLEMENT