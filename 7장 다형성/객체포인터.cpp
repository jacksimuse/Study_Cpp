#include <iostream>
using namespace std;

class A
{
public:
	void AFunc() {
		cout << "A::AFunc()" << endl;
	}
};
class B : public A
{
public:
	void BFunc() {
		cout << "B::BFunc()" << endl;
	}
};
class C : public B
{
public:
	void CFunc() {
		cout << "C::CFunc()" << endl;
	}
};
int main()
{
	A* pa = new C;	// �θ��� ��ü �����Ͱ� �ڽ��� ����Ŵ
	pa->AFunc();	// �����ʹ� �ش� Ŭ���� ���� �Լ��� ��������� ��밡��
	B* pb = new C;
	pb->AFunc();	
	pb->BFunc();	// ��ӹ��� Ŭ������ �����ʹ� �θ� Ŭ������ �ڽ��� �Լ��� ��������� ��� ����
	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();
}