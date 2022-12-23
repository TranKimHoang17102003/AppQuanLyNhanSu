#include "Date.h"

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date(void)
{
}

bool operator>(const Date& d1, const Date& d2)
{
	if (d1.year < d2.year)
		return false;
	else if (d1.year == d2.year)
	{
		if (d1.month < d2.month)
			return false;
		else if (d1.month == d2.month)
		{
			if (d1.day <= d2.day)
				return false;
		}
	}
	return true;
}

bool operator==(const Date& d1, const Date& d2)
{
	return (d1.day == d2.day &&
		d1.month == d2.month && d1.year == d2.year);
}

bool operator<(const Date& d1, const Date& d2)
{
	return !((d1 == d2) || (d1 > d2));
}

ostream& operator<<(ostream& out, const Date d)
{
	string s = to_string(d.day) + "/" + to_string(d.month) + "/" + to_string(d.year);
	out << s;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "Day: ";
	in >> d.day;
	cout << "Month: ";
	in >> d.month;
	cout << "Year: ";
	in >> d.year;
	return in;
}

int Date::endDayOfMonth()
{
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
		else
			return 28;
	}
}

Date Date::operator++()
{
	if (day == endDayOfMonth())
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
		}
		else
			month++;
	}
	else
		day++;
	return (*this);
}

Date Date::operator++(int a)
{
	Date old = *this;
	++(*this);
	return old;
}