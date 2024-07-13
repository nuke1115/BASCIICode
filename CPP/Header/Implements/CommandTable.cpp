#ifndef COMMAND_TABLE_IMPLEMENT
#define COMMAND_TABLE_IMPLEMENT
#include "..\CommandTable.h"


void EndProgram(bool& running)
{
	running = false;
}

void MOVValueIndexLeft(long long& valueIndex)
{
	valueIndex--;
}

void MOVValueIndexRight(long long& valueIndex)
{
	valueIndex++;
}

void INCRValue(long long valueLine[], long long valueIndex)
{
	(valueLine[valueIndex]) += 1;
}

void DECRValue(long long valueLine[], long long valueIndex)
{
	(valueLine[valueIndex]) -= 1;
}

void PrintValueByASCII(long long valueLine[], long long valueIndex)
{
	char buffer = valueLine[valueIndex];
	printf("%c", buffer);
}

void InputValueByASCII(long long valueLine[], long long valueIndex)
{
	char tmp[4];
	while (getchar() != '\n') {}
	printf(">>");
	scanf_s("%s", tmp, 2);


	if (tmp[1] != '\0')
	{
		puts("문자 한개만 입력해주세요");
		InputValueByASCII(valueLine, valueIndex);
	}
	else
	{
		valueLine[valueIndex] = tmp[0];
	}
}

void PushLoopStack(stack<int>& loopStack, int commandIndex)
{
	loopStack.push(commandIndex);

}

void JMPCommandIndex(stack<int>& loopStack, int& commandIndex)
{
	commandIndex = loopStack.top();
}

void PopLoopStack(stack<int>& loopStack)
{
	loopStack.pop();
}

void PrintValueByInteger(long long valueLine[], long long valueIndex)
{
	printf("%lld", valueLine[valueIndex]);
}
#endif // !COMMAND_TABLE_IMPLEMENT
