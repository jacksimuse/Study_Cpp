#include <stdio.h>

class Base
{
private:
	char* B_buf;
public:
	Base() { B_buf = new char[10]; puts("Base 积己"); }
	virtual ~Base() { delete[] B_buf; puts("Base 颇鲍"); } 
};

class Derived : public Base
{
private:
	int* D_buf;
public:
	Derived() { D_buf = new int[32]; puts("Derived 积己"); }
	virtual ~Derived() { delete[] D_buf; puts("Derived 颇鲍"); }
};

int main()
{
	Base* pB;

	pB = new Derived;
	delete pB;
}