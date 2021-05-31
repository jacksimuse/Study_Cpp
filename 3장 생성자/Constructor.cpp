#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	/* 생성자 초기화
	방법 1*/
	Human(const char* aname, int aage) { // human이라는 함수에 aname으로 포인터 쓰는 것은 문자열이라서
		strcpy(name, aname);	// name에 포인터로 가리킨 문자들을 대입하겠다
		age = aage;
	}
	/* 방법 2 멤버 이름를 만들 때 m_멤버로 설정 근데 귀찮아서 잘 안씀 */
	
	/*방법 3
	Human(const char* name, int age) { 클래스 멤버와 매개변수를 이름 같게하고 싶으면 this->를 사용
	strcpy(this->name, name);	
	this->age = age;
	} */

	/*방법 4
	Human(const char* aname, int aage) { 범위 지정 연산자 :: 사용
		strcpy(Human::name, aname);	
		Human::age = aage;
	}*/
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main() {
	Human kim("김상형", 29);	// human에 kim변수를 만들고 매개변수 입력받음
	kim.intro();
}