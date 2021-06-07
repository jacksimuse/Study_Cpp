#include <stdio.h>

class Shape
{
public:
	virtual void draw() = 0;
};

class Line : public Shape
{
public:
	virtual void draw() { puts("���� �߽��ϴ�."); }
};

class Circle : public Shape
{
public:
	virtual void draw() { puts("���׶�� �׷ȴ� ġ��."); }
};

class Rect : public Shape
{
public:
	virtual void draw() { puts("��� �簢���Դϴ�."); }
};

int main()
{
	Shape* pS[3];

	//Shape s;
	pS[0] = new Line;
	pS[1] = new Circle;
	pS[2] = new Rect;

	for (int i = 0; i < 3; i++)
	{
		pS[i]->draw();
	}

	for (int i = 0; i < 3; i++)
	{
		delete pS[i];
	}
}