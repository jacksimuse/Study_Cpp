/* 함수 템플릿 */
#include <iostream>
using namespace std;

template<typename T> // 일반화
class CTest {
private:
	T num;
public:
	//CTest(T anum) : num(anum) {};	내부작성 정석
	CTest(T);	// 선언하고 외부에서 작성
	void printData() {
		cout << "num : " << num << endl;
	}
};
template <typename T>	// 선언한 부분과 연결된 외부지점
CTest<T>::CTest(T anum) {

}

int main()
{
	//CTest obj(10);
	CTest<int> obj(10);
	obj.printData();
}