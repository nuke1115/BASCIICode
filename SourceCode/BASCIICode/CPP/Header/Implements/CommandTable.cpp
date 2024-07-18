#ifndef COMMAND_TABLE_IMPLEMENT
#define COMMAND_TABLE_IMPLEMENT
#include "..\CommandTable.h"


void EndProgram(bool& running)
{
	running = false;
}

#pragma region ValueIndexMovement

void MOVValueIndexLeft(unsigned int& valueIndex)
{
	valueIndex--;
}

void MOVValueIndexRight(unsigned int& valueIndex)
{
	valueIndex++;
}

#pragma endregion



#pragma region ValueIncreasement/Decreasement

void INCRValue(int valueLine[], unsigned int valueIndex)
{
	valueLine[valueIndex]++;
}

void DECRValue(int valueLine[], unsigned int valueIndex)
{
	valueLine[valueIndex]--;
}

#pragma endregion



#pragma region I/O

void InputValueByASCII(int valueLine[], unsigned int valueIndex)
{
	char tmp[4] = "aaa";
	printf(">>");
	scanf_s("%s", tmp, (unsigned int)sizeof(tmp));

	if (tmp[1] != '\0')
	{
		while (getchar() != '\n') {}
		puts("문자 한개만 입력해주세요");
		InputValueByASCII(valueLine, valueIndex);
	}
	else
	{
		while (getchar() != '\n') {}
		valueLine[valueIndex] = tmp[0];
	}
}

void PrintValueByASCII(int valueLine[], unsigned int valueIndex)
{
	int tmp = valueLine[valueIndex];
	char buffer = tmp > CHAR_MAX ? CHAR_MAX : tmp;
	printf("%c", buffer);
}

void PrintValueByInteger(int valueLine[], unsigned int valueIndex)
{
	printf("%d", valueLine[valueIndex]);
}

#pragma endregion


#pragma region CommandIndexMovement

void JMPCommandIndexToTail(unordered_map<unsigned int, unsigned int> loopMap, unsigned int& commandIndex)
{
	commandIndex = loopMap[commandIndex];
}

void JMPCommandIndexToHead(unordered_map<unsigned int, unsigned int> loopMap, unsigned int& commandIndex)
{
	commandIndex = loopMap[commandIndex];
}

#pragma endregion



#endif // !COMMAND_TABLE_IMPLEMENT