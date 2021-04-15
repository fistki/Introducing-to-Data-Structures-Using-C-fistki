#include <cstdio>
class Point {
public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	~Point() {}
	Point(const Point& rhs): xpos(rhs.xpos), ypos(rhs.ypos) {}

	
	Point& operator=(const Point& rhs)
	{
		xpos = rhs.xpos;
		ypos = rhs.ypos;
		return *this;
	}
	void SetPointPos(int x, int y);
	bool operator==(const Point& rhs) const;
	int getx(void);
	int gety(void);

private:
	int xpos;
	int ypos;
};

int Point::getx(void) { return xpos; }
int Point::gety(void) { return ypos; }


bool Point::operator==(const Point& rhs) const
{
	if (xpos == rhs.xpos && ypos == rhs.ypos) return true;
	else return false;
}

void Point::SetPointPos(int x, int y)
{
	xpos = x;
	ypos = y;
}

void ShowPointPos(Point& p)
{
	printf("[%d, %d]\n", p.getx(), p.gety());
}
