#include <stdio.h>

/* �����ڵ� overload�ؼ� ��밡���ϴ� */
class Time
{
private:
	int hour, min, sec;

public:
	// ������1
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	// ������2
	Time(int abssec) { // �Ű������� ���� �����ڰ� ����Ʈ ������
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() {
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 30, 40);
	now.OutTime();
	Time noon(44000);
	noon.OutTime();
}