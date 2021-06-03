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
	const MyTest operator+(const MyTest& other) const {	// ��¿� ���������ڸ� ��������ν� ��������ڰ� �ʿ���Ե�
		MyTest t;
		t.x = x + other.x;
		t.y = y + other.y;

		return t;	// t�� return�ɶ� ��������ڰ� ȣ��Ǹ鼭 �ӽ� ��ü�� ������� t�� ��� ���������� ����ȴ�
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
	printf("��ü ������ ���ÿ� �� �ֱ�\n");
	MyTest obj1(10, 20);
	obj1.printData();
	MyTest obj2(20, 10);
	obj2.printData();
	printf("--------------------------------\n");
	MyTest obj;
	//obj = obj1.operator+(obj2);
	printf("--------------------------------\n");
	obj = obj1 + obj2;	// ���� �����ڸ� �����ϸ� ���� �����ڰ� �ȳ��ͼ� ���� ���� �Ϲ� �����ڰ� ȣ��Ǽ� �����Ⱚ�� ����
	obj.printData();
	printf("--------------------------------\n");

	obj = obj1 - obj2;
	obj.printData();
	printf("--------------------------------\n");

	obj = obj1.operator=(obj2);
	obj.printData();

	printf("--------------------------------\n");
	printf("���� ������ �Լ��� ���� �Լ������� ����\n");
	obj = operator-(obj1, obj2);
}