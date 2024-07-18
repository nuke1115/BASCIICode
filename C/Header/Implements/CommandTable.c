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

void InputValueByASCII(int valueLine[], unsigned int valueIndex)
{
	unsigned char tmp[4] = "aaa";
	printf(">>");
	scanf_s("%s", tmp, 2);

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
	unsigned char buffer = tmp > UCHAR_MAX ? UCHAR_MAX : tmp;
	printf("%c", buffer);
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