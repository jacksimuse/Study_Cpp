#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ string");

	cout << s << "���ڿ��� ���� = " << s.size() << endl;
	cout << s << "���ڿ��� ���� = " << s.length() << endl;
	cout << s << "���ڿ��� �Ҵ� ũ�� = " << s.capacity() << endl;
	cout << s << "���ڿ��� �ִ� ���� = " << s.max_size() << endl;

	s.resize(6);
	cout << s << "���� = " << s.size() << ",�Ҵ� ũ�� = " << s.capacity() << endl;

	s.reserve(100);
	cout << s << "���� = " << s.size() << ",�Ҵ� ũ�� = " << s.capacity() << endl;
}