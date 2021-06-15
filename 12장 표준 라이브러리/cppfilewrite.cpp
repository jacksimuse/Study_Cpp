#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream f;

	f.open("C:\\temp\\cpptest.txt");
	if (f.is_open()) {
		f << "String " << 1234 << endl;
		f.close();
	}
	else {
		cout << "파일 열기 실패" << endl;
	}
}