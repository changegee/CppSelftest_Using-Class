#include "Time.h"
#include <iostream>
using namespace std;
//1. 修改程序清单11.15， 使之将一系列连续的随机漫步者位置写入文件中。对于每个位置，用步号进行标示。
//另外，让该程序将初始条件（目标距离和步长）以结果小结写入到该文件中。该文件的内容与下面类似：
//Target Distance : 100, Step Size : 20
//0 : (x, y) = (0, 0)
//1 : (x, y) = (-11.4715, 16.383)
//2 : (x, y) = (-8.68807, -3.42232)
//...
//26 : (x, y) = (42.2919, -78.2594)
//27 : (x, y) = (58.6749, -89.7309)
//After 27 steps, the subject has the following location :
//(x, y) = (58.6749, -89.7309)
//or
//(m, a) = (107.212, -56.8194)
//Average outward distance per step = 3.97081

Time::Time()
{
	m_hour = 0;
	m_minutes = 0;
}

Time::Time(int h, int m)
{
	m_hour = h;
	m_hour = m;
}

void Time::AddMin(int m)
{
	m_minutes += m;
	m_hour += m / 60;
	m_minutes %= 60;
}

void Time::AddHr(int h)
{
	m_hour += h;
}

void Time::Reset(int h, int m)
{
	m_hour = h;
	m_minutes = m;
}

Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.m_minutes = m_minutes + t.m_minutes;
	sum.m_hour = m_hour + t.m_hour + sum.m_minutes / 60;
	sum.m_minutes %= 60;
	return Time();
}

void Time::Show() const
{
	cout << "\nHour :" << m_hour << endl;
	cout << "\nMinutes :" << m_minutes << endl;
}
