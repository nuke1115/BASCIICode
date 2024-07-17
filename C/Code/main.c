#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "..\Header\Definitions.h"
#include "..\Header\Interpreter.h"
char extension[] = ".BFAC";
#pragma warning(disable:4996)


int EndsWith(char target[], char suffix[])
{
	size_t targetLength = 0, suffixLength = 5;

	for (; target[targetLength] != '\0'; ++targetLength){}

	if (suffixLength <= 0)
	{
		return 2;
	}

	if (targetLength < suffixLength)
	{
		return 1;
	}

	for (size_t targetIndex = targetLength - suffixLength, suffixIndex = 0; suffixIndex < suffixLength; suffixIndex++, targetIndex++)
	{
		if (target[targetIndex] != suffix[suffixIndex])
		{
			return 3;
		}
	}
	return 0;
}

int LoadCodeFile(char *rawCode[] , unsigned int *bracketCount)
{
	FILE* fp = NULL;
	char path[512];
	unsigned long codeLength = 0;


	printf(".BFAC로 끝나는 코드 파일의 주소를 입력: ");
	scanf_s("%[^\n]s", path, (unsigned int)sizeof(path));

	if (EndsWith(path, extension))
	{
		puts("파일 확장자 오류");
		return 3;
	}
	

	fp = fopen(path, "r");


	if (fp == NULL)
	{
		puts("파일 열기 실패");
		return 1;
	}

	while (ctrue)
	{
		char ch = fgetc(fp);

		if (ch != 10)
		{
			if (ch%10 == 7 || ch%10 == 8)
			{
				(*bracketCount)++;
			}

			codeLength++;
		}

		if (ch == EOF)
		{
			break;
		}

	}

	if ((*bracketCount) & 1)
	{
		puts("괄호 문법 오류");
		return 6;
	}

	if ((long long)codeLength+2 >= UINT_MAX)
	{
		puts("코드 길이 최대치 도달");
		return 5;
	}

	rewind(fp);
	(*rawCode) = (char*)malloc(sizeof(char) * (codeLength + 1));


	if ((*rawCode) == NULL)
	{
		puts("배열 할당 실패");
		return 4;
	}

	for (unsigned int i = 0; i <= codeLength; i++)
	{
		(*rawCode)[i] = '\0';
	}

	unsigned int Cindex = 0;
	while (Cindex < codeLength)
	{
		char ch = fgetc(fp);

		if (ch == EOF)
		{
			break;
		}

		if (ch != 10)
		{
			(*rawCode)[Cindex] = ch;
			Cindex++;
		}
	}

	fclose(fp);


	return 0;
}


int main()
{
	struct Interpreter interpreter;
	char* rawCode = NULL;

	unsigned int bracketCount = 0;
	int exitCode = LoadCodeFile(&rawCode, &bracketCount);

	if (exitCode == 0)
	{
		InterpreterConstructor(&interpreter, rawCode, bracketCount);
		interpreter.func_Start(&interpreter);

		interpreter.func_InterpreterDestructor(&interpreter);
	}

	if (rawCode != NULL)
	{
		free(rawCode);
	}

	return 0;
}