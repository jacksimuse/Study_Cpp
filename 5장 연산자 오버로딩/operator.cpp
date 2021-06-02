#include <iostream>

class MyTest {
private:
	int x;
	int y;

public:
	MyTest(){}
	MyTest(int ax, int ay) { x = ax; y = ay; }
	void printData() {
		printf("%d + %d = %d\n", x, y, x + y);
	}
	const MyTest sum(const MyTest & other) const{
		MyTest t;
		t.x = x + other.x;
		t.y = y + other.y;

		return t;
	}
};
int main()
{
	MyTest obj1(10, 20);
	obj1.printData();
	MyTest obj2(20, 10);
	obj2.printData();
	MyTest obj;
	obj = obj1.sum(obj2);
	obj.printData();

	return 0;
}