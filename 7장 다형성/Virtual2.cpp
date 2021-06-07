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
	
	CTest* pb = new CTestSub(30, 33);	// �߻��ڷ������� �ڽ� ��ü�� ����Ű�� �Ѵ�
	// �޸� ���� �Ҵ��ϴ� ��쿡 �ı��ڰ� �Ⱥҷ��� -> �θ��� �ı��ڿ� virtual�� �ɾ��ش�

	pb->func();

	delete pb;
	
}