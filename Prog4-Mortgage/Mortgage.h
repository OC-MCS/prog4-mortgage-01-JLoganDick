#pragma once
// header file for Mortgage class
class Mortgage
{
private:
	float loan;
	float rate;
	float term;
	float payment;
	float totalPaid;
	int years;
public:
	Mortgage();
	Mortgage(float Loan, float rate, int years);
	void calcTerm();
	void calcPayment();
	void calcTotalPaid();
	float returnPayment();
	float returnTotalPaid();
};
