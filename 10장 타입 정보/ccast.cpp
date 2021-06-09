#include <stdio.h>

int main()
{
	const char* str = "korea";
	int* pi;

	pi = (int*)str;
	printf("%d %x\n", *pi, *pi);
}