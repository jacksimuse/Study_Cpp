#include <iostream>

/* ����ü(struct)�� �⺻������ public���� �Ǿ�����
class�� public ���� ����� ��밡��
*/

class Human {
public:
	char name[20];
	float height;
	float weight;
	int age;
	char blood;

	void view();
};
/* ::���� ������ 
class ���ο� �Լ��� ����� ���������� ������ ���� �ػ� Ŭ�����ȿ� ������ �˸��� ���� �����ڰ� �ʿ�
����� 'Ŭ������::'
*/
void Human:: view()
{
	printf("���� �̸��� %s �̰� Ű�� %.1f �̰� �����Դ� %.1f �̰� ���̴� %d �̰� �������� %c �̴�.", name, height, weight, age, blood);
}

int main()
{
	Human my = { "����", 180, 70, 20, 'A' };
	//printf("���� �̸��� %s �̰� Ű�� %.1f �̰� �����Դ� %.1f �̰� ���̴� %d �̰� �������� %c �̴�.", my.name, my.height, my.weight, my.age, my.blood);
	my.view();
	return 0;
}