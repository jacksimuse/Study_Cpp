#include <stdio.h>

int main()
{
	int num;

	try
	{
		printf("1���� 100������ ������ �Է��Ͻÿ� : ");
		scanf("%d", &num);
		if (num < 1 || num > 100) throw num;
		printf("�Է��� ��  = %d\n", num);
	}
	catch (int num)
	{
		printf("%d�� 1���� 100 ������ ������ �ƴմϴ�.\n", num);
	}
}