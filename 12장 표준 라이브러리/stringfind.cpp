#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("string class find function");
	string s2("func");

	cout << "i:" << s1.find('i') << "번째" << endl;
	cout << "i:" << s1.find('i', 10) << "번째" << endl;
	cout << "ass:" << s1.find("ass") << "번째" << endl;
	cout << "finding의 앞 4:" << s1.find("finding", 0, 4) << "번째" << endl;
	cout << "kiss:" << s1.find("kiss") << "번째" << endl;
	cout << s2 << ':' << s1.find(s2) << "번째" << endl;

}