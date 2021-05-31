#include <stdio.h>

/* 생성자도 overload해서 사용가능하다 */
class Time
{
private:
	int hour, min, sec;

public:
	// 생성자1
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	// 생성자2
	Time(int abssec) { // 매개변수가 없는 생성자가 디폴트 생성자
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 30, 40);
	now.OutTime();
	Time noon(44000);
	noon.OutTime();
}