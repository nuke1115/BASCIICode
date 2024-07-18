#include <iostream>
#include <string>
#include <fstream>
#include "..\Header\Interpreter.h"
using namespace std;
string fileExtension = ".BFAC";

int LoadCodeFile(string &code)
{
	string filePath, tmp;
	cout << "코드가 저장되있는 .BFAC 형식의 파일 주소를 입력해주세요:";
	getline(cin,filePath);

	if (!filePath.ends_with(fileExtension))
	{
		cout << "파일 확장자가 잘못되었습니다.";
		return 1;
	}

	ifstream codeFile;
	codeFile.open(filePath);

	if (!codeFile.is_open())
	{
		cout << "코드 파일을 여는 과정에서 문제가 발생했습니다.\n";
		return 2;
	}

	while (codeFile.good())
	{
		getline(codeFile,tmp);
		code.append(tmp);
	}

	codeFile.close();

	return 0;
}
#include <conio.h>
int main()
{
	
	string code;

	int exitCode = LoadCodeFile(code);

	if (exitCode == 0)
	{
		Interpreter interpreter(code);

		interpreter.Start();
	}


	printf("\n아무 문자나 입력해 종료합니다");

	_getch();
	return 0;
}
