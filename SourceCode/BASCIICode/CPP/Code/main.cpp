#include <iostream>
#include <string>
#include <fstream>
#include "..\Header\Interpreter.h"
using namespace std;
string fileExtension = ".BFAC";

int LoadCodeFile(string &code)
{
	string filePath, tmp;
	cout << "�ڵ尡 ������ִ� .BFAC ������ ���� �ּҸ� �Է����ּ���:";
	getline(cin,filePath);

	if (!filePath.ends_with(fileExtension))
	{
		cout << "���� Ȯ���ڰ� �߸��Ǿ����ϴ�.";
		return 1;
	}

	ifstream codeFile;
	codeFile.open(filePath);

	if (!codeFile.is_open())
	{
		cout << "�ڵ� ������ ���� �������� ������ �߻��߽��ϴ�.\n";
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


	printf("\n�ƹ� ���ڳ� �Է��� �����մϴ�");

	_getch();
	return 0;
}
