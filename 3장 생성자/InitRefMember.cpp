#include <stdio.h>

class Some
{
public:
	int& total;	// ���� ������ �ݷ��� ���� �ʱ�ȭ�� ���ش�
	Some(int& atotal) : total(atotal) {}
	void OutTotal() { printf("%d\n", total); }
};

int main() {
	int value = 8;
	Some S(value);
	S.OutTotal();
}