#include <ostream>
#pragma once

//5. ���±�дStonewt�ࣨ�����嵥11.16 �ͳ����嵥11.17 ����ʹ����һ��״̬��Ա��
//�ɸó�Ա���ƶ���Ӧת��ΪӢʯ��ʽ����������ʽ������Ĳ����ʣ�Ӧ���ǰ�����ʽ�����Ǹ������ʽ������stone, ����pounds����
//���� << �������ʹ�����滻show_stn()��show_lbs()������
//���ؼӷ��������ͳ˷���������Ա���Զ�Stonewt���мӡ����������㡣
//��дһ��ʹ�������෽������Ԫ��С���������������


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
