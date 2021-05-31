#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56); // now라는 객체 생성, 객체 생성과 동시에 생성자 자동 발동
	Time then = now; // 새로운 객체 then와 생성자 생성, now로 초기화 <- 복사 생성자
	//Time then(now);  같은 표현

	then.OutTime();
}