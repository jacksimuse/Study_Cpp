#include <stdio.h>

int main()
{
	int a, b;

	try {
		printf("�������� ���� �Է��Ͻÿ� : ");
		scanf("%d", &a);
		if (a < 0)throw a;
		printf("������ ���� �Է��Ͻÿ� : ");
		scanf("%d", &b);
		if (b == 0)throw "0���δ� ���� �� �����ϴ�.";
		printf("������ ����� %d�Դϴ�.\n", a / b);
	}
	catch (int a) {
		printf("%d�� �����̹Ƿ� ������ �ź�\n", a);
	}
	catch (const char* message) { // 13���� �޴� message
		puts(message);
	}
}