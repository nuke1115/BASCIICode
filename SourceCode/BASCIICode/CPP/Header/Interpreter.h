#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER
#include <string>
#include <unordered_map>
#include "..\Header\CommandTable.h"
#include "..\Header\Parser.h"
using namespace std;

class Interpreter
{
private:
	int* _ValueLine = nullptr;
	unordered_map<unsigned int, unsigned int> _loopMap;
	string _CommandLine;
	unsigned int _ValueIndex = 0;
	unsigned int _CommandIndex = 0;
	int _exitCode = 0;
	bool _Running = true;
public:

	Interpreter(string &rawCode);
	Interpreter(Interpreter&&) = delete;
	~Interpreter();

	void Start();

};
#endif
