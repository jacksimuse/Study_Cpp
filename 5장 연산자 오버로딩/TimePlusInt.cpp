#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(){}
	Time(int h, int m, int s) { hour = h; min = m; sec = s;}
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
	const Time operator +(int s) const {
		Time t = *this;
		t.sec += s;
		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

int main()
{
	Time now(11, 22, 33);
	now.OutTime();
	now = now + 1;
	now.OutTime();
}
