#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	int num;
	int age;
	char name[128];

	try {
		printf("�й��� �Է��ϼ��� : ");
		scanf("%d", &num);
		if (num <= 0) throw num;
		try {
			printf("�̸��� �Է��Ͻÿ� : ");
			scanf("%s", name);
			if (strlen(name) < 4)throw "�̸��� �ʹ� ª���ϴ�.";
			printf("���̸� �Է��Ͻÿ� : ");
			scanf("%d", &age);
			if (age <= 0) throw age;
			printf("�Է��� ���� => �й�:%d, �̸�:%s, ����:%d\n", num, name, age);
		}
		catch (const char* message)
		{
			puts(message);
		}
		catch (int) {
			throw;
		}
	}
	catch (int n) {
		printf("%d�� �����̹Ƿ� �������� �ʽ��ϴ�.\n", n);
	}
}