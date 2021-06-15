#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("korea");
	size_t len;

	len = s.size();
	for (int i = 0; i < len; i++)
	{
		cout << s[i];
	}
	cout << endl;
	s[0] = 'c';

	for (int i = 0; i < len; i++)
	{
		cout << s.at(i);
	}
	cout << endl;
}