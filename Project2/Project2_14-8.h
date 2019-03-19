// Project 2: Chapter 14 #8 - Date Class Modification
/* Modify the Date class in Programming Challenge 1 of Chapter 13 to have overloaded operators.
Demonstrate the class’s capabilities in a simple program. */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Date
{
	private: 
		int month, day, year;
		static string monthNames[12];
		static int numberOfDays[12];
	public:
		Date(int mes, int dia, int ano)
		{
			month = mes;
			day = dia;
			year = ano;
		}

		int getMonth() const { return month; }
		int getDay() const { return day; }
		int getYear() const { return year; }
		void setMonth(int mes) { month = mes; }
		void setDay(int dia) { day = dia; }
		void setYear(int ano) { year = ano; }

		// ++ Prefix and postfix increment operators. These operators should increment the object's day member. 
		/*	• When a date is set to the last day of the month and incremented, it should become
			the first day of the following month. 
			• When a date is set to December 31 and incremented, it should become January 1 of
			the following year. */
		Date operator ++ () 
		{
			if (day == numberOfDays[month - 1]) 
			{
				day = 1;
				if (month == 12) 
				{
					month = 1;
					++year;
				}
				else
					++month;
			}
			else
				++day;

			return *this;
		}
		Date operator ++ (int)
		{
			day++;

			if (numberOfDays[month - 1] == 31 && day == 32)
			{
				day = 1;
				month++;
				if (month == 13)
				{
					month = 1;
					year++;
				}
			}
			else if (month == 2 && day == 29)
			{
				day = 1;
				month = 3;
			}
			else if (numberOfDays[month - 1] == 30 && day == 31)
			{
				day = 1;
				month++;
			}

			return *this;
		}
		// -- Prefix and postfix decrement operators. These operators should decrement the object's day member.
		/* 	• When a day is set to the first day of the month and decremented, it should become
			the last day of the previous month.
			• When a date is set to January 1 and decremented, it should become December 31 of
			the previous year. */
		Date operator -- () 
		{
			if (day == 1) 
			{
				if (month == 1) 
				{
					month = 12;
					day = 31;
					--year;
				}
				else 
				{
					--month;
					day = numberOfDays[month - 1];
				}
			} 
			else 
				--day;
			
			return *this;
		}
		Date operator -- (int)
		{
			day--;

			if (day == 0)
			{
				month--;
				day = numberOfDays[month - 1];
				if (month == 0)
				{
					month = 12;
					day = 31;
					year--;
				}
			}

			return *this;
		}
		// - Subtraction operator. 
		/* If one Date object is subtracted from another, the operator should give the number of days between 
		the two dates. For example, if April 10, 2014 is subtracted from April 18, 2014, the result will be 8. */
		int operator - (const Date &date2)
		{
			int day2 = date2.getDay(),
				month2 = date2.getMonth(),
				year2 = date2.getYear();

			if (year2 != year)
			{
				int totalDays1 = 0, totalDays2 = 0;
				for (int i = 0; i < (month - 1); i++)
					totalDays1 += numberOfDays[i];
				totalDays1 += day;
				for (int j = 0; j < (month2 - 1); j++)
					totalDays2 += numberOfDays[j];
				totalDays2 += day2;
				return abs(totalDays2 - (365 - totalDays1)) + abs(year2 - year - 1) * 365;
			}
			else if (year == year2)
			{
				int tDays1 = 0, tDays2 = 0;
				for (int i = 0; i < (month - 1); i++)
					tDays1 += numberOfDays[i];
				tDays1 += day;
				for (int j = 0; j < (month2 - 1); j++)
					tDays2 += numberOfDays[j];
				tDays2 += day2;

				return abs(tDays2 - tDays1);
			}
		}
		// << cout ’s stream insertion operator.
		friend ostream& operator << (ostream& strm, const Date& date)
		{
			strm << monthNames[(date.month) - 1] << " " << date.day << ", " << date.year;
			return strm;
		}
		// >> cin ’s stream extraction operator. 
		/* This operator should prompt the user for a date to be stored in a Date object.
		Input Validation: The overloaded >> operator should not accept invalid dates. */
		friend istream &operator >> (istream &strm, Date &date) 
		{
			cout << "Month: ";
			strm >> date.month;
			if (date.month < 1 || date.month > 12)
			{
				do {
					cout << "Invalid month! Enter again.\n";
					cout << "Month: ";
					strm >> date.month;
				} while (date.month < 1 || date.month > 12);
			}
			cout << "Day: ";
			strm >> date.day;
			if (numberOfDays[date.month - 1] == 28 && (date.day < 1 || date.day > 28))
			{
				do {
					cout << "Invalid day! Enter again.\n";
					cout << "Day: ";
					strm >> date.day;
				} while (date.day < 1 || date.day > 28);
			}
			else if (numberOfDays[date.month - 1] == 30 && (date.day < 1 || date.day > 30))
			{
				do {
					cout << "Invalid day! Enter again.\n";
					cout << "Day: ";
					strm >> date.day;
				} while (date.day < 1 || date.day > 30);
			}
			else if (numberOfDays[date.month - 1] == 31 && (date.day < 1 || date.day > 31))
			{
				do {
					cout << "Invalid day! Enter again.\n";
					cout << "Day: ";
					strm >> date.day;
				} while (date.day < 1 || date.day > 31);
			}
			cout << "Year: ";
			strm >> date.year;
			if (date.year < 1)
			{
				do {
					cout << "Invalid year! Enter again.\n";
					cout << "Year: ";
					strm >> date.year;
				} while (date.year < 1);
			}

			return strm;
		}
};

string Date::monthNames[12] = { "January", "February", "March", "April", "May", "June",
								"July", "August", "September", "October", "November", "December" };
int Date::numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };