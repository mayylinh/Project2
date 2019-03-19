#include "Project2_13-20.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* The main program will be a menu that allows the user to enter a type of surgery and 
a type of medication, and check the patient out of the hospital. When the patient 
checks out, the total charges should be displayed.  */
int main()
{
	cout << "Creating a PatientAccount object...\n";
	PatientAccount account;
	cout << "\nCreating Surgery object linked to this account...\n";
	Surgery surg(account);
	cout << "\nCreating Pharmacy object linked to this account...\n";
	Pharmacy pharm(account);
	cout << "Done!\n";

	int input;
	double rate;

	cout << fixed << setprecision(2);

	cout << "\nThe types of surgeries: \n";
	for (int i = 1; i <= 5; i++) {
		cout << "\t" << i << ". ";
		cout << surg.getTypeOnPosition(i);
		cout << "  ($" << surg.getPriceOnPosition(i);
		cout << ")\n";
	}

	cout << "Enter your choice: ";
	cin >> input;

	while (input < 1 || input > 5) 
	{
		cout << "Please enter a number between";
		cout << " 1 and 5: ";
		cin >> input;
	}
	
	surg.addCharges(input);

	cout << "\nThe types of medication: \n";
	for (int i = 1; i <= 5; i++) {
		cout << "\t" << i << ". ";
		cout << pharm.getMedOnPosition(i);
		cout << "  ($" << pharm.getPriceOnPosition(i);
		cout << ")\n";
	}

	cout << "Enter your choice: ";
	cin >> input;

	while (input < 1 || input > 5) 
	{
		cout << "Please enter a number between";
		cout << " 1 and 5: ";
		cin >> input;
	}

	pharm.addCharges(input);

	cout << "\nEnter number of nights that the";
	cout << " patient stayed in the hospital: ";
	cin >> input;

	account.setNumberOfDays(input);

	cout << "\nEnter the hospital's daily rate: ";
	cin >> rate;

	account.setDailyRate(rate);

	cout << "Patient's total charges are: $";
	cout << account.getTotalCharges();

	return 0;
}