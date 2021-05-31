#include <stdio.h>

/* 멤버 함수가 포함될 때는 class사용
구조체는 변수모음일 때 사용*/
struct SHuman {
private:
	char name[12];
	int age;

public:
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main() {
	SHuman kim;
	kim.intro();
}