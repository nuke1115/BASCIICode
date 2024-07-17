#ifndef COMMAND_TABLE_IMPLEMENT
#define COMMAND_TABLE_IMPLEMENT
#include "..\CommandTable.h"


void EndProgram(cBool* running)
{
	*running = cfalse;
}


#pragma region Value_Index_Movement

void MOVValueIndexLeft(unsigned int* valueIndex)
{
	(*valueIndex)--;
}

void MOVValueIndexRight(unsigned int* valueIndex)
{
	(*valueIndex)++;
}

#pragma endregion


#pragma region Value_Increase/Decrease

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

void PrintValueByASCII(int valueLine[], unsigned int valueIndex)
{
	int tmp = valueLine[valueIndex];
	char buffer = tmp > CHAR_MAX ? CHAR_MAX : tmp;
	printf("%c", buffer);
}

void InputValueByASCII(int valueLine[], unsigned int valueIndex)
{
	char tmp[4] = "aaa";
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

void PrintValueByInteger(int valueLine[], unsigned int valueIndex)
{
	printf("%d", valueLine[valueIndex]);
}

#pragma endregion


#pragma region Command_Index_Movement

void JMPToHead(struct UnsignedIntLoopMap* map, unsigned int* commandIndex)
{
	*commandIndex = map->func_GetHeadPointThroughTail(map, *commandIndex);
}

void JMPToTail(struct UnsignedIntLoopMap* map, unsigned int* commandIndex)
{
	*commandIndex = map->func_GetTailPointThroughHead(map, *commandIndex);
}

#pragma endregion



#endif // !COMMAND_TABLE_HEADER
