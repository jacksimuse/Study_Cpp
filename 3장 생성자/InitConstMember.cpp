#include <stdio.h>

class Some
{
public:
	const int total; // ���� ������ ������ ����Ǵ� const
	// const�� ����� ���ÿ� �ʱ�ȭ ����ߵǴµ� Ŭ���� ����� �Ұ�����
	Some(int atotal) : total(atotal) {} // ��� �ʱ�ȭ ����Ʈ
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);
	S.OutTotal();
}