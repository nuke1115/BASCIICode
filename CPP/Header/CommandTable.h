#ifndef COMMAND_TABLE_HEADER
#define COMMAND_TABLE_HEADER
#include <stdio.h>
#include <unordered_map>
#include <climits>
using namespace std;


void EndProgram(bool& running);


#pragma region ValueIndexMovement

void MOVValueIndexLeft(unsigned int& valueIndex);

void MOVValueIndexRight(unsigned int& valueIndex);

#pragma endregion


#pragma region ValueIncreasement/Decreasement

void INCRValue(int valueLine[], unsigned int valueIndex);

void DECRValue(int valueLine[], unsigned int valueIndex);

#pragma endregion


#pragma region I/O

void InputValueByASCII(int valueLine[], unsigned int valueIndex);

void PrintValueByASCII(int valueLine[], unsigned int valueIndex);

void PrintValueByInteger(int valueLine[], unsigned int valueIndex);

#pragma endregion



#pragma region CommandIndexMovement

void JMPCommandIndexToTail(unordered_map<unsigned int, unsigned int> loopMap, unsigned int& commandIndex);

void JMPCommandIndexToHead(unordered_map<unsigned int, unsigned int> loopMap, unsigned int& commandIndex);

#pragma endregion




#endif // !COMMAND_TABLE_HEADER