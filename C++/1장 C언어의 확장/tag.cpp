#include <stdio.h>

int main()
{
	enum origin{ EAST,WEST,SOUTH,NORTH };
	origin mark = WEST;
	printf("%d 방향\n", mark);

	typedef struct SHuman
	{
		char name[12];
		int age;
		double height;
	};

	SHuman Kim = { "김상형", 29, 181.4 };
	printf("이름 = %s, 나이 = %d\n", Kim.name, Kim.age);

}