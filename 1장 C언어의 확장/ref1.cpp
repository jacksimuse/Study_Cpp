#include <stdio.h>

int main()
{
	int i = 3;
	int& ri = i;
	int* pi = &i;

	printf("i = %d, ri = %d\n", i, ri);
	ri++;
	printf("i = %d, ri = %d\n", i, ri);
	*pi = i + 1;
	printf("i = %d, ri = %d\n", i, ri);

	printf("i번지 = %x, ri번지=%x\n", &i, &ri);

}