#include <stdio.h>

class Int100
{
private:
	int num;

public:
	Int100(int a) 
		try : num(a) {
		if (a > 100) {
			throw 0;
		}
	}
	catch (int a) {
		printf("%d�� 100���� �� Ů�ϴ�.\n", a);
	}

	void OutValue() {
		printf("%d\n", num);
	}
};

int main()
{
	try {
		Int100 i(101);
		i.OutValue();
	}
	catch (int) {
		puts("��ȿ�� ��ü��");
	}
}