#include "cursor.h"
#include <iostream>
using namespace std;

template <typename T>
class PosValue
{
private:
	int x, y;
	T value;
public:
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) {}
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();

}