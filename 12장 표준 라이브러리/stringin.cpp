#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, addr;

	cout << "이름을 입력하시오 : ";
	cin >> name;
	cout << "입력한 이름은 " << name << "입니다." << endl;
	cin.ignore();
	cout << "주소를 입력하시오 : ";
	getline(cin, addr);
	cout << "입력한 주소는 " << addr << "입니다." << endl;
}