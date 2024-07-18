#ifndef PARSER_HEADER
#define PARSER_HEADER
#include "..\Header\Stack.h"
#include "..\Header\LoopMap.h"
#include <stdlib.h>
#include <stdio.h>

int Parse (struct UnsignedIntLoopMap* map, char rawCode[], char* code[], unsigned int* valueLineCnt, unsigned int bracketCount);

#endif // !PARSER_HEADER
