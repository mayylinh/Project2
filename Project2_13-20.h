// Project 2: Chapter 13 #20 - Patient Fees
/* Write a program that computes a patient’s bill for a hospital stay. */

#include <iostream>
#include <string>
using namespace std;

/* The PatientAccount class will keep a total of the patient’s charges. It will also
keep track of the number of days spent in the hospital. */
class PatientAccount 
{
	private:
		double totalCharges, dailyRate;
		int numDays;
	public:
		PatientAccount() 
		{
			totalCharges = 0.00;
			numDays = 0;
			dailyRate = 1500.00;
		}
		PatientAccount(int n) 
		{
			while (n < 0) 
			{
				cout << "Please enter a nonnegative number: ";
				cin >> n;
			}
			numDays = n;
			dailyRate = 1500.00;
			totalCharges = numDays * dailyRate;
		}
		double getTotalCharges() const 
		{
			return totalCharges;
		}
		int getNumberOfDays() const 
		{
			return numDays;
		}
		double getDailyRate() const 
		{
			return dailyRate;
		}
		void setNumberOfDays(int n) 
		{
			while (n < 0) 
			{
				cout << "Please enter a nonnegative number: ";
				cin >> n;
			}
			numDays = n;
			totalCharges += numDays * dailyRate;
		}
		void setDailyRate(double d) 
		{
			while (d < 0) 
			{
				cout << "Please enter a nonnegative number: ";
				cin >> d;
			}

			dailyRate = d;
			totalCharges += (dailyRate - 1500.00) * numDays;
		}
		void addToTotal(double a) 
		{
			totalCharges += a;
		}
};
/* The Surgery class will have stored within it the charges for at least five types
of surgery. It can update the charges variable of the PatientAccount class. */
class Surgery
{
	private:
		string types[5];
		double prices[5];
		PatientAccount *ptr;
	public:
		Surgery(PatientAccount &account)
		{
			string t;
			for (int i = 0; i < 5; i++)
			{
				t = "Type ";
				types[i] = t.append(to_string(i + 1));
			}
			double p = 1500.00;
			for (int i = 0; i < 5; i++)
			{
				prices[i] = p;
				p += 500.00;
			}
			ptr = &account;
		}
		void setTypeOnPosition(string s, int i)
		{
			types[i - 1] = s;
		}
		void setPriceOnPosition(double p, int i)
		{
			prices[i - 1] = p;
		}
		string getTypeOnPosition(int i) const
		{
			return types[i - 1];
		}
		double getPriceOnPosition(int i) const
		{
			return prices[i - 1];
		}
		void addCharges(int i) const
		{
			ptr->addToTotal(prices[i - 1]);
		}
};
/* The Pharmacy class will have stored within it the price of at least five types of
medication. It can update the charges variable of the PatientAccount class. */
class Pharmacy 
{
	private:
		string meds[5];
		double prices[5];
		PatientAccount *ptr;
	public:
		Pharmacy(PatientAccount &account) 
		{
			string m;
			for (int i = 0; i < 5; i++) 
			{
				m = "Medication ";
				meds[i] = m.append(to_string(i + 1));
			}
			double p = 15.00;
			for (int i = 0; i < 5; i++) 
			{
				prices[i] = p;
				p += 5.00;
			}
			ptr = &account;
		}
		void setMedOnPosition(string s, int i) 
		{
			meds[i - 1] = s;
		}
		void setPriceOnPosition(double p, int i) 
		{
			prices[i - 1] = p;
		}
		string getMedOnPosition(int i) const 
		{
			return meds[i - 1];
		}
		double getPriceOnPosition(int i) const 
		{
			return prices[i - 1];
		}
		void addCharges(int i) const 
		{
			ptr->addToTotal(prices[i - 1]);
		}
};