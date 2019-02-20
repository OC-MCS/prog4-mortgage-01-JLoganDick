//===================================================== 
// Logan Dick
// 02/20/19 
// Programming II Assignment #4 
// Description: Mortgage
//=====================================================


#include <iostream>
#include <string>
#include "Mortgage.h"
using namespace std;

// main goes here. Code that *uses* the Mortgage class
// goes in this file

bool parseInt(string sval, int& val);
bool parseFloat(string sval, float& val);

int main(){
	float loanTotal, loanRate, payment, totalPaid;
	int loanYears;
	string input;
	do {
		cout << " enter the loan ammount " << endl << " must be positive " << endl;
		getline(cin, input);
	} while (!parseFloat(input, loanTotal) || loanTotal <= 0);
	do {
		cout << " enter the loan years " << endl << " must be positive " << endl;
		getline(cin, input);
	} while (!parseInt(input, loanYears) || loanYears <= 0);
	do {
		cout << " enter the loan rate " << endl << " must be positive and decimal form (ex. 5% entered as .05 ) " << endl;
		getline(cin, input);
	} while (!parseFloat(input, loanRate) || loanRate <= 0);

	Mortgage mortgage(loanTotal, loanRate, loanYears);
	mortgage.calcTerm();
	mortgage.calcPayment();
	mortgage.calcTotalPaid();
	payment = mortgage.returnPayment();
	totalPaid = mortgage.returnTotalPaid();

	cout << "The monthly payment is:                      " << payment << endl;
	cout << "The total paid over the life of the lonan:   " << totalPaid << endl;


	return 0;
}

//===============================================================
// Function: parseFloat
// Function purpose: prevents pathalogical input from user
// parameters: String entered, float value of string
// returns: bool of whether parse succeded.
//===============================================================
bool parseFloat(string sval, float& val)
{
	float num;
	bool success = true;
	try
	{
		num = stof(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

//===============================================================
// Function: ParseInt
// Function purpose: prevents pathalogical input from user
// parameters: String entered, float value of string
// returns: bool of whether parse succeded.
//===============================================================
bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}
