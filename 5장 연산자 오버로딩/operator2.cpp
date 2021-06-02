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
		printf("�μ� 2�� ������!!\n");
	}
	MyTest(MyTest& rfs) : x(rfs.x), y(rfs.y){
		printf("���� ������ ȣ��!!\n");
	}
	const MyTest& operator+(const MyTest& other) {	// ��¿� ���������ڸ� ��������ν� ��������ڰ� �ʿ���Ե�
		MyTest t;
		t.x = x + other.x;
		t.y = y + other.y;

		return t;	// t�� return�ɶ� ��������ڰ� ȣ��Ǹ鼭 �ӽ� ��ü�� ������� t�� ��� ���������� ����ȴ�
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