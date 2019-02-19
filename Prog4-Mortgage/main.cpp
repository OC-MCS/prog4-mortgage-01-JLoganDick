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
		cout << "enter the loan ammount" << endl;
		getline(cin, input);
	} while (!parseFloat(input, loanTotal) || loanTotal <= 0);
	do {
		cout << "enter the loan years" << endl;
		getline(cin, input);
	} while (!parseInt(input, loanYears) || loanYears <= 0);
	do {
		cout << "enter the loan rate" << endl;
		getline(cin, input);
	} while (!parseFloat(input, loanRate) || loanRate <= 0);

	Mortgage mortgage(loanTotal, loanRate, loanYears);
	mortgage.calcTerm();
	mortgage.calcPayment();
	mortgage.calcTotalPaid();
	payment = mortgage.returnPayment();
	totalPaid = mortgage.returnTotalPaid();

	cout << payment << endl;
	cout << totalPaid << endl;


	return 0;
}

bool parseFloat(string sval, float& val)
{
	float num;
	bool success = true;
	try
	{
		num = stof(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}
