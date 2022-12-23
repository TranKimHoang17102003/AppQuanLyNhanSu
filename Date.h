#pragma once
#include <iostream>
#include <string>
#include<ctime>
#include<iomanip>
#include <cstdlib>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

class Date
{
protected:
	int day, month, year;
public:
	Date(int day = 1, int month = 1, int year = 1900);
	int getD() const { return day; }
	int getM() const { return month; }
	int getY() const { return year; }

	int endDayOfMonth();

	~Date(void);
	friend bool operator>(const Date& d1, const Date& d2);
	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
	friend ostream& operator<<(ostream& out, const Date d);
	friend istream& operator>>(istream& in, Date& d);
	Date operator++(); //tien to???
	Date operator++(int a); //hau to
};

