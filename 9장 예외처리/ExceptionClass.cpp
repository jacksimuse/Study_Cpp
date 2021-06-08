#include <stdio.h>

class MyClass
{
public:
	class Exception
	{
	private:
		int ErrorCode;

	public:
		Exception(int ae) : ErrorCode(ae){}
		int GetErrorCode() { return ErrorCode; }
		void ReportError() {
			switch (ErrorCode)
			{
			case 1:
				puts("메모리가 부족합니다.");
				break;
			case 2:
				puts("연산 범위를 초과했습니다.");
				break;
			case 3:
				puts("하드 디스크가 가득 찼습니다.");
				break;
			}
		}
	};
	void calc() {
		try
		{
			if (true/*에러 발생*/) throw Exception(1);
		}
		catch (Exception &e)
		{
			printf("에러 코드 = %d => ", e.GetErrorCode());
			e.ReportError();
		}
	}
	void calc2() throw(Exception) {
		if (true/*에러 발생*/) throw Exception(2);
	}
};

int main()
{
	MyClass m;
	m.calc();
	try {
		m.calc2();
	}
	catch (MyClass::Exception& e) {
		printf("에러 코드 = %d => ", e.GetErrorCode());
		e.ReportError();
	}
}
