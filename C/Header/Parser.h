#ifndef PARSER_HEADER
#define PARSER_HEADER
#include "..\Header\Stack.h"
#include "..\Header\LoopMap.h"

void ParserConstructor(struct Parser* parser, char* rawCode);
int Parse(struct Parser* parser, char rawCode[], char* code[], unsigned int* valueLineCnt, struct unsignedIntLoopMap * map , unsigned int bracketCount);

struct Parser
{
	int (*func_Parse)(struct Parser* parser, char rawCode[], char* code[], unsigned int* valueLineCnt, struct unsignedIntLoopMap* map, unsigned int bracketCount);
	unsigned int rawCodeLength;
};
#endif // !PARSER_HEADER
