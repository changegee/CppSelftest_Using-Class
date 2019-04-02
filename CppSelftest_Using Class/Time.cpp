#include "Time.h"
#include <iostream>
using namespace std;
//1. �޸ĳ����嵥11.15�� ʹ֮��һϵ�����������������λ��д���ļ��С�����ÿ��λ�ã��ò��Ž��б�ʾ��
//���⣬�øó��򽫳�ʼ������Ŀ�����Ͳ������Խ��С��д�뵽���ļ��С����ļ����������������ƣ�
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
