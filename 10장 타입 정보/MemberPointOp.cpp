#include <stdio.h>

class Time
{
public:
	int hour, min, sec;

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now;
	int Time::* pi;

	pi = &Time::hour;
	now.*pi = 12;
	pi = &Time::min;
	now.*pi = 34;
	pi = &Time::sec;
	now.*pi = 56;
	now.OutTime();
}