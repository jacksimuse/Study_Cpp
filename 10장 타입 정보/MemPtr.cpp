#include <stdio.h>

class Calc
{
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
};

int main()
{
	int ch;
	Calc c;
	int a = 3, b = 4;
	void (Calc:: * arop[3])(int, int) = { &Calc::Op1,&Calc::Op2,&Calc::Op3 };
	
	printf("���� ����� �����Ͻÿ�. 0 = ���ϱ�, 1 = ����, 2 = ���ϱ� : ");
	scanf("%d", &ch);

	if (ch >= 0 && ch <= 2) {
		(c.*arop[ch])(3, 4);
	}

	/*switch (ch)
	{
	case 0:
		c.Op1(a, b);
		break;
	case 1:
		c.Op2(a, b);
		break;
	case 2:
		c.Op3(a, b);
		break;
	}*/
}