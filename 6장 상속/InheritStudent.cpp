#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Studenet : public Human
{
private:
	int stunum;

public:
	Studenet(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};
int main()
{
	Human Kim("�����", 29);
	Kim.intro();
	Studenet han("���Ѱ�", 15, 123456);
	han.intro();
	han.study();
}
