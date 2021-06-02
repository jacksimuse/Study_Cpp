#include <stdio.h>

class Some
{
public:
	int& total;	// 참조 변수도 콜론을 통한 초기화를 해준다
	Some(int& atotal) : total(atotal) {}
	void OutTotal() { printf("%d\n", total); }
};

int main() {
	int value = 8;
	Some S(value);
	S.OutTotal();
}