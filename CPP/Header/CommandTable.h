#ifndef COMMAND_TABLE_HEADER
#define COMMAND_TABLE_HEADER
#include <stdio.h>
#include <unordered_map>
using namespace std;

void EndProgram(bool& running);

void MOVValueIndexLeft(int& valueIndex);

void MOVValueIndexRight(int& valueIndex);

void INCRValue(long long valueLine[], int valueIndex);

void DECRValue(long long valueLine[], int valueIndex);

void PrintValueByASCII(long long valueLine[], int valueIndex);

void InputValueByASCII(long long valueLine[], int valueIndex);

void JMPCommandIndexToTail(unordered_map<int,int> loopMap, int& commandIndex);

void JMPCommandIndexToHead(unordered_map<int , int> loopMap, int& commandIndex);



void PrintValueByInteger(long long valueLine[], int valueIndex);


#endif // !COMMAND_TABLE_HEADER