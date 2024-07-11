#pragma once
#include <string>
#include <stack>
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
public:

	Interpreter(string &rawCode);
	Interpreter(Interpreter&&) = delete;

	void Start();

};