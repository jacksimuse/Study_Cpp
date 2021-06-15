#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("1234567890");
	string s2("^_^");

	cout << s1 << endl;
	s1.insert(5, "XXX"); // s1의 5번째 자리에 XXX삽입
	cout << s1 << endl;
	s1.insert(5, s2);	 // s1의 5번째 자리에 s2를 삽입
	cout << s1 << endl;
	s1.erase(5, 6);		 // s1의 5번째 자리에 6글자를 삭제
	cout << s1 << endl;
}