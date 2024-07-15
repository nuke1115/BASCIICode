#ifndef COMMAND_TABLE_IMPLEMENT
#define COMMAND_TABLE_IMPLEMENT
#include "..\CommandTable.h"

void EndProgram(bool& running)
{
	running = false;
}

void MOVValueIndexLeft(unsigned int& valueIndex)
{
	valueIndex--;
}

void MOVValueIndexRight(unsigned int& valueIndex)
{
	valueIndex++;
}

void INCRValue(int valueLine[], unsigned int valueIndex)
{
	(valueLine[valueIndex]) += 1;
}

void DECRValue(int valueLine[], unsigned int valueIndex)
{
	(valueLine[valueIndex]) -= 1;
}

void PrintValueByASCII(int valueLine[], unsigned int valueIndex)
{
	int tmp = valueLine[valueIndex];
	char buffer = tmp > CHAR_MAX ? CHAR_MAX : tmp;
	printf("%c", buffer);
}

void InputValueByASCII(int valueLine[], unsigned int valueIndex)
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


void JMPCommandIndexToTail(unordered_map<int, int> loopMap, unsigned int& commandIndex)
{
	commandIndex = loopMap[commandIndex];
}

void JMPCommandIndexToHead(unordered_map<int, int> loopMap, unsigned int& commandIndex)
{
	commandIndex = loopMap[commandIndex];
}

void PrintValueByInteger(int valueLine[], unsigned int valueIndex)
{
	printf("%d", valueLine[valueIndex]);
}
#endif // !COMMAND_TABLE_IMPLEMENT