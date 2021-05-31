#include <stdio.h>

/* 속성의 값만 가지고 인스턴스 생성
함수는 인스턴스 생성 안됨
멤버 함수의 크기는 필요없다 멤버 함수는 공유되어진다

공유될때 누가 함수를 호출하는지 알아야되는데 this포인터가 생략되어 자기가 부른다는걸 알려준다함
*/
class Human
{
public:
	char name[12];
	int age;

	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = {
		{ "문동욱", 49},
		{ "김유진", 49},
		{ "박상막", 49}
	};

	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();
}