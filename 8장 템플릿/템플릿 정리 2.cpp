/* �Լ� ���ø� */
#include <iostream>
using namespace std;

template<typename T> // �Ϲ�ȭ
class CTest {
private:
	T num;
public:
	//CTest(T anum) : num(anum) {};	�����ۼ� ����
	CTest(T);	// �����ϰ� �ܺο��� �ۼ�
	void printData() {
		cout << "num : " << num << endl;
	}
};
template <typename T>	// ������ �κа� ����� �ܺ�����
CTest<T>::CTest(T anum) {

}

int main()
{
	//CTest obj(10);
	CTest<int> obj(10);
	obj.printData();
}