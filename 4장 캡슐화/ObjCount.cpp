#include <stdio.h>

int count = 0;
class Simple
{
private:
	int value;

public:
	Simple() { count++; }
	~Simple() { count--; }
	void OutCount() {
		printf("���� ��ü ���� = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;
	s.OutCount();
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("ũ�� = %d\n", sizeof(s));
}