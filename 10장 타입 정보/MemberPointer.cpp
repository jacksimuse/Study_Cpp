#include <stdio.h>

class MyClass
{
public:
	int i, j;
	double d;
};

int main()
{
	MyClass C;
	int MyClass::* pi;
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;
	pi = &MyClass::j;
	pd = &MyClass::d;
}