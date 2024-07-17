#ifndef COMMAND_TABLE_HEADER
#define COMMAND_TABLE_HEADER
#include "..\Header\Stack.h"
#include "..\Header\Definitions.h"
#include "..\Header\LoopMap.h"
#include <limits.h>
#include "..\Header\Definitions.h"
#include <stdio.h>

void EndProgram(cBool* running);

#pragma region Value_Index_Movement

void MOVValueIndexLeft(unsigned int* valueIndex);
void MOVValueIndexRight(unsigned int* valueIndex);

#pragma endregion


#pragma region Value_Increase/Decrease

void INCRValue(int valueLine[], unsigned int valueIndex);
void DECRValue(int valueLine[], unsigned int valueIndex);

#pragma endregion


#pragma region I/O

void PrintValueByASCII(int valueLine[], unsigned int valueIndex);
void InputValueByASCII(int valueLine[], unsigned int valueIndex);
void PrintValueByInteger(int valueLine[], unsigned int valueIndex);

#pragma endregion


#pragma region Command_Index_Movement

void JMPToHead(struct UnsignedIntLoopMap* map, unsigned int* commandIndex);
void JMPToTail(struct UnsignedIntLoopMap* map, unsigned int* commandIndex);

#pragma endregion




#endif // !COMMAND_TABLE_HEADER
