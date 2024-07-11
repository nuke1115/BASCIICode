#pragma once
#include "..\CommandTable.h"
#include <stdio.h>
#include <stack>
using namespace std;
CommandTable::CommandTable()
{

}

void CommandTable::EndProgram(bool &running)
{
	running = false;
}

void CommandTable::MOVValueIndexLeft(long long& valueIndex)
{
	valueIndex--;
}

void CommandTable::MOVValueIndexRight(long long& valueIndex)
{
	valueIndex++;
}

void CommandTable::INCRValue(long long* valueLine, long long valueIndex)
{
	valueLine[valueIndex]++;
}

void CommandTable::DECRValue(long long* valueLine, long long valueIndex)
{
	valueLine[valueIndex]--;
}

void CommandTable::PrintValueByASCII(long long* valueLine, long long valueIndex)
{
	printf("%c",valueLine[valueIndex]);
}

void CommandTable::InputValueByASCII(long long* valueLine, long long valueIndex)
{
	char tmp[4];
	printf(">>");
	scanf_s("%s",&tmp,2);
	
	if (tmp[2]!='\0')
	{
		puts("문자 한개만 입력해주세요");
		InputValueByASCII(valueLine, valueIndex);
	}
	valueLine[valueIndex] = tmp[0];
}

void CommandTable::PushLoopStack(stack<int> &loopStack, int commandIndex)
{
	loopStack.push(commandIndex);
	
}

void CommandTable::JMPCommandIndex(stack<int>& loopStack, int &commandIndex)
{
	commandIndex = loopStack.top();
}

void CommandTable::PopLoopStack(stack<int>& loopStack)
{
	loopStack.pop();
}

void CommandTable::PrintValueByInteger(long long* valueLine, long long valueIndex)
{
	printf("%lld",valueLine[valueIndex]);
}
//TODO 오류 없는지 검사