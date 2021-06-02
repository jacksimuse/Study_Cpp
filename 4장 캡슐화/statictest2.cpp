#include <iostream>

class StaticTest {
	static int a;	// static 멤버변수 
	int b;

public:
	StaticTest();
	static void setData(int); // static 멤버함수는 static 멤버변수에 사용한다.
	void getData();
};
int StaticTest::a = 10;	// static 멤버변수 초기화
StaticTest::StaticTest()
{
	this->b = 20;
}
void StaticTest::getData()
{
	printf("a : %d, b : %d\n",a, b);
}
void StaticTest::setData(int aa)
{
	// this->a = aa; static은 객체가 주체가 아님 그래서 this못씀
	a = aa;
}

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();
	s2.getData();

	StaticTest::setData(40);	// 클래스 소속으로 클래스 호출이 가능하다.
	s1.getData();
	s2.getData();
}