#include <stdio.h>

class Date
{
private:
	int year, month, day;

public:
	void SetDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void today() {
		printf("���� ��¥�� %d-%d-%d�Դϴ�\n", year, month, day);
	}
};

int main()
{
	Date now;

	now.SetDate(2021, 5, 31);
	now.today();
}