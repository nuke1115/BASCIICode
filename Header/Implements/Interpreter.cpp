#pragma once
#include "..\Interpreter.h"
#include "..\CommandTable.h"
#include "..\Tokenizer.h"

Interpreter::Interpreter(string &rawCode)
{
	Tokenizer tokenizer;
	_Running = true;
	//tokenize
	long long valueLineSize;
	int exitCode = tokenizer.tokenize(rawCode,_CommandLine,valueLineSize);

	if (exitCode != 0)
	{
		_Running = false;
	}

	_ValueLine = new long long[valueLineSize];

	while (valueLineSize--)
	{
		_ValueLine[valueLineSize] = 0;
	}
}

void Interpreter::Start()
{
	CommandTable commandTable;
	while (_Running&& _CommandIndex <= _CommandLine.length())
	{
		if (_CommandLine[_CommandIndex] == 'E')
		{
			commandTable.EndProgram(_Running);
		}
		else if (_CommandLine[_CommandIndex] == '>')
		{
			commandTable.MOVValueIndexRight(_ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '<')
		{
			commandTable.MOVValueIndexLeft(_ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '+')
		{
			commandTable.INCRValue(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '-')
		{
			commandTable.DECRValue(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == 'A')
		{
			commandTable.PrintValueByASCII(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == 'S')
		{
			commandTable.InputValueByASCII(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '[')
		{
			commandTable.PushLoopStack(_LoopStack, _CommandIndex);
		}
		else if (_CommandLine[_CommandIndex] == ']')
		{
			if (_ValueLine[_ValueIndex] == 0)
			{
				commandTable.PopLoopStack(_LoopStack);
			}
			else
			{
				commandTable.JMPCommandIndex(_LoopStack, _CommandIndex);
			}
		}
		else if (_CommandLine[_CommandIndex] == 'D')
		{
			commandTable.PrintValueByInteger(_ValueLine, _ValueIndex);
		}

		_CommandIndex++;
	}
	
}

Interpreter::~Interpreter()
{
	delete[] _ValueLine;
}