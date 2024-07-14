#ifndef INTERPRETER_IMPLEMENT
#define INTERPRETER_IMPLEMENT
#include "..\Interpreter.h"

Interpreter::Interpreter(string& rawCode)
{

	_Running = true;
	int valueLineSize;

	_exitCode = Parse(rawCode, _CommandLine, valueLineSize , _loopMap);

	if (_exitCode != 0)
	{
		_Running = false;
		return;
	}

	_ValueLine = new long long[valueLineSize];

	while (valueLineSize--)
	{
		_ValueLine[valueLineSize] = 0;
	}
}

void Interpreter::Start()
{
	while (_Running && _CommandIndex <= _CommandLine.length())
	{
		if (_CommandLine[_CommandIndex] == 'E')
		{	
			EndProgram(_Running);
		}
		else if (_CommandLine[_CommandIndex] == '>')
		{
			MOVValueIndexRight(_ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '<')
		{
			MOVValueIndexLeft(_ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '+')
		{
			INCRValue(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '-')
		{
			DECRValue(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == 'A')
		{
			PrintValueByASCII(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == 'S')
		{
			InputValueByASCII(_ValueLine, _ValueIndex);
		}
		else if (_CommandLine[_CommandIndex] == '[')
		{
			if (_ValueLine[_ValueIndex] == 0)
			{
				JMPCommandIndexToTail(_loopMap, _CommandIndex);
			}
		}
		else if (_CommandLine[_CommandIndex] == ']')
		{
			if (_ValueLine[_ValueIndex] != 0)
			{
				JMPCommandIndexToHead(_loopMap, _CommandIndex);
			}

		}
		else if (_CommandLine[_CommandIndex] == 'D')
		{
			PrintValueByInteger(_ValueLine, _ValueIndex);
		}

		_CommandIndex++;
	}

}

Interpreter::~Interpreter()
{
	if (_exitCode == 0)
	{
		delete[] _ValueLine;
	}

}
#endif // !INTERPRETER_IMPLEMENT
