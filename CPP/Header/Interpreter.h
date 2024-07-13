#pragma once
#include <string>
#include <stack>
#include "..\Header\CommandTable.h"
#include "..\Header\Parser.h"
using namespace std;

class Interpreter
{
private:
	long long* _ValueLine = nullptr;
	long long _ValueIndex = 0;
	stack<int> _LoopStack;
	int _CommandIndex = 0;
	string _CommandLine;
	bool _Running;
	int _exitCode = 0;
public:

	Interpreter(string &rawCode);
	Interpreter(Interpreter&&) = delete;
	~Interpreter();

	void Start();

};
//TODO 스택 longlong으로 하기