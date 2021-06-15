#include <iostream>
using namespace std;

int main()
{
	int i = 1234;

	hex(cout);
	cout << i << endl;

	cout << "8진수 : " << oct << i << endl;
	cout << "16진수 : " << hex << i << endl;
	cout << "10진수 : " << dec << i << endl;
}