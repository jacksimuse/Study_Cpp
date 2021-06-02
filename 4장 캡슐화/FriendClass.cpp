#include <stdio.h>
class Date;
class Time
{// 한쪽만 친구임 time은 date의 친구지만 date는 time의 친구가 아님 
	friend class Date;
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutToday(Date& d) {
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
			d.year, d.month, d.day, hour, min, sec);
	}
};

class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t) {
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
			year, month, day, t.hour, t.min, t.sec);
	}
};

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	//d.OutToday(t);
}