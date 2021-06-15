#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "독도는 일본땅";

	cout << s1 << endl;
	s1.replace(7, 4, "대한민국");
	cout << s1 << endl;
}