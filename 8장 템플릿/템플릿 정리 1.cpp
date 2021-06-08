/* 함수 템플릿 */
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
template <> // 특수화
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;
	char* str = new char[len];
	strcpy_s(str, llen + 1, lstr);
	strcat_s(str, len, rstr);
	
	return str;
}
int main()
{
	/*cout << Add(10, 20) << endl;
	cout << Add(3.14, 4.5) << endl;*/
	int res = Add<int>(3, 4);
	cout << res << endl;
	const char* sres = Add<const char*>("Hello", "IoT");
	cout << sres << endl;

	return 0;
}