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
	pa->test();	// pa�� �θ� �����Ͱ� �ڽ��� �����Ѽ� ����
	B* pb = dynamic_cast<B*>(pa);	// �����Ͱ� �ڽŲ��� �����Ѽ� cast ���� 
	if (pb) pb->test2();
	C* pc = dynamic_cast<C*>(paa);	// �����Ͱ� �θ� �����Ѽ� cast �Ұ���
	if (pc) pc->test2();

	C c;
	GlobalFunc(c); // �Լ��� c�� c�� �����ؼ� ����
	B b;
	GlobalFunc(b); // �Լ��� b�� ���� ����� ��� bad_cast�ߵ�
	return 0;
}