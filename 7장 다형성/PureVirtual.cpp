#include <stdio.h>

class Shape
{
public:
	virtual void draw() = 0;
};

class Line : public Shape
{
public:
	virtual void draw() { puts("선을 긋습니다."); }
};

class Circle : public Shape
{
public:
	virtual void draw() { puts("동그라미 그렸다 치고."); }
};

class Rect : public Shape
{
public:
	virtual void draw() { puts("요건 사각형입니다."); }
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