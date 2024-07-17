#ifndef INTERPRETER_IMPLEMENT
#define INTERPRETER_IMPLEMENT

#include "..\Interpreter.h"


void InterpreterConstructor(struct Interpreter* interpreter, char rawCommand[], unsigned int bracketCount)
{
#pragma region initialize_variables
	interpreter->_exitCode = 0;
	UnsignedIntLoopMapConstructor(&(interpreter->_loopMap) , bracketCount);
	interpreter->_ValueLine = NULL; //할당될 예정
	interpreter->_CommandLine = NULL; //parser에서 할당될 예정
	interpreter->func_Start = Start;
	interpreter->func_InterpreterDestructor = InterpreterDestructor;
	interpreter->_Running = ctrue;
	unsigned valueLineSize = 0;
#pragma endregion

	interpreter->_exitCode = Parse(&(interpreter->_loopMap), rawCommand, &(interpreter->_CommandLine), &valueLineSize , bracketCount);


	interpreter->_ValueLine = (int*)malloc(sizeof(int) * valueLineSize);

	if (interpreter->_ValueLine == NULL)
	{
		puts("배열 할당 실패");
		interpreter->_Running = cfalse;
		return;
	}

	for (unsigned int i = 0; i < valueLineSize; i++)
	{
		interpreter->_ValueLine[i] = 0;
	}
}

void Start(struct Interpreter* interpreter)
{
	unsigned int valueIndex = 0;
	unsigned int commandIndex = 0;
	while (interpreter->_Running)
	{

		char instruction = interpreter->_CommandLine[commandIndex];

		if (instruction == 'E')
		{
			EndProgram(&(interpreter->_Running));
		}
		else if (instruction == '>')
		{
			MOVValueIndexRight(&(valueIndex));
		}
		else if (instruction == '<')
		{
			MOVValueIndexLeft(&(valueIndex));
		}
		else if (instruction == '+')
		{
			INCRValue(interpreter->_ValueLine, valueIndex);
		}
		else if (instruction == '-')
		{
			DECRValue(interpreter->_ValueLine, valueIndex);
		}
		else if (instruction == 'A')
		{
			PrintValueByASCII(interpreter->_ValueLine, valueIndex);
		}
		else if (instruction == 'S')
		{
			InputValueByASCII(interpreter->_ValueLine, valueIndex);
		}
		else if (instruction == '[')
		{
			if (interpreter->_ValueLine[valueIndex] == 0)
			{
				JMPToTail(&(interpreter->_loopMap), &(commandIndex));
			}
		}
		else if (instruction == ']')
		{
			if (interpreter->_ValueLine[valueIndex] != 0)
			{
				JMPToHead(&(interpreter->_loopMap), &(commandIndex));
			}
		}
		else if (instruction == 'D')
		{
			PrintValueByInteger(interpreter->_ValueLine, valueIndex);
		}

		commandIndex++;
	}
}

void InterpreterDestructor(struct Interpreter* interpreter)
{
	interpreter->_loopMap.func_UnsignedIntLoopMapDestructor(&(interpreter->_loopMap));

	if (interpreter->_ValueLine != NULL)
	{
		free(interpreter->_ValueLine);
	}

	if (interpreter->_CommandLine != NULL)
	{
		free(interpreter->_CommandLine);
	}

}


#endif // !INTERPRETER_IMPLEMENT
