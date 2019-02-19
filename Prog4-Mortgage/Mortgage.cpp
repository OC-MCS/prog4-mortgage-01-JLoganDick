#include <iostream>
#include "Mortgage.h"
// implementation file for Mortgage class

Mortgage::Mortgage() {
	loan = 0;
	rate = 0;
	term = 0;
	years = 0;
}

Mortgage::Mortgage(float Loan, float Rate, int Years) {
	loan = Loan;
	rate = Rate;
	years = Years;
	calcTerm();
}

void Mortgage::calcTerm() {
	float t = pow((1 + (rate / 12)), (12 * years));
	term = t;
}

void Mortgage::calcPayment() {
	payment = (loan * (rate / 12) * term) / (term - 1);
}

void Mortgage::calcTotalPaid() {
	totalPaid = payment * years * 12;
}

float Mortgage::returnTotalPaid() {
	return totalPaid;
}

float Mortgage::returnPayment() {
	return payment;
}
