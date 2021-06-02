#include <stdio.h>

class Fahrenheit;
class Cesius
{
public:
	double Tem;
	Cesius() {}
	Cesius(double aTem) : Tem(aTem) {}
	operator Fahrenheit();
	void OutTem() { printf("¼·¾¾ = %f\n", Tem); }
};

class Fahrenheit
{
public:
	double Tem;
	Fahrenheit() {}
	Fahrenheit(double aTem) : Tem(aTem) {}
	operator Cesius();
	void OutTem() { printf("È­¾¾ = %f\n", Tem); }
};

Cesius::operator Fahrenheit()
{
	Fahrenheit F;
	F.Tem = Tem * 1.8 + 32;
	return F;
}

Fahrenheit::operator Cesius()
{
	Cesius C;
	C.Tem = (Tem - 32) / 1.8;
	return C;
}

int main()
{
	Cesius C(100);
	Fahrenheit F = C;
	C.OutTem();
	F.OutTem();

	printf("\n");
	Fahrenheit F2 = 120;
	Cesius C2 = F2;
	F2.OutTem();
	C2.OutTem();
}