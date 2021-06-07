/*student class�� ����� human�� ��� 

student ��ü�� ����� iot�� ��µǰ��ϱ�

����
Student s("�̸�", "Iot");
s.printMajor(); Myname is ȫ�浿 My major is Iot
*/
#include <iostream>
using namespace std;
class Human
{
private:
	char* name;
public:
	Human(const char* aname) {
		int len = strlen(aname) + 1;
		name = new char[len];
		strcpy_s(name, len, aname);
	}
	~Human() {
		delete[] name;
	}
	void printname() {
		cout << "My name is " << name;
	}
};
class Student : public Human
{
private:
	char* major;

public:
	Student(const char* aname, const char* amajor) : Human(aname) {
		major = new char[strlen(amajor) + 1];
		strcpy(major, amajor);
		
	}
	void printMajor() {
		printname();
		printf(" My Major is %s �Դϴ�.", major);
	}
};

int main()
{
	Human my("ȫ�浿");
	//my.printname();
	Student s("ȫ�浿", "Iot");
	s.printMajor();
	return 0;
}