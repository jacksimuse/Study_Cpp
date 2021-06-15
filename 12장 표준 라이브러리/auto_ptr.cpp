#include <iostream>
#include <memory>
using namespace std;

int main()
{
	auto_ptr<double> rate(new double);

	*rate = 3.1415;
	cout << *rate << endl;
}