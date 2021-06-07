#include <stdio.h>
#include <string.h>

class Human
{
protected:
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

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

class Graduate : public Student
{
protected:
	char thesis[32];

public:
	Graduate(const char* aname, int aage, int astunum, const char* athesis) : Student
	(aname, aage, astunum) {
		strcpy(thesis, athesis);
	}
	void research() {
		printf("%s�� �����ϰ� ���� ����.\n", thesis);
	}
};

int main()
{
	Graduate moon("������", 45, 920629, "���ӹ� ��� �м�");
	moon.research();
}