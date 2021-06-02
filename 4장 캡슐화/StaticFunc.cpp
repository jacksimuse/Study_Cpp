#include <stdio.h>

class Simple
{
private:
	int value;
	static int count;

public:
	Simple() { count++; }
	~Simple() { count--; }
	static void InitCount() {
		count = 0;
	}
	static void OutCount() {
		printf("���� ��ü ���� = %d\n", count);
	}
};
int Simple::count;

int main()
{
	Simple::InitCount();
	Simple::OutCount();
	Simple s, * ps;
	Simple::OutCount();
	ps = new Simple;
	Simple::OutCount();
	delete ps;
	Simple::OutCount();
	printf("ũ�� = %d\n", sizeof(s));
}