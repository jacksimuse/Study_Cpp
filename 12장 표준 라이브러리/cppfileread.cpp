#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f;
	char str[128];
	int i;

	f.open("C:\\temp\\cpptest.txt");
	if (f.is_open()) {
		f >> str >> i;
		cout << str << i << endl;
		f.close();
	}
	else {
		cout << "���� ���� ����" << endl;
	}
}