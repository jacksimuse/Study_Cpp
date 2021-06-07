#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "cursor.h"

class Point
{
protected:
	int x, y;
	char ch;

public:
	Point(int ax, int ay, char ach) { x = ax; y = ay; ch = ach; }
	void show() {
		gotoxy(x, y); putch(ch);
	}
	void hide() {
		gotoxy(x, y); putch(' ');
	}
	void move(int nx, int ny) {
		hide();
		x = nx;
		y = ny;
		show();
	}
};

class Circle : public Point
{
protected:
	int radius;

public:
	Circle(int ax, int ay, char ach, int arad) : Point(ax, ay, ach) { radius = arad; }
	void show() {
		for (double a = 0; a < 360; a += 10) {
			gotoxy(int(x + sin(a * 3.14 / 180) * radius), int(y - cos(a * 3.14 / 180) * radius / 2));
			putch(ch);
		}
	}
	void hide() {
		for (double a = 0; a < 360; a += 10) {
			gotoxy(int(x + sin(a * 3.14 / 180) * radius), int(y - cos(a * 3.14 / 180) * radius / 2));
			putch(' ');
		}
	}
};

int main()
{
	Point p(1, 1, 'P');
	Circle c(20, 10, 'C', 12);

	p.show();
	c.show();

	getch();
	p.move(40, 1);
	getch();
	c.move(40, 10);
	getch();
}