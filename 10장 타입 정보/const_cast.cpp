#include <stdio.h>

int main()
{
	char str[] = "string";
	const char* c1 = str;
	char* c2;
	const char str1[] = "hello Iot";

	c2 = const_cast<char*>(c1);	// const 기능을 일시적으로 해제
	c2[0] = 'a';

	char* c3 = const_cast<char*>(str1);
	c3[0] = 'H';

	puts(c2);
	puts(c3);

	int num = 10;
	const int& ref = num;
	int& rtem = const_cast<int&>(ref);
	rtem = 30;
	printf("%d\n", num);
}