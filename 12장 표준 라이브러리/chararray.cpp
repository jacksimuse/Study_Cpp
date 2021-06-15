#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("char array");

	cout << s.data() << endl;
	cout << s.c_str() << endl;

	char str[128];
	strcpy(str, s.c_str());
	printf("str = %s\n", str);
}