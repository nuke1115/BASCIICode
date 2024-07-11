#pragma once
#include <stack>
using namespace std;
class CommandTable
{
private:
public:

	CommandTable();

	void EndProgram(bool &running);
	void MOVValueIndexLeft(long long &valueIndex);
	void MOVValueIndexRight(long long &valueIndex);
	void INCRValue(long long *valueLine , long long valueIndex);
	void DECRValue(long long* valueLine, long long valueIndex);
	void PrintValueByASCII(long long *valueLine , long long valueIndex);
	void InputValueByASCII(long long* valueLine, long long valueIndex);
	void PushLoopStack(stack<int>& loopStack, int commandIndex);
	void JMPCommandIndex(stack<int>& loopStack, int &commandIndex);
	void PopLoopStack(stack<int>& loopStack);
	void PrintValueByInteger(long long* valueLine, long long valueIndex);
};