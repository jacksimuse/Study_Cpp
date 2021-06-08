#include <stdio.h>

template <typename T>
T cast(int s)
{
	return (T)s;
}

int main()
{
	unsigned u = cast<unsigned>(1234);
	double d = cast<double>(5678);

	printf("u = %d, d = %f\n", u, d);
}