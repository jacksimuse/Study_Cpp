#include <stdio.h>

class ExNegative
{
protected:
	int number;

public:
	ExNegative(int n) : number(n){}
	virtual void PrintError() {
		printf("%d�� �����̹Ƿ� �߸��� ���Դϴ�.\n", number);
	}
};

class ExTooBig : public ExNegative
{
public:
	ExTooBig(int n) : ExNegative(n) {}
	virtual void PrintError() {
		printf("%d�� �ʹ� Ů�ϴ�. 100���� �۾ƾ��մϴ�.\n", number);
	}
};

class ExOdd : public ExTooBig
{
public:
	ExOdd(int n) : ExTooBig(n) {}
	virtual void PrintError() {
		printf("%d�� Ȧ���Դϴ�. ¦������ �մϴ�.\n", number);
	}
};

int main()
{
	int n;

	for (;;) {
		try {
			printf("���ڸ� �Է��ϼ���(���� �� 0) : ");
			scanf("%d", &n);
			if (n == 0)break;
			if (n < 0)throw ExNegative(n);
			if (n > 100)throw ExTooBig(n);
			if (n % 2 != 0) throw ExOdd(n);

			printf("%d ���ڴ� ��Ģ�� �´� �����Դϴ�.\n", n);
		}
		catch (ExNegative& e) {
			e.PrintError();
		}
	}
}