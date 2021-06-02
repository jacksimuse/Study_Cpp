#include <stdio.h>

class Some
{
private:
	mutable int temp;
public:
	Some() {}
	void method() const { temp = 0; }
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();
}