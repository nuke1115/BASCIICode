#ifndef COMMAND_TABLE_IMPLEMENT
#define COMMAND_TABLE_IMPLEMENT
#include "..\CommandTable.h"


void EndProgram(bool& running)
{
	running = false;
}

void MOVValueIndexLeft(int& valueIndex)
{
	valueIndex--;
}

void MOVValueIndexRight(int& valueIndex)
{
	valueIndex++;
}

void INCRValue(long long valueLine[], int valueIndex)
{
	(valueLine[valueIndex]) += 1;
}

void DECRValue(long long valueLine[], int valueIndex)
{
	(valueLine[valueIndex]) -= 1;
}

void PrintValueByASCII(long long valueLine[], int valueIndex)
{
	char buffer = valueLine[valueIndex];
	printf("%c", buffer);
}

void InputValueByASCII(long long valueLine[], int valueIndex)
{
	char tmp[4];
	printf(">>");
	scanf_s("%s", tmp, 2);


	if (tmp[1] != '\0')
	{
		puts("문자 한개만 입력해주세요");
		while (getchar() != '\n') {}
		InputValueByASCII(valueLine, valueIndex);
	}
	else
	{
		valueLine[valueIndex] = tmp[0];
		while (getchar() != '\n') {}
	}
}


void JMPCommandIndexToTail(unordered_map<int, int> loopMap, int& commandIndex)
{
	commandIndex = loopMap[commandIndex];
}

void JMPCommandIndexToHead(unordered_map<int, int> loopMap, int& commandIndex)
{
	commandIndex = loopMap[commandIndex];
}



void PrintValueByInteger(long long valueLine[], int valueIndex)
{
	printf("%lld", valueLine[valueIndex]);
}
#endif // !COMMAND_TABLE_IMPLEMENT
