#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = t;
}

class Human
{
private:
	char* name;
	int age;

public:
	Human() {
		name = new char[1];
		name[0] = NULL;
		age = 0;
	}
	Human(const char* aname, int aage) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
	}

	Human(const Human& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}

	Human& operator =(const Human& other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}

	~Human() {
		delete[] name;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human lee("이승만", 10);
	Human park("박정희", 20);
	lee.intro();
	park.intro();
	swap(lee, park);
	lee.intro();
	park.intro();
}

