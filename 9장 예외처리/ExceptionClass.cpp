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
				puts("�޸𸮰� �����մϴ�.");
				break;
			case 2:
				puts("���� ������ �ʰ��߽��ϴ�.");
				break;
			case 3:
				puts("�ϵ� ��ũ�� ���� á���ϴ�.");
				break;
			}
		}
	};
	void calc() {
		try
		{
			if (true/*���� �߻�*/) throw Exception(1);
		}
		catch (Exception &e)
		{
			printf("���� �ڵ� = %d => ", e.GetErrorCode());
			e.ReportError();
		}
	}
	void calc2() throw(Exception) {
		if (true/*���� �߻�*/) throw Exception(2);
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
		printf("���� �ڵ� = %d => ", e.GetErrorCode());
		e.ReportError();
	}
}
