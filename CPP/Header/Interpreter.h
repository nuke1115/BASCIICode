#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER
#include <string>
#include <unordered_map>;
#include "..\Header\CommandTable.h"
#include "..\Header\Parser.h"
using namespace std;

class Interpreter
{
private:
	int* _ValueLine = nullptr;
	unsigned int _ValueIndex = 0;
	unordered_map< int, int> _loopMap;
	unsigned int _CommandIndex = 0;
	string _CommandLine;
	bool _Running;
	int _exitCode = 0;
public:

	Interpreter(string &rawCode);
	Interpreter(Interpreter&&) = delete;
	~Interpreter();

	void Start();

};
#endif
