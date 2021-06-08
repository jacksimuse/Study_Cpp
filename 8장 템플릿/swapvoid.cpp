#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void swap(void* a, void* b, size_t len)
{
	void* t;
	t = malloc(len);
	memcpy(t, a, len);
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(&a, &b, sizeof(int));
	swap(&c, &d, sizeof(double));
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
}