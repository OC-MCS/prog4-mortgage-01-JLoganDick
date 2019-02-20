#include <iostream>
#include "Mortgage.h"
// implementation file for Mortgage class

//default constructor
Mortgage::Mortgage() {
	loan = 0;
	rate = 0;
	term = 0;
	years = 0;
}

//constructor for user input
Mortgage::Mortgage(float Loan, float Rate, int Years) {
	loan = Loan;
	rate = Rate;
	years = Years;
	calcTerm();
}

//===============================================================
// Function: Mortgage::calcTerm
// Function purpose: calculates the Term of the loan
// parameters: N/A
// returns: N/A
//===============================================================
void Mortgage::calcTerm() {
	float t = pow((1 + (rate / 12)), (12 * years));
	term = t;
}

//===============================================================
// Function: Mortgage::calcPayment
// Function purpose: calculates the monthly payment on the loan
// parameters: N/A
// returns: N/A
//===============================================================
void Mortgage::calcPayment() {
	payment = (loan * (rate / 12) * term) / (term - 1);
}

//===============================================================
// Function: Mortgage::calcTotalPaid
// Function purpose: calculates the total that will be paid on the loan
// parameters: N/A
// returns: N/A
//===============================================================
void Mortgage::calcTotalPaid() {
	totalPaid = payment * years * 12;
}

//===============================================================
// Function: Mortgage::returnTotalPaid
// Function purpose: returns total paid
// parameters: N/A
// returns: totalPaid
//===============================================================
float Mortgage::returnTotalPaid() {
	return totalPaid;
}

//===============================================================
// Function: Mortgage::returnPayment
// Function purpose: returns the monthly payment
// parameters: N/A
// returns: payment
//===============================================================
float Mortgage::returnPayment() {
	return payment;
}
