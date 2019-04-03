// mytime3.cpp  -- implementing Time methods
#include "mytime3.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

//Time Time::operator+(const Time& t) const
//{
//	Time sum;
//	sum.minutes = minutes + t.minutes;
//	sum.hours = hours + t.hours + sum.minutes / 60;
//	sum.minutes %= 60;
//	return sum;
//}
//
//Time Time::operator-(const Time& t) const
//{
//	Time diff;
//	int tot1, tot2;
//	tot1 = t.minutes + 60 * t.hours;
//	tot2 = minutes + 60 * hours;
//	diff.minutes = (tot2 - tot1) % 60;
//	diff.hours = (tot2 - tot1) / 60;
//	return diff;
//}
//
//Time Time::operator*(double mult) const
//{
//	Time result;
//	long totalminutes = hours * mult * 60 + minutes * mult;
//	result.hours = totalminutes / 60;
//	result.minutes = totalminutes % 60;
//	return result;
//}
//
//std::ostream& operator<<(std::ostream & os, const Time & t)
//{
//	os << t.hours << " hours, " << t.minutes << " minutes";
//	return os;
//}

Time operator+(const Time& t1, const Time& t2)
{
	Time tmp;
	tmp.minutes = t1.minutes + t2.minutes;
	tmp.hours = t1.hours + t2.hours + tmp.minutes / 60;
	tmp.minutes %= 60;
	return tmp;
}

Time operator-(const Time& t1, const Time& t2)
{
	Time tmp;
	tmp.minutes = t1.minutes - t2.minutes;
	tmp.hours = t1.hours - t2.hours;
	if (tmp.minutes<0)
	{
		tmp.hours--;
		tmp.minutes += 60;
	}
	return Time();
}

Time operator*(const Time& t1, double n)
{
	Time tmp;
	tmp.minutes = t1.minutes * n;
	tmp.hours = t1.hours * n + tmp.minutes / 60;
	tmp.minutes %= 60;
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	using namespace std;
	os << "\nHour :" << t.hours << "\nMinutes :" << t.minutes << endl;
	return os;
	// TODO: 在此处插入 return 语句
}
