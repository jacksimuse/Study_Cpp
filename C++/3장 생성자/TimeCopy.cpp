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

	void OutTime() {
		printf("���� �ð��� %d:%d:%d�Դϴ�\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56); // now��� ��ü ����, ��ü ������ ���ÿ� ������ �ڵ� �ߵ�
	Time then = now; // ���ο� ��ü then�� ������ ����, now�� �ʱ�ȭ <- ���� ������
	//Time then(now);  ���� ǥ��

	then.OutTime();
}