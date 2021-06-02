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
		cout << "회원 번호 : " << cnt << endl;
		cout << "회원 이름 : " << this->pname << " / 회원 주소 : " << this->paddress << " / 회원 전화번호 : " << this->phone << endl
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
	cout << "회원 번호 : " << cnt << endl;
	cout << "회원 이름 : " << this->name << " / 회원 주소 : " << this->address << " / 회원 전화번호 : " << this->phone << endl
		 << "-------------------------------------" << endl;
}
int CMember::cnt = 0;

int main()
{
	CMember m1;
	m1.setData("재훈", "부산남구", 0101234567);
	m1.getData();
	CMember *m2;
	m2 = new CMember;
	m2->setData("동훈", "부산진구", 01054646513);
	m2->getData();
	CMember m3;
	m3.setData("성주", "남천동", 7846546);
	delete m2;
	cout << "회원 탈퇴 번호가 앞 당겨집니다 " << endl;
	m3.getData();
	CMember* m4;
	m4 = new CMember("규민", "해운대", 456132);
	delete m4;
	
}
