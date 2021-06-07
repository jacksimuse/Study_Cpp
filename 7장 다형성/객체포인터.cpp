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
	A* pa = new C;	// 부모의 객체 포인터가 자식을 가리킴
	pa->AFunc();	// 포인터는 해당 클래스 안의 함수나 멤버변수만 사용가능
	B* pb = new C;
	pb->AFunc();	
	pb->BFunc();	// 상속받은 클래스의 포인터는 부모 클래스와 자신의 함수와 멤버변수도 사용 가능
	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();
}