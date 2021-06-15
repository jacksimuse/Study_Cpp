#include <iostream>
using namespace std;

int main()
{
	int i = 1234;
	int j = -567;

	// 출력 폭 지정
	cout << i << endl;
	cout.width(10);
	cout << i << endl;
	cout.width(2);
	cout << i << endl;

	// 채움 문자 지정
	cout.width(10);
	cout.fill('_');
	cout << i << endl;
	cout.fill(' ');

	// 정렬 지정
	cout.width(20);
	cout << left << j << endl;
	cout.width(20);
	cout << right << j << endl;
	cout.width(20);
	cout << internal << j << endl;
}