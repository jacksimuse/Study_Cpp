#include <stdio.h>

/* �Ӽ��� ���� ������ �ν��Ͻ� ����
�Լ��� �ν��Ͻ� ���� �ȵ�
��� �Լ��� ũ��� �ʿ���� ��� �Լ��� �����Ǿ�����

�����ɶ� ���� �Լ��� ȣ���ϴ��� �˾ƾߵǴµ� this�����Ͱ� �����Ǿ� �ڱⰡ �θ��ٴ°� �˷��ش���
*/
class Human
{
public:
	char name[12];
	int age;

	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = {
		{ "������", 49},
		{ "������", 49},
		{ "�ڻ�", 49}
	};

	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();
}