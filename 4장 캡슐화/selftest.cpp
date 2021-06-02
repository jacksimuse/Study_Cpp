#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Human
{
private:
	char name[12];
	int age;

public:
	void SetName(char *aname) {
		
		for (int i = 0; i < strlen(aname); i++)
		{
			if (i < 12)	name[i] = aname[i];
			else name[i] = '\0';
		}
	}
	void getName() { printf("%s\n", name); }
	void SetAge(int age) {
		if (age > 0 && age < 120)
			this->age = age;
		else this->age = 0;
	}
	void getAge() { printf("%d\n", age); }
};

int main()
{
	Human i;
	char tempName[100];
	int tempAge;
	printf("이름을 입력하세요 : ");
	cin >> tempName >> tempAge;
	i.SetName(tempName);
	i.SetAge(tempAge);

	i.getName();
	i.getAge();
	return 0;

}