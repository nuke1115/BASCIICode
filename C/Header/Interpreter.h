#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER
#include "..\Header\Definitions.h"
#include "..\Header\LoopMap.h"

void InterpreterConstructor(struct Interpreter* interpreter, char rawCommand[] , unsigned int bracketCount);
void Start(struct Interpreter* interpreter);
void InterpreterDestructor(struct Interpreter* interpreter);

struct Interpreter
{
	struct unsignedIntLoopMap _loopMap;
	int* _ValueLine;
	char* _CommandLine;
	void (*func_Start)(struct Interpreter* interpreter);
	void (*func_InterpreterDestructor)(struct Interpreter* interpreter);
	unsigned int _ValueIndex;
	unsigned int _CommandIndex;
	int _exitCode;
	cBool _Running;
};
#endif // !INTERPRETER_HEADER
