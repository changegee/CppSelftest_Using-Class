#include <ostream>
#pragma once

//5. 重新编写Stonewt类（程序清单11.16 和程序清单11.17 ），使它有一个状态成员，
//由该成员控制对象应转换为英石格式、整数磅格式（翻译的不合适，应该是磅数格式）还是浮点磅格式（多少stone, 多少pounds）。
//重载 << 运算符，使它来替换show_stn()和show_lbs()方法。
//重载加法、减法和乘法运算符，以便可以对Stonewt进行加、减、乘运算。
//编写一个使用所有类方法和友元的小程序，来测试这个类


#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };      // pounds per stone
	enum Mode
	{
		STN,PLT,POD
	};
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
public:
	Stonewt(double lbs);          // constructor for double pounds
	Stonewt(int stn, double lbs); // constructor for stone, lbs
	Stonewt();                    // default constructor
	~Stonewt();

	Stonewt operator+(Stonewt& sw)const;
	Stonewt operator-(Stonewt& sw)const;
	Stonewt operator*(const double n)const;

	friend std::ostream& operator<<(std::ostream os,Stonewt& sw);

};
#endif
