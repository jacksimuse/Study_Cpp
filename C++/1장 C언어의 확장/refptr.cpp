#include <stdio.h>
#include <malloc.h>
#include <string.h>
// �ּ��� ������ �Ⱦ��� ���
void InputName(char **Name) // void InputName(char *&Name)
{
	*Name = (char *)malloc(32); // Name = (char *)malloc(32);
	strcpy(*Name, "kim sang hyung"); //strcpy(Name, "kim sang hyung");
}

int main() {
	char* Name;

	InputName(&Name); // InputName(Name)
	printf("�̸��� %s�Դϴ�.\n", Name);
	free(Name);
}