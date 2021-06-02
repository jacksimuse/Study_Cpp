#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		SetTime(h, m, s);
	}

	void SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	// const void OutTime() {} 상수 멤버함수 / 함수의 상수화
	void OutTime() const {	// 함수의 인자를 상수로 고정
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00); // 객체 상수화
	//meeting.SetTime(17,00,00);
	meeting.OutTime();
}