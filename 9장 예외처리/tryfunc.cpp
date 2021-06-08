#include <stdio.h>

void divide(int a, int d)
try{
	if (d == 0) throw "0으로는 나눌 수 없습니다.";
	printf("나누기 결과 = %d입니다.\n", a / d);
}
catch (const char* message) {
	puts(message);
}

int main()
{
	divide(10, 0);
}