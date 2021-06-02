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
	// explicit - 명시적 변환만 허용
	explicit Time(int abssec) {	// 변환생성자-임시객체를 생성하여 변환하고 멤버에 대입을 한다.
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.OutTime();
}

int main()
{
	Time noon(40000); // 명시적인 변환의 형태
	noon.OutTime();
	noon = 70000;		// 명시적이지 않다.
	Time now = 60000;
	now.OutTime();
	now = 70000;
	now.OutTime();

	printTime(80000);
}