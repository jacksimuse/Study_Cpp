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
		printf("현재 객체 개수 = %d\n", count);
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
	printf("크기 = %d\n", sizeof(s));
}