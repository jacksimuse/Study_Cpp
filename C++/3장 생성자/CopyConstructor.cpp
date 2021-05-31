#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human &other) { // const Human other이 객체 생성하는 모양이므로 자동으로 생성자가 나옴 그래서 무한 생성자 루프에 빠짐 ** & 이거 꼭 써주기
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

void printHuman(Human who) {
	who.intro();
}

int main() {
	Human kang("강감찬", 1424);
	Human boy = kang;

	printHuman(boy);
}