#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	/* ������ �ʱ�ȭ
	��� 1*/
	Human(const char* aname, int aage) { // human�̶�� �Լ��� aname���� ������ ���� ���� ���ڿ��̶�
		strcpy(name, aname);	// name�� �����ͷ� ����Ų ���ڵ��� �����ϰڴ�
		age = aage;
	}
	/* ��� 2 ��� �̸��� ���� �� m_����� ���� �ٵ� �����Ƽ� �� �Ⱦ� */
	
	/*��� 3
	Human(const char* name, int age) { Ŭ���� ����� �Ű������� �̸� �����ϰ� ������ this->�� ���
	strcpy(this->name, name);	
	this->age = age;
	} */

	/*��� 4
	Human(const char* aname, int aage) { ���� ���� ������ :: ���
		strcpy(Human::name, aname);	
		Human::age = aage;
	}*/
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main() {
	Human kim("�����", 29);	// human�� kim������ ����� �Ű����� �Է¹���
	kim.intro();
}