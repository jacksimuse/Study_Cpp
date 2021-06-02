#include <stdio.h>

class Some
{
public:
	const int total; // 정적 데이터 영역에 저장되는 const
	// const는 선언과 동시에 초기화 해줘야되는데 클래스 멤버는 불가능함
	Some(int atotal) : total(atotal) {} // 멤버 초기화 리스트
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);
	S.OutTotal();
}