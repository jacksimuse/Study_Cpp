#include <stdio.h>

int report()
{
	if (true/*���ܹ߻�*/) return 1;

	//������� ������ ������ �۾� �Ϸ�����
	return 0;
}

int main()
{
	int e;

	e = report();
	switch (e)
	{
	case 1:
		puts("�޸𸮰� �����մϴ�.");
		break;
	case 2:
		puts("���� ������ �ʰ��߽��ϴ�.");
		break;
	case 3:
		puts("�ϵ� ��ũ�� ���� á���ϴ�.");
		break;
	default:
		puts("�۾��� �Ϸ��߽��ϴ�.");
		break;
	}
}