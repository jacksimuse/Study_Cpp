#include <stdio.h>
#include <exception>
using namespace std;

void myunex()
{
	puts("�߻��ؼ��� �ȵǴ� ���� �߻�");
	exit(-2);
}

void calc() throw(int)
{
	throw "string";
}

int main()
{
	set_unexpected(myunex);
	try
	{
		calc();
	}
	catch (const char* message)
	{
		puts("������ ���� �߻�");
	}
	puts("���α׷� ����");
}