#include <stdio.h>
#include <string.h>
// 컴파일러는 생성자, 소멸자 자동생성, + 복사 생성자
class Human
{
private:
	char name[12];
	int age;

public:
	Human() {
		strcpy(name, "이름없음");
		age = 0;
	}

	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human momo;		 
	//Human arFriend[3]; 

	Human arFriend[3] = {
		{Human("문동욱", 49)},
		{Human("김유진", 49)},
		{Human("방상막", 49)},
	};

	arFriend[2].intro();
}