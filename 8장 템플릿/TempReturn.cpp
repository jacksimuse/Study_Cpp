#include <stdio.h>

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = max(1, 2);
	double b = max(1.1, 2.2);
	//int c = max<int>(2, 3.14);
	double c = max<double>(2, 3.14);

	printf("a = %d\n", a);
	printf("b = %.1lf\n", b);
	printf("C = %f\n", c);
}