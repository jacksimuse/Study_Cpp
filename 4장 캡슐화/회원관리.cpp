#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class CMember
{
private:
	static int cnt;
	
public:
	char name[50];
	char* pname;
	int phone;
	char address[100];
	char* paddress;
	CMember() { cnt++; }
	CMember(const char* aname, const char * aaddress, int number) { 
		pname = new char[strlen(aname) + 1];
		strcpy(this->pname, aname);
		paddress = new char[strlen(aaddress) + 1];
		strcpy(this->paddress, aaddress);
		phone = number;
		cnt++; 
		cout << "-------------------------------------" << endl;
		cout << "ȸ�� ��ȣ : " << cnt << endl;
		cout << "ȸ�� �̸� : " << this->pname << " / ȸ�� �ּ� : " << this->paddress << " / ȸ�� ��ȭ��ȣ : " << this->phone << endl
			<< "-------------------------------------" << endl;
	}
	~CMember() { cnt--; }
	void getData();
	void setData(const char*, const char*, const int);
};
void CMember::setData(const char * pname, const char* paddress, const int number)
{
	strcpy(this->name, pname);
	strcpy(this->address, paddress);
	this->phone = number;
}
void CMember::getData()
{
	cout << "-------------------------------------" << endl;
	cout << "ȸ�� ��ȣ : " << cnt << endl;
	cout << "ȸ�� �̸� : " << this->name << " / ȸ�� �ּ� : " << this->address << " / ȸ�� ��ȭ��ȣ : " << this->phone << endl
		 << "-------------------------------------" << endl;
}
int CMember::cnt = 0;

int main()
{
	CMember m1;
	m1.setData("����", "�λ곲��", 0101234567);
	m1.getData();
	CMember *m2;
	m2 = new CMember;
	m2->setData("����", "�λ�����", 01054646513);
	m2->getData();
	CMember m3;
	m3.setData("����", "��õ��", 7846546);
	delete m2;
	cout << "ȸ�� Ż�� ��ȣ�� �� ������ϴ� " << endl;
	m3.getData();
	CMember* m4;
	m4 = new CMember("�Թ�", "�ؿ��", 456132);
	delete m4;
	
}
