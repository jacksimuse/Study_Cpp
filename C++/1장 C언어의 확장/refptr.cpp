#include <stdio.h>
#include <malloc.h>
#include <string.h>
// 주석은 포인터 안쓰는 방법
void InputName(char **Name) // void InputName(char *&Name)
{
	*Name = (char *)malloc(32); // Name = (char *)malloc(32);
	strcpy(*Name, "kim sang hyung"); //strcpy(Name, "kim sang hyung");
}

int main() {
	char* Name;

	InputName(&Name); // InputName(Name)
	printf("이름은 %s입니다.\n", Name);
	free(Name);
}