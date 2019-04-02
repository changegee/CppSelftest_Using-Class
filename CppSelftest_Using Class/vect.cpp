#include "vect.h"
using namespace VECTOR;
using namespace std;

void VECTOR::Vector::set_mag()
{
	mag = sqrt(x * x + y * y);
}

void VECTOR::Vector::set_ang()
{
	if (x == 0.0 && y == 0.0)
		ang = 0.0;
	else
		ang = atan2(y, x);
}

void VECTOR::Vector::set_x()
{
	x = mag * cos(ang);
}

void VECTOR::Vector::set_y()
{
	y = mag * sin(ang);
}

VECTOR::Vector::Vector()
{
	x = y = mag = ang = 0;
}

VECTOR::Vector::Vector(double n1, double n2, Mode form)
{
	mode = form;
	if (form == RECT)
	{
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	} 
	else
	{
		mag = n1;
		ang = n2;
		set_x();
		set_y();
	}
}

void VECTOR::Vector::reset(double n1, double n2, Mode form)
{
	mode = form;
	if (form == RECT)
	{
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	}
	else
	{
		mag = n1;
		ang = n2;
		set_x();
		set_y();
	}
}

VECTOR::Vector::~Vector()
{
	x = y = mag = ang = 0;
	mode = RECT;
}

void VECTOR::Vector::polar_mode()
{
	mode = POL;
}

void VECTOR::Vector::rect_mode()
{
	mode = RECT;
}

Vector VECTOR::Vector::operator+(const Vector& b) const
{
	return Vector(x + b.x, y + b.y);
}

Vector VECTOR::Vector::operator-(const Vector& b) const
{
	return Vector(x - b.x, y - b.y);
}

Vector VECTOR::Vector::operator-() const
{
	return Vector(-x,-y);
}

Vector VECTOR::Vector::operator*(double n) const
{
	return Vector(x * n, y * n);
}

Vector VECTOR::operator*(double n, const Vector& a)
{
	return a * n;;
}

std::ostream& VECTOR::operator<<(std::ostream& os, const Vector& v)
{
	if (v.mode == VECTOR::Vector::Mode::RECT)
	{
		os << "(x,y) = (" << v.x << ", " << v.y << ")" << endl;
	}
	else
	{
		os << "(m,a) = (" << v.mag << ", " << v.y << ")" << endl;
	}
	return os;
	// TODO: 在此处插入 return 语句
}
