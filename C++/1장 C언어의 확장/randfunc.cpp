#include <stdio.h>
#include <stdlib.h>

/* inline�� �Ϲ� �Լ� ����
	�Ϲ� �Լ��� ���α׷��� �����ϴٰ� �Լ��� ã�ư��� �����ϰ� ���ϵǼ� ���µ�
	inline �Լ��� �Լ�ȣ�������� �Լ� ���γ����� �����ͼ� �׳� ����Ѵ�.
*/
inline int randfunc(int n)
{
	return rand() % n;
}

int main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("���� \ %d,%d,%d\n", i, j, k);
}