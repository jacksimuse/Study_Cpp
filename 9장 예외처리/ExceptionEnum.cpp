#include <stdio.h>

enum E_Error {OUTOFMEMORY, OVERRANGE, HARDFULL};
void report() throw(E_Error)
{
	if (true/*���ܹ߻�*/) throw OVERRANGE;

	// ������� ������ ������ �۾� �Ϸ�����
}

int main()
{
	try {
		report();
		puts("�۾��� �Ϸ��߽��ϴ�.");
	}
	catch (E_Error e) {
		switch (e)
		{
		case OUTOFMEMORY:
			puts("�޸𸮰� �����մϴ�.");
			break;
		case OVERRANGE:
			puts("���� ������ �ʰ��߽��ϴ�.");
			break;
		case HARDFULL:
			puts("�ϵ� ��ũ�� ���� á���ϴ�.");
			break;
		default:
			break;
		}
	}
}