#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human() {
		strcpy(name, "�̸�����");
		age = 0;
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main() {
	Human momo;
	momo.intro();
}