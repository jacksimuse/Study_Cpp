/*student class를 만들고 human을 상속 

student 객체를 만들고 iot가 출력되게하기

예시
Student s("이름", "Iot");
s.printMajor(); Myname is 홍길동 My major is Iot
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
		printf(" My Major is %s 입니다.", major);
	}
};

int main()
{
	Human my("홍길동");
	//my.printname();
	Student s("홍길동", "Iot");
	s.printMajor();
	return 0;
}