#include <stdio.h>

/* ��� �Լ��� ���Ե� ���� class���
����ü�� ���������� �� ���*/
struct SHuman {
private:
	char name[12];
	int age;

public:
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main() {
	SHuman kim;
	kim.intro();
}