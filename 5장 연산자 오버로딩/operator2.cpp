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
	const MyTest operator+(const MyTest& other) const {	// 출력에 참조연산자를 사용함으로써 복사생성자가 필요없게됨
		MyTest t;
		t.x = x + other.x;
		t.y = y + other.y;

		return t;	// t가 return될때 복사생성자가 호출되면서 임시 객체가 만들어져 t의 멤버 변수값들이 복사된다
	}
	friend const MyTest operator -(const MyTest& rhs1, const MyTest& rhs2);
	/*const MyTest operator -(const MyTest& other) const {
		MyTest t;
		t.x = x - other.x;
		t.y = y - other.y;

		return t;
	}*/
	const MyTest& operator =(const MyTest& other)  {
		x = other.x;
		y = other.y;

		return *this;
		}
	void printData() {
		printf("%d + %d = %d\n", x, y, x + y);
	}
};
const MyTest operator -(const MyTest& rhs1, const MyTest& rhs2) {
	MyTest res;
	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;
	return res;
}

int main()
{
	printf("객체 생성과 동시에 값 넣기\n");
	MyTest obj1(10, 20);
	obj1.printData();
	MyTest obj2(20, 10);
	obj2.printData();
	printf("--------------------------------\n");
	MyTest obj;
	//obj = obj1.operator+(obj2);
	printf("--------------------------------\n");
	obj = obj1 + obj2;	// 참조 연산자를 사용안하면 복사 생성자가 안나와서 값이 없는 일반 생성자가 호출되서 쓰레기값이 나옴
	obj.printData();
	printf("--------------------------------\n");

	obj = obj1 - obj2;
	obj.printData();
	printf("--------------------------------\n");

	obj = obj1.operator=(obj2);
	obj.printData();

	printf("--------------------------------\n");
	printf("전역 연산자 함수를 통해 함수식으로 연산\n");
	obj = operator-(obj1, obj2);
}