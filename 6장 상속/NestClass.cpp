#include <stdio.h>
#include <string.h>

class Product
{
private:
	char name[64];
	char company[32];
	int price;

	class Date
	{
	protected:
		int year, month, day;
	public:
		Date(int y, int m, int d) { year = y; month = m; day = d; }
		void OutDate() { printf("%d/%d/%d", year, month, day); }
	};
	Date validto;
public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :
		validto(y, m, d) {
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct(){
		printf("�̸�:%s\n", name);
		printf("������:%s\n", company);
		printf("��ȿ�Ⱓ:");
		validto.OutDate();
		puts("");
		printf("����:%d\n", price);
	}
};

int main()
{
	Product shrimp("�����", "���", 2020, 8, 15, 900);
	shrimp.OutProduct();

	//Date now(12,34,56); // ����
}