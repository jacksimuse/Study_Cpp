#include <stdio.h>

class Parent
{
public:
	int p;
};

class Child : public Parent
{
public:
	int c;
};

int main()
{
	int Parent::* pp;
	int Child::* pc;

	pp = &Parent::p;
	pc = &Child::c;

	pc = &Parent::p;
	pc = &Child::p;
}