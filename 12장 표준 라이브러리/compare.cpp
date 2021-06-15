#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("aaa");
	string s2("bbb");

	cout << (s1 == s1 ? "����" : "�ٸ���") << endl;
	cout << (s1 == s2 ? "����" : "�ٸ���") << endl;
	cout << (s1 > s1 ? "ũ��" : "��ũ��") << endl;

	string s3("1234567");
	string s4("1234999");
	cout << (s3.compare(s4) == 0 ? "����" : "�ٸ���") << endl;
	cout << (s3.compare(0, 4, s4, 0, 4) == 0 ? "����" : "�ٸ���") << endl;

	string s5("hongkildong");
	cout << (s5 == "hongkildong" ? "����" : "�ٸ���") << endl;
}