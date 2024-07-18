#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER
#include "..\Header\Definitions.h"
#include "..\Header\LoopMap.h"
#include "..\Header\Parser.h"
#include "..\Header\CommandTable.h"
#include <stdio.h>
#include <stdlib.h>


void Start(struct Interpreter* interpreter);

void InterpreterConstructor(struct Interpreter* interpreter, char rawCommand[], unsigned int bracketCount);
void InterpreterDestructor(struct Interpreter* interpreter);

struct Interpreter
{
	struct UnsignedIntLoopMap _loopMap;
	int* _ValueLine;
	char* _CommandLine;
	void (*func_Start)(struct Interpreter* interpreter);
	void (*func_InterpreterDestructor)(struct Interpreter* interpreter);
	int _exitCode;
	cBool _Running;
};
#endif // !INTERPRETER_HEADER
