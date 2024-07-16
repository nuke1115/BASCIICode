#ifndef INTERPRETER_IMPLEMENT
#define INTERPRETER_IMPLEMENT

#include "..\Interpreter.h"
#include "..\Parser.h"
#include "..\CommandTable.h"
#include <stdio.h>
#include <stdlib.h>

void InterpreterConstructor(struct Interpreter* interpreter, char rawCommand[], unsigned int bracketCount)
{
#pragma region initialize_variables
	interpreter->_exitCode = 0;
	UnsignedIntLoopMapConstructor(&(interpreter->_loopMap) , bracketCount);
	interpreter->_ValueLine = NULL; //할당될 예정
	interpreter->_CommandLine = NULL; //parser에서 할당될 예정
	interpreter->func_Start = Start;
	interpreter->func_InterpreterDestructor = InterpreterDestructor;
	interpreter->_ValueIndex = 0;
	interpreter->_CommandIndex = 0;
	interpreter->_Running = ctrue;
#pragma endregion

	unsigned valueLineSize = 0;

	struct Parser parser;
	ParserConstructor(&parser, rawCommand);
	interpreter->_exitCode = parser.func_Parse(&parser, rawCommand, &(interpreter->_CommandLine), &valueLineSize , &(interpreter->_loopMap), bracketCount);


	interpreter->_ValueLine = (int*)malloc(sizeof(int) * valueLineSize);

	if (interpreter->_ValueLine == NULL)
	{
		puts("배열 할당 실패");
		interpreter->_Running = cfalse;
		return;
	}

	for (int i = 0; i < valueLineSize; i++)
	{
		interpreter->_ValueLine[i] = 0;
	}


	
}

void Start(struct Interpreter* interpreter)
{

	while (interpreter->_Running)
	{
		//logics

		char instruction = interpreter->_CommandLine[interpreter->_CommandIndex];

		//파라미터 뜯어고치자
		//일단 잠시 어디 좀 다녀오고
		if (instruction == 'E')
		{
			EndProgram(&(interpreter->_Running));
		}
		else if (instruction == '>')
		{
			MOVValueIndexRight(&(interpreter->_ValueIndex));
		}
		else if (instruction == '<')
		{
			MOVValueIndexLeft(&(interpreter->_ValueIndex));
		}
		else if (instruction == '+')
		{
			INCRValue(interpreter->_ValueLine, interpreter->_ValueIndex);
		}
		else if (instruction == '-')
		{
			DECRValue(interpreter->_ValueLine, interpreter->_ValueIndex);
		}
		else if (instruction == 'A')
		{
			PrintValueByASCII(interpreter->_ValueLine, interpreter->_ValueIndex);
		}
		else if (instruction == 'S')
		{
			InputValueByASCII(interpreter->_ValueLine, interpreter->_ValueIndex);
		}
		else if (instruction == '[')
		{
			if (interpreter->_ValueLine[interpreter->_ValueIndex] == 0)
			{
				JMPToTail(&(interpreter->_loopMap), &(interpreter->_CommandIndex));
			}
		}
		else if (instruction == ']')
		{
			if (interpreter->_ValueLine[interpreter->_ValueIndex] != 0)
			{
				JMPToHead(&(interpreter->_loopMap), &(interpreter->_CommandIndex));
			}
		}
		else if (instruction == 'D')
		{
			PrintValueByInteger(interpreter->_ValueLine, interpreter->_ValueIndex);
		}

		interpreter->_CommandIndex++;
	}
}

void InterpreterDestructor(struct Interpreter* interpreter)
{
	interpreter->_loopMap.func_UnsingedIntLoopMapDestructor(&(interpreter->_loopMap));

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
