#include <iostream>

class CTest {
	int m_num;
	int* ptr;
public:
	CTest(int num) {			// 생성자
		m_num = num;
		printf("생성자 호출 %d\n", m_num);
	}
	CTest() {					// 디폴트 생성자
		printf("디폴트 생성자!!\n");
	};	
	CTest(int num, int* ptr) {	
		this->m_num = num;
		this->ptr = new int;	// 동적할당
		this->ptr = ptr;
		printf("인자 두개 생성자 호출 : %d, %p\n", m_num, ptr);
	}
	CTest(const CTest& other) { // 복사 생성자
		this->m_num = other.m_num;
		this->ptr = new int;	// 동적할당(깊은 복사)
		this->ptr = ptr;
		printf("복사생성자 호출 : %d, %p\n", m_num, ptr);
	}
	~CTest() {
		delete[] ptr;			// 동적할당한 경우 소멸자에서 해제시킨다.
	}
	void getData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	/* 기본 자료형 */
	int a = 10;
	int b(20);
	int c = a;
	printf("%d, %d, %d\n", a, b, c);

	/* 사용자 자료형 */
	CTest c1(100);	// 인수한개의 생성자 호출
	CTest c2;	// 디폴트 생성자 호출
	CTest c3(c1);	// 복사생성자 호출(얕은 복사) - 주소를 복사한다 / 포인터 역할(참조를 전달받는다)
	CTest c4(50, nullptr);
	CTest c5(c4);
	c3.getData();
	c5.getData();

	return 0;
}