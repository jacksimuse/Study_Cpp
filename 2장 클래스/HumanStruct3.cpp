#include <stdio.h>

struct SHuman
{
	char name[12];
	int age;

	void intro();
};

void SHuman::intro()
{
	printf("이름 = %s, 나이 = %d\n", name, age);
}

int main()
{
	SHuman kim = { "김상형", 29 };
	kim.intro();
}