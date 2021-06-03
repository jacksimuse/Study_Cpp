#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
	bool operator ==(const Time& other) const {
		return (hour == other.hour && min == other.min && sec == other.sec);
	}
	bool operator !=(const Time& other) const {
		return !(*this == other);
	}
	bool operator >(const Time& other) const {
		if (hour > other.hour) return true;
		if (hour < other.hour) return false;
		if (min > other.min) return true;
		if (min < other.min) return false;
		if (sec > other.sec) return true;
		return false;
	}
	bool operator >=(const Time& other) const {
		return (*this == other || *this > other);
	}
	bool operator <(const Time& other) const {
		return !(*this >= other);
	}
	bool operator <=(const Time& other) const {
		return !(*this > other);
	}
};

int main()
{
	Time t1(12, 34, 56);
	Time t2(12, 34, 21);

	if (t1 == t2) {
		puts("두 시간은 같다.");
	}
	else {
		puts("두 시간은 다르다.");
	}

	if (t1 > t2) {
		puts("t1이 더 크다.");
	}
	else {
		puts("t1이 더 작다.");
	}
}