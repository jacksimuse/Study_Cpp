#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("string class find function");
	string s2("func");

	cout << "i:" << s1.find('i') << "��°" << endl;
	cout << "i:" << s1.find('i', 10) << "��°" << endl;
	cout << "ass:" << s1.find("ass") << "��°" << endl;
	cout << "finding�� �� 4:" << s1.find("finding", 0, 4) << "��°" << endl;
	cout << "kiss:" << s1.find("kiss") << "��°" << endl;
	cout << s2 << ':' << s1.find(s2) << "��°" << endl;

}