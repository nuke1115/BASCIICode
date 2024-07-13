#include <iostream>
#include <string>
#include <fstream>
#include "..\Header\Interpreter.h"
using namespace std;
string fileExtension = ".BFAC";

int LoadCodeFile(string &code)
{
	string filePath,tmp;
	cout << "�ڵ尡 ������ִ� .BFAC ������ ���� �ּҸ� �Է����ּ���:";
	getline(cin,filePath);

	if (!filePath.ends_with(fileExtension))
	{
		cout << "���� Ȯ���ڰ� �߸��Ǿ����ϴ�.";
		return 2;
	}


	ifstream codeFile;
	codeFile.open(filePath);

	if (!codeFile.is_open())
	{
		cout << "�ڵ� ������ ���� �������� ������ �߻��߽��ϴ�.\n";
		return 1;
	}

	while (codeFile.good())
	{
		getline(codeFile,tmp);
		code.append(tmp);
	}

	codeFile.close();

	return 0;
}

int main()
{
	
	string code;

	LoadCodeFile(code);

	Interpreter interpreter(code);

	interpreter.Start();
	
	return 0;
}
