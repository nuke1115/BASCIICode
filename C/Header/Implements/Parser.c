#ifndef PARSER_IMPLEMENT
#define PARSER_IMPLEMENT

#include "..\Parser.h"
#include <stdlib.h>
#include <stdio.h>

void ParserConstructor(struct Parser* parser, char* rawCode)
{
	parser->func_Parse = Parse;
	parser->rawCodeLength = 0;
	for (; rawCode[parser->rawCodeLength] != '\0'; parser->rawCodeLength++)
	{

	}
	parser->rawCodeLength++;

}

int Parse(struct Parser* parser, char rawCode[], char* code[], unsigned int* valueLineCnt, struct unsignedIntLoopMap* map , unsigned int bracketCount)
{
	struct UnsignedIntStack loopStack;
	UnsignedIntStackConstructor(&loopStack, bracketCount);


	long long loopStackCnt = 0;
	unsigned int codeIndex = 0 , valueLineIndexMax = 1 , valueLineIndexLengthTmp = 1 , command = 0;


	(*code) = (char*)malloc(sizeof(char) * (parser->rawCodeLength + 1));

	if (*code == NULL)
	{
		puts("�迭 �Ҵ� ����");
		return 2;
	}


	for (int i = 0; i <= parser->rawCodeLength; i++)
	{
		(*code)[i] = '\0';
	}

	while (codeIndex < parser->rawCodeLength)
	{
		command = rawCode[codeIndex] % 10;

		if (command == 0)
		{
			(*code)[codeIndex] = 'E';
		}
		else if (command == 1)
		{
			(*code)[codeIndex] = '<';
			valueLineIndexLengthTmp--;
		}
		else if (command == 2)
		{
			(*code)[codeIndex] = '>';
			valueLineIndexLengthTmp++;
		}
		else if (command == 3)
		{
			(*code)[codeIndex] = '+';
		}
		else if (command == 4)
		{
			(*code)[codeIndex] = '-';
		}
		else if (command == 5)
		{
			(*code)[codeIndex] = 'A';
		}
		else if (command == 6)
		{
			(*code)[codeIndex] = 'S';
		}
		else if (command == 7)
		{
			(*code)[codeIndex] = '[';
			loopStack.func_Push(&loopStack, codeIndex);
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

			unsigned int head = loopStack.func_Peek(&loopStack);
			loopStack.func_Pop(&loopStack);
			map->func_SetIndexOfHeadPoint(map, head);
			map->func_SetIndexOfTailPoint(map, codeIndex);

			(*code)[codeIndex] = ']';
		}
		else if (command == 9)
		{
			(*code)[codeIndex] = 'D';
		}

		if (valueLineIndexMax < valueLineIndexLengthTmp)
		{
			valueLineIndexMax = valueLineIndexLengthTmp;
		}

		codeIndex++;
	}

	loopStack.func_Destructor(&loopStack);

	if (loopStackCnt != 0)
	{
		puts("loop syntex error");
		return 1;
	}

	*valueLineCnt = valueLineIndexMax;

	return 0;
}
#endif // !PARSER_IMPLEMENT
