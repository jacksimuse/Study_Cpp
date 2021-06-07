#include <iostream>
using namespace std;

class CTest
{
private:
	int num;

public:
	CTest(int anum) { num = anum;
	cout << num << " CTest constructor" << endl;
	}
	virtual void func() {
		cout << "CTest function()" << endl;
	}
	virtual ~CTest() { cout << num << " CTest deconstructor" << endl; }
};
class CTestSub : public CTest
{
	int subN;
public:
	CTestSub(int anum, int asubN) : CTest(anum) { subN = asubN; 
		cout << subN << " CTestSub constructor" << endl;
	}
	~CTestSub() { cout << subN << " CTestSub deconstructor" << endl; }
	void func() {
		cout << "CTestSub function()" << endl;
	}
};


int main()
{
	CTest b(10);
	b.func();
	CTestSub d(10, 20);
	d.func();
	
	CTest* pb = new CTestSub(30, 33);	// 추상자료형으로 자식 객체를 가리키게 한다
	// 메모리 동적 할당하는 경우에 파괴자가 안불러짐 -> 부모의 파괴자에 virtual을 걸어준다

	pb->func();

	delete pb;
	
}