#include <iostream>

class A
{
public:
	virtual void test() { printf("A::test()\n"); }
};
class B : public A
{
public:
	virtual void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }
};
class C : public B
{
public:
	virtual void test() { printf("C::test()\n"); }
	void test2() { printf("C::test2()\n"); }
};
void GlobalFunc(A& a) {
	try
	{
		C& c = dynamic_cast<C&>(a);
		printf("GlobalFunc()\n");
	}
	catch (std::bad_cast)
	{
		printf("casting error\n");
	}
}
int main()
{
	A* pa = new C;
	A* paa = new B;
	pa->test();	// pa는 부모 포인터가 자식을 가리켜서 가능
	B* pb = dynamic_cast<B*>(pa);	// 포인터가 자신꺼를 가리켜서 cast 가능 
	if (pb) pb->test2();
	C* pc = dynamic_cast<C*>(paa);	// 포인터가 부모를 가리켜서 cast 불가능
	if (pc) pc->test2();

	C c;
	GlobalFunc(c); // 함수는 c가 c를 참조해서 가능
	B b;
	GlobalFunc(b); // 함수는 b에 대한 언급이 없어서 bad_cast발동
	return 0;
}