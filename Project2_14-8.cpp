#include "Project2_14-8.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	Date date1(06, 07, 2000);
	Date date2(9, 30, 2000);
	Date date3(02, 13, 2001);
	Date date4(12, 31, 1999);
	Date date5(01, 01, 2000);
	Date date6(12, 02, 2017);

	cout << "Printing dates using overloaded << operator...\n";
	cout << "Date 1: " << date1 << endl;
	cout << "Date 2: " << date2 << endl;
	cout << "Date 3: " << date3 << endl;
	cout << "Date 4: " << date4 << endl;
	cout << "Date 5: " << date5 << endl;

	cout << "\nCounting days between...\n";
	cout << date1 << " and " << date3 << ": " << date1 - date3 << " day(s)\n";
	cout << date4 << " and " << date5 << ": " << date4 - date5 << " day(s)\n";
	cout << date1 << " and " << date2 << ": " << date1 - date2 << " days(s)\n";

	cout << "\nIncrementing Dates...\n";
	cout << date1;
	++date1;
	cout << " after pre increment: \n" << date1 << endl;
	cout << date2;
	date2++;
	cout << " after post increment: \n" << date2 << endl;
	cout << date4;
	date4++;
	cout << " after post increment: \n" << date4 << endl;

	cout << "\nDecrementing Dates...\n";
	cout << date1;
	--date1;
	cout << " after pre decrement: \n" << date1 << endl;
	cout << date2;
	date2--;
	cout << " after post decrement: \n" << date2 << endl;
	cout << date5;
	--date5;
	cout << " after pre decrement: \n" << date5 << endl;

	cout << "\nReading Date 5 using overloaded >> operator...\n";
	cin >> date6;
	cout << "Date 5 printed using << operator is: " << date6;

	return 0;
}