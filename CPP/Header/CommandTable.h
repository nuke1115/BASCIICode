#ifndef COMMAND_TABLE_HEADER
#define COMMAND_TABLE_HEADER
#include <stdio.h>
#include <unordered_map>
#include <climits>
using namespace std;

void EndProgram(bool& running);

void MOVValueIndexLeft(unsigned int& valueIndex);

void MOVValueIndexRight(unsigned int& valueIndex);

void INCRValue(int valueLine[], unsigned int valueIndex);

void DECRValue(int valueLine[], unsigned int valueIndex);

void PrintValueByASCII(int valueLine[], unsigned int valueIndex);

void InputValueByASCII(int valueLine[], unsigned int valueIndex);

void JMPCommandIndexToTail(unordered_map<int,int> loopMap, unsigned int& commandIndex);

void JMPCommandIndexToHead(unordered_map<int , int> loopMap, unsigned int& commandIndex);

void PrintValueByInteger(int valueLine[], unsigned int valueIndex);

#endif // !COMMAND_TABLE_HEADER