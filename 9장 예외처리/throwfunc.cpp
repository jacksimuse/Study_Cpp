#include <stdio.h>

void divide(int a, int d)
{
	if (d == 0) throw "0���δ� ���� �� �����ϴ�.";
	printf("������ ��� = %d�Դϴ�.\n", a / d);
}

int main()
{
	try {
		divide(2, 0);
	}
	catch (const char* message) {
		puts(message);
	}
	divide(10, 5);
}