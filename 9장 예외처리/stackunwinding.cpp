#include <stdio.h>

class C
{
	int a;
public:
	C() { puts("생성자 호출"); }
	~C() { puts("파괴자 호출"); }
};

void divide(int a, int d)
{
	if (d == 0) throw "0으로는 나눌 수 없습니다.";
	printf("나누기 결과  = %d입니다.\n", a / d);
}

void calc(int t, const char* m)
{
	C c;
	divide(10, 0);
}

int main()
{
	try {
		calc(1, "계산");
	}
	catch (const char* message) {
		puts(message);
	}
	puts("프로그램이 종료됩니다.");
}