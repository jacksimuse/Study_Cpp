#include <stdio.h>
#include <string.h>

class Human
{
private:
	char *name;
	int age;

public:
	Human() {}
	Human(const char *pname, int old) { 
		name = new char[strlen(pname)+ 1];
		strcpy(name, pname); 
		age = old; }
	~Human() {
		printf("객체가 파괴되었습니다.\n");
		delete[] name;
	}
	void OutHuman() {
		printf("이름은 %s, 나이는 %d입니다.\n", this->name, this->age);
	}
	Human(const Human& rfs) {
		name = new char[strlen(rfs.name) + 1];
		strcpy(name, rfs.name);
		age = rfs.age;
	}
	const Human& operator=(const Human& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->age = other.age;
		return *this;
	}

};

int main()
{
	Human ch1("재훈", 20);
	ch1.OutHuman();
	Human ch2(ch1);
	ch2.OutHuman();
	Human xman;
	xman = ch1;
	xman.OutHuman();
}