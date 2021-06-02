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
	// const void OutTime() {} ��� ����Լ� / �Լ��� ���ȭ
	void OutTime() const {	// �Լ��� ���ڸ� ����� ����
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00); // ��ü ���ȭ
	//meeting.SetTime(17,00,00);
	meeting.OutTime();
}