#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("1234567890");
	string s2("^_^");

	cout << s1 << endl;
	s1.insert(5, "XXX"); // s1�� 5��° �ڸ��� XXX����
	cout << s1 << endl;
	s1.insert(5, s2);	 // s1�� 5��° �ڸ��� s2�� ����
	cout << s1 << endl;
	s1.erase(5, 6);		 // s1�� 5��° �ڸ��� 6���ڸ� ����
	cout << s1 << endl;
}