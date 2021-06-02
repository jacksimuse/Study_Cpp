#include <stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	MyTest(){}
	MyTest(int ax, int ay) { 
		x = ax; 
		y = ay;
		printf("인수 2개 생성자!!\n");
	}
	MyTest(MyTest& rfs) : x(rfs.x), y(rfs.y){
		printf("복사 생성자 호출!!\n");
	}
	const MyTest& operator+(const MyTest& other) {	// 출력에 참조연산자를 사용함으로써 복사생성자가 필요없게됨
		MyTest t;
		t.x = x + other.x;
		t.y = y + other.y;

		return t;	// t가 return될때 복사생성자가 호출되면서 임시 객체가 만들어져 t의 멤버 변수값들이 복사된다
	}
	const MyTest& operator -(const MyTest& other) {
		MyTest t;
		t.x = x - other.x;
		t.y = y - other.y;

		return t;
	}
	void printData() {
		printf("%d + %d = %d\n", x, y, x + y);
	}
};

int main()
{
	MyTest obj1(10, 20);
	obj1.printData();
	MyTest obj2(20, 10);
	obj2.printData();
	MyTest obj;
	//obj = obj1.operator+(obj2);
	obj = obj1 + obj2;
	obj.printData();
	obj = obj1 - obj2;
	obj.printData();
}