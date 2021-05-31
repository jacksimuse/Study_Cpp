#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human &other) { // const Human other�� ��ü �����ϴ� ����̹Ƿ� �ڵ����� �����ڰ� ���� �׷��� ���� ������ ������ ���� ** & �̰� �� ���ֱ�
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

void printHuman(Human who) {
	who.intro();
}

int main() {
	Human kang("������", 1424);
	Human boy = kang;

	printHuman(boy);
}