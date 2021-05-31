#include <iostream>

/* 구조체(struct)는 기본적으로 public으로 되어있음
class는 public 선언 해줘야 사용가능
*/

class Human {
public:
	char name[20];
	float height;
	float weight;
	int age;
	char blood;

	void view();
};
/* ::범위 연산자 
class 내부에 함수를 만들고 전역변수로 지정할 때는 해상 클래스안에 있음을 알리는 범위 연산자가 필요
사용은 '클래스명::'
*/
void Human:: view()
{
	printf("나의 이름은 %s 이고 키는 %.1f 이고 몸무게는 %.1f 이고 나이는 %d 이고 혈액형은 %c 이다.", name, height, weight, age, blood);
}

int main()
{
	Human my = { "재훈", 180, 70, 20, 'A' };
	//printf("나의 이름은 %s 이고 키는 %.1f 이고 몸무게는 %.1f 이고 나이는 %d 이고 혈액형은 %c 이다.", my.name, my.height, my.weight, my.age, my.blood);
	my.view();
	return 0;
}