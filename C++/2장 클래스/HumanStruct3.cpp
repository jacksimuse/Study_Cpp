#include <stdio.h>

struct SHuman
{
	char name[12];
	int age;

	void intro();
};

void SHuman::intro()
{
	printf("�̸� = %s, ���� = %d\n", name, age);
}

int main()
{
	SHuman kim = { "�����", 29 };
	kim.intro();
}