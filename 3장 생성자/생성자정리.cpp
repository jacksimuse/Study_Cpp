#include <iostream>

class CTest {
	int m_num;
	int* ptr;
public:
	CTest(int num) {			// ������
		m_num = num;
		printf("������ ȣ�� %d\n", m_num);
	}
	CTest() {					// ����Ʈ ������
		printf("����Ʈ ������!!\n");
	};	
	CTest(int num, int* ptr) {	
		this->m_num = num;
		this->ptr = new int;	// �����Ҵ�
		this->ptr = ptr;
		printf("���� �ΰ� ������ ȣ�� : %d, %p\n", m_num, ptr);
	}
	CTest(const CTest& other) { // ���� ������
		this->m_num = other.m_num;
		this->ptr = new int;	// �����Ҵ�(���� ����)
		this->ptr = ptr;
		printf("��������� ȣ�� : %d, %p\n", m_num, ptr);
	}
	~CTest() {
		delete[] ptr;			// �����Ҵ��� ��� �Ҹ��ڿ��� ������Ų��.
	}
	void getData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	/* �⺻ �ڷ��� */
	int a = 10;
	int b(20);
	int c = a;
	printf("%d, %d, %d\n", a, b, c);

	/* ����� �ڷ��� */
	CTest c1(100);	// �μ��Ѱ��� ������ ȣ��
	CTest c2;	// ����Ʈ ������ ȣ��
	CTest c3(c1);	// ��������� ȣ��(���� ����) - �ּҸ� �����Ѵ� / ������ ����(������ ���޹޴´�)
	CTest c4(50, nullptr);
	CTest c5(c4);
	c3.getData();
	c5.getData();

	return 0;
}