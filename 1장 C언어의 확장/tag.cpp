#include <stdio.h>

int main()
{
	enum origin{ EAST,WEST,SOUTH,NORTH };
	origin mark = WEST;
	printf("%d ����\n", mark);

	typedef struct SHuman
	{
		char name[12];
		int age;
		double height;
	};

	SHuman Kim = { "�����", 29, 181.4 };
	printf("�̸� = %s, ���� = %d\n", Kim.name, Kim.age);

}