#include <stdio.h>
#include <string.h>
/* overload는 함수명만 같고 매개변수 수나 자료형이 다를때 사용
override는 함수명(매개변수) 같을때 사용한다 - 재정의 상속에서 주로 쓰임*/
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
		printf("이름 = %s, 나이 = %d\n", name, age);
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
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	han.intro();
	han.Human::intro(); // 오버라이드 후 부모의 함수 내용이 필요한경우
}